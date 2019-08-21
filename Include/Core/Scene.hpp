#pragma once

#include "Ray.hpp"

#include "Color/RGBColor.hpp"
#include "Graphics/Image.hpp"
#include "Illumination/Light.hpp"
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
    Scene(GenericImage image, const Object::Camera& camera);

    void AddLight(GenericLight light);
    void AddShape(GenericShape shape);

    void Render(const std::string& filename, bool supersampling = false);

    void SetCameraPosition(const Math::Vector3D& position);
    void SetFieldOfView(double field_of_view);

  private:
    void SortShapes();

    Color::RGBColor Raytrace(const Graphics::PixelPosition& position, bool supersampling) const;
    Color::RGBColor Trace(const Ray& ray) const;

    GenericImage image_;
    Object::Camera camera_;
    double field_of_view_ = 0;
    std::vector<GenericLight> lights_;
    std::vector<GenericShape> shapes_;
  };
}
