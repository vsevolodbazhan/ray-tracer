#pragma once

#include "Pixel.hpp"

#include "Color/RGBColor.hpp"

#include <algorithm>
#include <cstddef>
#include <fstream>
#include <list>
#include <string>

namespace Graphics {
  struct ImageProperties {
    std::size_t width = 0;
    std::size_t height = 0;
    double aspect_ratio = static_cast<double>(width) / static_cast<double>(height);
  };

  class Image {
  public:
    using Pixels = std::list<Pixel>;
    using PixelsIterator = Pixels::iterator;
    using ConstPixelsIterator = Pixels::const_iterator;

    Image();
    explicit Image(const ImageProperties& properties);

    virtual ~Image() = default;

    virtual void Export(const std::string&) const = 0;

    PixelsIterator begin();
    PixelsIterator end();

    const ConstPixelsIterator begin() const;
    const ConstPixelsIterator end() const;

    ImageProperties GetProperties() const;

  protected:
    uint8_t ConvertToOctet(double compenent) const;

  private:
    ImageProperties properties_;
    std::list<Pixel> pixels_;
  };
}
