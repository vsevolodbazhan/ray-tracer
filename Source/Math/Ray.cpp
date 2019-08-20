#include "Math/Ray.hpp"

namespace Math {
  Ray::Ray() {}

  Ray::Ray(const Vector3D& direction) : origin_(), direction_(direction) {}

  Ray::Ray(const Vector3D& origin, const Vector3D& direction) : origin_(origin), direction_(direction) {}

  Ray::Ray(const Ray& other) : origin_(other.origin_), direction_(other.direction_) {}

  Ray::Ray(Ray&& other) : origin_(std::move(other.origin_)), direction_(std::move(other.direction_)) {}

  Vector3D Ray::GetOrigin() const {
    return origin_;
  }

  Vector3D Ray::GetDirection() const {
    return direction_;
  }
}
