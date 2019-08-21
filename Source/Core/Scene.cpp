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
      return lhs->DistanceFrom(camera_) < rhs->DistanceFrom(camera_);
    });
  }

  RGBColor Scene::Raytrace(const Graphics::PixelPosition& position, bool supersampling) const {
    RGBColor color;
    if (supersampling) {
      std::vector<PixelOffset> sample_offsets{
        {0.25, 0.25}, {0.75, 0.25}, {0.5, 0.5}, {0.25, 0.75}, {0.75, 0.75}
      };
      for (const auto& offset : sample_offsets) {
        color += Trace(CreateRay(position, offset, image_->GetProperties(), camera_)) / 5;
      }
    } else {
      color = Trace(CreateRay(position, {0.5, 0.5}, image_->GetProperties(), camera_));
    }
    return color;
  }

  RGBColor Scene::Trace(const Ray& ray) const {
    RGBColor color;
    for (const auto& shape : shapes_) {
      Vector3D intersection;
      if (shape->Intersects(ray, intersection)) {
        color = shape->GetAmbient();
      }
    }
    return color;
  }
}
