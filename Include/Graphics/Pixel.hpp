#pragma once

#include "Color/RGBColor.hpp"
#include "Math/Point2D.hpp"

#include <cstddef>

namespace Graphics {
  struct Pixel {
    Math::Point2D<std::size_t> position;
    Color::RGBColor color;
  };
};
