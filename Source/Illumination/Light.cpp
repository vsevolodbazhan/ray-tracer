#include "Illumination/Light.hpp"

namespace Illumination {
  Light::Light(
    const Math::Vector3D& position,
    const Intensity& intensity)
    : position_(position),
    intensity_(intensity) {}

  double Light::GetAmbientIntesity() const {
    return intensity_.ambient;
  }
}
