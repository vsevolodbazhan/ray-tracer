#include "Illumination/Light.hpp"

namespace Illumination {
  Light::Light(
    const Math::Vector3D& position,
    const Intensity& intensity)
    : position_(position),
    intensity_(intensity) {}

  Math::Vector3D Light::Direction(const Math::Vector3D& point) const {
    return Normalized(point - position_);
  }

  Math::Vector3D Light::View(const Object::Camera& camera, const Math::Vector3D& point) const {
    return Normalized(camera.position - point);
  }

  Math::Vector3D Light::Halfway(const Math::Vector3D& direction_toward_light, const Math::Vector3D& view) const {
    return Normalized(direction_toward_light + view);
  }

  Color::RGBColor Light::Illumination(const Core::RayHit& hit, const Object::Camera& camera) {
    const Math::Vector3D direction_toward_light = Negated(Direction(hit.intersection));
    const Math::Vector3D view = View(camera, hit.intersection);
    const Math::Vector3D halfway = Halfway(direction_toward_light, view);
    return AmbientComponent(hit.material.ambient) +
           DiffuseComponent(hit.material.diffuse, direction_toward_light, hit.normal) +
           SpecularComponent(hit.material.specular, hit.material.shininess, halfway, hit.normal);
  }

  Color::RGBColor Light::AmbientComponent(const Color::RGBColor& ambient) {
    return intensity_.ambient * ambient;
  }

  Color::RGBColor Light::DiffuseComponent(const Color::RGBColor& diffuse, const Math::Vector3D& direction_toward_light,
                                          const Math::Vector3D& normal) {
    return intensity_.diffuse * diffuse * std::max(Dot(direction_toward_light, normal), 0.0);
  }

  Color::RGBColor Light::SpecularComponent(const Color::RGBColor& specular, double shininess,
                                           const Math::Vector3D& halfway, const Math::Vector3D& normal) {
    return intensity_.specular * specular * std::pow(std::max(Dot(halfway, normal), 0.0), shininess);
  }

  double Light::GetAmbientIntesity() const {
    return intensity_.ambient;
  }
}
