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
    Light(const Math::Vector3D& position, double intensity);

    Math::Vector3D Direction(const Math::Vector3D& point) const;

    Math::Vector3D View(const Object::Camera& camera,
                        const Math::Vector3D& point) const;

    Math::Vector3D Halfway(const Math::Vector3D& direction_toward_light,
                           const Math::Vector3D& view) const;

    Color::RGBColor Illumination(const Core::RayHit& hit,
                                 const Object::Camera& camera);

    double AmbientComponent(double ambient);

    double DiffuseComponent(double diffuse,
                            const Math::Vector3D& direction_toward_light,
                            const Math::Vector3D& normal);

    double SpecularComponent(double specular,
                             double shininess,
                             const Math::Vector3D& halfway,
                             const Math::Vector3D& normal);

  private:
    Math::Vector3D position_;
    double intensity_;
  };
} // namespace Illumination
