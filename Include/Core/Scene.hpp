#pragma once

#include "Graphics/Image.hpp"
#include "Illumination/Light.hpp"
#include "Math/Ray.hpp"
#include "Math/Vector3D.hpp"
#include "Object/Camera.hpp"
#include "Object/Shape.hpp"

#include <algorithm>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace Core {
  class Scene {
  public:
    using GenericImage = std::unique_ptr<Graphics::Image>;
    using GenericLight = std::unique_ptr<Illumination::Light>;
    using GenericShape = std::unique_ptr<Object::Shape>;

    Scene() = delete;
    explicit Scene(GenericImage image);
    Scene(GenericImage image, const Object::Camera& camera, double field_of_view);

    void AddLight(GenericLight light);
    void AddShape(GenericShape shape);

    void Render(const std::string& filename);

    void SetCameraPosition(const Math::Vector3D& position);
    void SetFieldOfView(double field_of_view);

  private:
    void SortShapes();

    GenericImage image_;
    Object::Camera camera_;
    double field_of_view_ = 0;
    std::vector<GenericLight> lights_;
    std::vector<GenericShape> shapes_;
  };
}
