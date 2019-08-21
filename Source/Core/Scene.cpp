#include "Core/Scene.hpp"

using namespace Color;
using namespace Graphics;
using namespace Illumination;
using namespace Math;
using namespace Object;

namespace Core {
  Scene::Scene(GenericImage image) : image_(std::move(image)), camera_{Vector3D{0, 0, 0}}, field_of_view_(45) {}

  Scene::Scene(GenericImage image, const Camera& camera, double field_of_view)
    : image_(std::move(image)), camera_(camera), field_of_view_(field_of_view) {}

  void Scene::AddLight(GenericLight light) {
    lights_.push_back(std::move(light));
  }

  void Scene::AddShape(GenericShape shape) {
    shapes_.push_back(std::move(shape));
  }

  void Scene::Render(const std::string& filename) {
    SortShapes();
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

  RGBColor Scene::Trace(const Ray& ray) {
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
