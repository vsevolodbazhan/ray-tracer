#pragma once

#include "Position.hpp"

#include "Color/RGBColor.hpp"

#include <cstddef>

namespace Graphics {
  struct Pixel {
    Position position;
    Color::RGBColor color;
  };
}
