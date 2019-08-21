#include "Core/Ray.hpp"

using namespace Graphics;
using namespace Object;

namespace Core {
  Ray CreateRay(const PixelPosition& position, const Graphics::PixelOffset& offset,
                const ImageProperties& properties, const Camera& camera) {
    const double x = static_cast<double>(position.x);
    const double y = static_cast<double>(position.y);
    const double w = static_cast<double>(properties.width);
    const double h = static_cast<double>(properties.height);
    const Math::Vector3D direction{
      +(2 * (x + offset.x) / w - 1) * properties.aspect_ratio,
      -(2 * (y + offset.y) / h - 1),
      -1 / std::tan(camera.field_of_view / 2)
    };
    return {camera.position, Normalized(direction)};
  }
}
