#include "Math/Vector3D.hpp"

namespace Math {
  Vector3D::Vector3D() {}

  Vector3D::Vector3D(double x, double y, double z) : point_{x, y, z} {}

  Vector3D::Vector3D(const Point3D<double>& point) : point_(point) {}

  Vector3D::Vector3D(const Vector3D& other) : point_(other.point_) {}

  Vector3D::Vector3D(Vector3D&& other) : point_(std::move(other.point_)) {}

  void Vector3D::Normalize() {
    const double length = Length();
    point_.x /= length;
    point_.y /= length;
    point_.z /= length;
  }

  void Vector3D::Negate() {
    point_.x = -point_.x;
    point_.y = -point_.y;
    point_.z = -point_.z;
  }

  Vector3D& Vector3D::operator+=(const Vector3D& other) {
    point_.x += other.point_.x;
    point_.y += other.point_.y;
    point_.z += other.point_.z;
    return *this;
  }

  Vector3D& Vector3D::operator-=(const Vector3D& other) {
    point_.x -= other.point_.x;
    point_.y -= other.point_.y;
    point_.z -= other.point_.z;
    return *this;
  }

  Vector3D& Vector3D::operator*=(double scalar) {
    point_.x *= scalar;
    point_.y *= scalar;
    point_.z *= scalar;
    return *this;
  }

  Vector3D& Vector3D::operator/=(double scalar) {
    point_.x /= scalar;
    point_.y /= scalar;
    point_.z /= scalar;
    return *this;
  }

  void Vector3D::SetX(double x) {
    point_.x = x;
  }

  void Vector3D::SetY(double y) {
    point_.y = y;
  }

  void Vector3D::SetZ(double z) {
    point_.z = z;
  }

  double Vector3D::GetX() const {
    return point_.x;
  }

  double Vector3D::GetY() const {
    return point_.y;
  }

  double Vector3D::GetZ() const {
    return point_.z;
  }

  double Vector3D::LengthSquared() const {
    return point_.x * point_.x + point_.y * point_.y + point_.z * point_.z;
  }

  double Vector3D::Length() const {
    return std::sqrt(point_.x * point_.x + point_.y * point_.y + point_.z * point_.z);
  }

  double Dot(const Vector3D& lhs, const Vector3D& rhs) {
    return lhs.GetX() * rhs.GetX() + lhs.GetY() * rhs.GetY() + lhs.GetZ() * rhs.GetZ();
  }

  double Angle(const Vector3D& lhs, const Vector3D& rhs) {
    return std::acos(Dot(lhs, rhs) / (lhs.Length() * rhs.Length()));
  }

  Vector3D Cross(const Vector3D& lhs, const Vector3D& rhs) {
    return {
      lhs.GetY() * rhs.GetZ() - lhs.GetZ() * rhs.GetY(),
      lhs.GetZ() * rhs.GetX() - lhs.GetX() * rhs.GetZ(),
      lhs.GetX() * rhs.GetY() - lhs.GetY() * rhs.GetX()
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
