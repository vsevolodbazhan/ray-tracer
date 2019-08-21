#pragma once

#include "Image.hpp"

namespace Graphics {
  class PPMImage : public Image {
  public:
    PPMImage();
    explicit PPMImage(const ImageProperties& properties);

    void Export(const std::string& filename) const override;
  };
}
