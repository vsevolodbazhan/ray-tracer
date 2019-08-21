#include "Math/Ray.hpp"

using namespace Graphics;

namespace Math {
  Ray::Ray() {}

  Ray::Ray(const Vector3D& direction) : origin_(), direction_(direction) {}

  Ray::Ray(const Vector3D& origin, const Vector3D& direction) : origin_(origin), direction_(direction) {}

  Ray::Ray(const PixelPosition& position, const ImageProperties& properties, double field_of_view) : origin_(0, 0, 0) {
    const double real_x = static_cast<double>(position.x);
    const double real_y = static_cast<double>(position.y);
    const double real_width = static_cast<double>(properties.width);
    const double real_height = static_cast<double>(properties.height);
    direction_ = Normalized({
      DirectionX(real_x, real_width, properties.aspect_ratio),
      DirectionY(real_y, real_height),
      DirectionZ(field_of_view)
    });
  }

  Ray::Ray(const Ray& other) : origin_(other.origin_), direction_(other.direction_) {}

  Ray::Ray(Ray&& other) : origin_(std::move(other.origin_)), direction_(std::move(other.direction_)) {}

  Vector3D Ray::GetOrigin() const {
    return origin_;
  }

  Vector3D Ray::GetDirection() const {
    return direction_;
  }

  double Ray::DirectionX(double x, double width, double aspect_ratio) const {
  return ((2 * x / width) - 1) * aspect_ratio;
}

  double Ray::DirectionY(double y, double height) const {
    return -((2 * y / height) - 1);
  }

  double Ray::DirectionZ(double field_of_view) const {
    return -1 / std::tan(field_of_view / 2);
  }
}
