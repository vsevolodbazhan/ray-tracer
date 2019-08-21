#pragma once

#include "Graphics/Image.hpp"
#include "Graphics/Pixel.hpp"
#include "Math/Vector3D.hpp"
#include "Object/Camera.hpp"

namespace Core {
  struct Ray {
    Math::Vector3D origin;
    Math::Vector3D direction;
  };

  Ray CreateRay(const Graphics::PixelPosition& position, const Graphics::ImageProperties& properties,
    const Object::Camera& camera);
}
