#pragma once

#include "Color/RGBColor.hpp"

namespace Surface {
  struct Material {
    Color::RGBColor ambient;
    Color::RGBColor diffuse;
    Color::RGBColor specular;
    double shininess;
  };
}
