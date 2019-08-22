#include "Core/Scene.hpp"

#include <iostream>

using namespace Color;
using namespace Graphics;
using namespace Illumination;
using namespace Math;
using namespace Object;

namespace Core {
  Scene::Scene(GenericImage image, const Camera& camera) : image_(std::move(image)), camera_(camera) {}

  void Scene::AddLight(GenericLight light) {
    lights_.push_back(std::move(light));
  }

  void Scene::AddShape(GenericShape shape) {
    shapes_.push_back(std::move(shape));
  }

  void Scene::Render(const std::string& filename, bool supersampling) {
    SortShapes();
    for (auto& pixel : *image_.get()) {
      pixel.color = Raytrace(pixel.position, supersampling);
    }
    image_->Export(filename);
  }

  void Scene::SetCameraPosition(const Math::Vector3D& position) {
    camera_.position = position;
  }

  void Scene::SetFieldOfView(double field_of_view) {
    field_of_view_ = field_of_view;
  }

  void Scene::SortShapes() {
    std::sort(shapes_.begin(), shapes_.end(), [this](const GenericShape& lhs, const GenericShape& rhs) {
      return lhs->DistanceFrom(camera_) > rhs->DistanceFrom(camera_);
    });
  }

  RGBColor Scene::Raytrace(const Graphics::PixelPosition& position, bool supersampling, unsigned depth) const {
    RGBColor color;
    if (supersampling) {
      std::vector<PixelOffset> sample_offsets{
        {0.25, 0.25}, {0.75, 0.25}, {0.5, 0.5}, {0.25, 0.75}, {0.75, 0.75}
      };
      for (const auto& offset : sample_offsets) {
        color += Trace(CreateRay(position, offset, image_->GetProperties(), camera_), depth) / 5;
      }
    } else {
      color = Trace(CreateRay(position, {0.5, 0.5}, image_->GetProperties(), camera_), depth);
    }
    return color;
  }

  RGBColor Scene::Trace(const Ray& ray, unsigned depth) const {
    RGBColor color;
    for (const auto& shape : shapes_) {
      RayHit hit;
      if (shape->Intersects(ray, hit)) {
        color = Shade(ray, hit, depth);
      }
    }
    return color;
  }

  RGBColor Scene::Shade(const Ray& ray, const RayHit& hit, unsigned depth) const {
    RGBColor radiance;
    if (depth <= 4) {
      for (const auto& light : lights_) {
        if (!InShadow(hit.intersection, light)) {
          radiance += light->Illumination(hit, camera_);
        }
      }
      if (hit.material.reflectivity > 0.0) {
        radiance += hit.material.reflectivity * Trace(Reflected(ray, hit), depth + 1);
      }
    }
    return radiance;
  }

  bool Scene::InShadow(const Vector3D& point, const GenericLight& light) const {
    const Ray shadow_ray = Shadow(point, light);
    RayHit hit;
    for (const GenericShape& shape : shapes_) {
      if (shape->Intersects(shadow_ray, hit)) {
        return true;
      }
    }
    return false;
  }

  Ray Scene::Shadow(const Vector3D& point, const GenericLight& light) const {
    const Vector3D direction_toward_light = Negated(light->Direction(point));
    return Ray{point + (0.01 * direction_toward_light), direction_toward_light};
  }

  Ray Scene::Reflected(const Ray& ray, const RayHit& hit) const {
    const Vector3D reflection_direciton = Normalized(ray.direction - hit.normal * 2.0 * Dot(ray.direction, hit.normal));
    return Ray{hit.intersection + (0.01 * reflection_direciton), reflection_direciton};
  }
}
