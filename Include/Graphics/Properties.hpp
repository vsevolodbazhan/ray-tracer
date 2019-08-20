#pragma once

#include "Color/RGBColor.hpp"

#include <cstddef>

namespace Graphics {
  struct Properties {
    std::size_t width = 0;
    std::size_t height = 0;
    Color::RGBColor background = Color::RGBColor(0, 0, 0);
    double aspect_ratio = static_cast<double>(width) / static_cast<double>(height);
  };
}
