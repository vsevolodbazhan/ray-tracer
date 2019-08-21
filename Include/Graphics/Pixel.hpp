#pragma once

#include "Color/RGBColor.hpp"

#include <cstddef>

namespace Graphics {
  struct PixelPosition {
    std::size_t x = 0;
    std::size_t y = 0;
  };

  struct Pixel {
    PixelPosition position;
    Color::RGBColor color;
  };
}
