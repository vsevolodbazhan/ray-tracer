#pragma once

#include "Math/Vector3D.hpp"

namespace Illumination {
  struct Intensity {
    double ambient;
  };

  class Light {
  public:
    Light() = delete;
    Light(const Math::Vector3D& position, const Intensity& intensity);

    double GetAmbientIntesity() const;

  private:
    Math::Vector3D position_;
    Intensity intensity_;
  };
}
