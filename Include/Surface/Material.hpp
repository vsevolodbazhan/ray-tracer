#pragma once

#include "Color/RGBColor.hpp"

namespace Surface {
  struct Material {
    Color::RGBColor color;
    double ambient;
    double diffuse;
    double specular;
    double reflectivity;
    double refractivity;
    double refractive_index;
    double shininess;
  };
}
