#include "Graphics/PPMImage.hpp"

namespace Graphics {
  PPMImage::PPMImage(const Properties& properties) : Image(properties) {}

  void PPMImage::Export(const std::string& filename) const {
    std::ofstream file(filename + ".ppm", std::ios::binary);
    file << "P6\n" << GetProperties().width << " " << GetProperties().height << "\n255\n";
    for (const Pixel& pixel : *this) {
      file << ConvertToOctet(pixel.color.GetRed())
        << ConvertToOctet(pixel.color.GetGreen())
        << ConvertToOctet(pixel.color.GetBlue());
    }
    file.close();
  }
}
