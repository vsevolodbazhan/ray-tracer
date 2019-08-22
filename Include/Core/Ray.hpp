#pragma once

#include "Graphics/Image.hpp"
#include "Graphics/Pixel.hpp"
#include "Math/Vector3D.hpp"
#include "Object/Camera.hpp"
#include "Surface/Material.hpp"

namespace Core {
  struct Ray {
    Math::Vector3D origin;
    Math::Vector3D direction;
  };

  struct RayHit {
    Math::Vector3D intersection;
    Math::Vector3D normal;
    Surface::Material material;
  };

  Ray CreateRay(const Graphics::PixelPosition& position, const Graphics::PixelOffset& offset,
                const Graphics::ImageProperties& properties, const Object::Camera& camera);
}
