#include "Object/Shape.hpp"

namespace Object {
  Shape::Shape(const Surface::Material& material) : material_(material) {}

  Color::RGBColor Shape::GetAmbient() const {
    return material_.ambient;
  }
}
