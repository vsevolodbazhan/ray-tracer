#include "Graphics/Image.hpp"

namespace Graphics {
  Image::Image() : properties_{} {}

  Image::Image(const Properties& properties) : properties_(properties), pixels_(properties.width * properties.height) {
    Position current_position{0, 0};
    for (Pixel& pixel : pixels_) {
      pixel.position = current_position;
      pixel.color = properties_.background;
      if (++current_position.x == properties_.width) {
        current_position.x = 0;
        ++current_position.y;
      }
    }
  }

  Properties Image::GetProperties() const {
    return properties_;
  }

  Image::PixelsIterator Image::begin() {
    return pixels_.begin();
  }

  Image::PixelsIterator Image::end() {
    return pixels_.end();
  }

  const Image::ConstPixelsIterator Image::begin() const {
    return pixels_.begin();
  }

  const Image::ConstPixelsIterator Image::end() const {
    return pixels_.end();
  }

  uint8_t Image::ConvertToOctet(double compenent) const {
    return static_cast<uint8_t>(255 * compenent);
  }
}
