#pragma once

#include "Pixel.hpp"
#include "Properties.hpp"

#include "Color/RGBColor.hpp"

#include <algorithm>
#include <cstddef>
#include <fstream>
#include <list>
#include <string>

namespace Graphics {
  class Image {
  public:
    using Pixels = std::list<Pixel>;
    using PixelsIterator = Pixels::iterator;
    using ConstPixelsIterator = Pixels::const_iterator;

    Image();
    explicit Image(const Properties& properties);

    virtual ~Image() = default;

    virtual void Export(const std::string&) const = 0;

    PixelsIterator begin();
    PixelsIterator end();

    const ConstPixelsIterator begin() const;
    const ConstPixelsIterator end() const;

    Properties GetProperties() const;

  protected:
    uint8_t ConvertToOctet(double compenent) const;

  private:
    Properties properties_;
    std::list<Pixel> pixels_;
  };
}
