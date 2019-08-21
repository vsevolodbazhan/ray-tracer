#include "Math/Vector3D.hpp"

namespace Math {
  void Vector3D::Normalize() {
    const double length = Length();
    x /= length;
    y /= length;
    z /= length;
  }

  void Vector3D::Negate() {
    x = -x;
    y = -y;
    z = -z;
  }

  Vector3D& Vector3D::operator+=(const Vector3D& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
  }

  Vector3D& Vector3D::operator-=(const Vector3D& other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
  }

  Vector3D& Vector3D::operator*=(double scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
  }

  Vector3D& Vector3D::operator/=(double scalar) {
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
  }

  double Vector3D::LengthSquared() const {
    return x * x + y * y + z * z;
  }

  double Vector3D::Length() const {
    return std::sqrt(x * x + y * y + z * z);
  }

  double Dot(const Vector3D& lhs, const Vector3D& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
  }

  double Angle(const Vector3D& lhs, const Vector3D& rhs) {
    return std::acos(Dot(lhs, rhs) / (lhs.Length() * rhs.Length()));
  }

  Vector3D Cross(const Vector3D& lhs, const Vector3D& rhs) {
    return {
      lhs.y * rhs.z - lhs.z * rhs.y,
      lhs.z * rhs.x - lhs.x * rhs.z,
      lhs.x * rhs.y - lhs.y * rhs.x
    };
  }

  Vector3D Normalized(const Vector3D& vector) {
    Vector3D normalized = vector;
    normalized.Normalize();
    return normalized;
  }

  Vector3D Negated(const Vector3D& vector) {
    Vector3D negated = vector;
    negated.Negate();
    return negated;
  }
}
