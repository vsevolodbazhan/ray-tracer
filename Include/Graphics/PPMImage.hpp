#pragma once

#include "Image.hpp"

namespace Graphics {
  class PPMImage : public Image {
  public:
    explicit PPMImage(const Properties& properties);

    void Export(const std::string& filename) const override;
  };
}
