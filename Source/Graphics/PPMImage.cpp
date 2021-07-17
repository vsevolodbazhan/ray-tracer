#include "Graphics/PPMImage.hpp"

#include <iostream>

namespace Graphics {
  PPMImage::PPMImage() : Image() {}

  PPMImage::PPMImage(const ImageProperties& properties) : Image(properties) {}

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

  void PPMImage::Import(const std::string& filename) {
    std::ifstream file(filename + ".ppm", std::ios::binary);
    std::string subformat;
    file >> subformat;
    std::cout << subformat << std::endl;

    std::size_t width, height;
    file >> width >> height;
    std::cout << width << " " << height << std::endl;

    std::list<Pixel>& pixels = GetPixels();
    pixels.clear();
    pixels.resize(width * height);

    for (auto& pixel : pixels) {
      uint8_t component;
      file >> component;
      std::cout << component << std::endl;
      pixel.color.SetRed(ConverFromOctet(component));
      file >> component;
      std::cout << component / 255 << std::endl;
      pixel.color.SetGreen(ConverFromOctet(component));
      file >> component;
      std::cout << component / 255 << std::endl;
      pixel.color.SetBlue(ConverFromOctet(component));
    }

    file.close();
  }
}
