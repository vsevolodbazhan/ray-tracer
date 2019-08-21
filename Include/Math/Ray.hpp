#pragma once

#include "Vector3D.hpp"

#include "Graphics/Image.hpp"
#include "Graphics/Pixel.hpp"

#include <utility>

namespace Math {
  class Ray {
  public:
    Ray();
    explicit Ray(const Vector3D& direction);
    Ray(const Vector3D& origin, const Vector3D& direction);
    Ray(const Graphics::PixelPosition& position, const Graphics::ImageProperties& properties, double field_of_view);
    Ray(const Ray& other);
    Ray(Ray&& other);

    Vector3D GetOrigin() const;
    Vector3D GetDirection() const;

  private:
    double DirectionX(double x, double width, double aspect_ratio) const;
    double DirectionY(double y, double height) const;
    double DirectionZ(double field_of_view) const;

    Vector3D origin_;
    Vector3D direction_;
  };
}
