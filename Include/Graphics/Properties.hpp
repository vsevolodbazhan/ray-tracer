#pragma once

#include <cstddef>

namespace Graphics {
  struct Properties {
    std::size_t width = 0;
    std::size_t height = 0;
    double aspect_ratio = static_cast<double>(width) / static_cast<double>(height);
  };
}
