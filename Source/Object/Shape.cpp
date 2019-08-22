#include "Object/Shape.hpp"

namespace Object {
  Shape::Shape(const Surface::Material& material) : material_(material) {}

  Surface::Material Shape::GetMaterial() const {
    return material_;
  }
}
