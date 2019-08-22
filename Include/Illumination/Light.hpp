#pragma once

#include "Core/Ray.hpp"
#include "Math/Vector3D.hpp"
#include "Object/Camera.hpp"

namespace Illumination {
  struct Intensity {
    double ambient;
    double diffuse;
    double specular;
  };

  class Light {
  public:
    Light() = delete;
    Light(const Math::Vector3D& position, const Intensity& intensity);

    Math::Vector3D Direction(const Math::Vector3D& point) const;

    Math::Vector3D View(const Object::Camera& camera, const Math::Vector3D& point) const;

    Math::Vector3D Halfway(const Math::Vector3D& direction_toward_light, const Math::Vector3D& view) const;

    Color::RGBColor Illumination(const Core::RayHit& hit, const Object::Camera& camera);

    Color::RGBColor AmbientComponent(const Color::RGBColor& ambient);

    Color::RGBColor DiffuseComponent(const Color::RGBColor& diffuse,
                                     const Math::Vector3D& direction_toward_light,
                                     const Math::Vector3D& normal);

    Color::RGBColor SpecularComponent(const Color::RGBColor& specular,
                                      double shininess,
                                      const Math::Vector3D& halfway,
                                      const Math::Vector3D& normal);

    double GetAmbientIntesity() const;

  private:
    Math::Vector3D position_;
    Intensity intensity_;
  };
}
