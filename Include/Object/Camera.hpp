#pragma once

#include "Math/Vector3D.hpp"

namespace Object {
  struct Camera {
    Math::Vector3D position;
    double field_of_view;
  };
}
