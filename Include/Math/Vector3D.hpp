#pragma once

#include <cmath>
#include <tuple>
#include <utility>

namespace Math {
  struct Vector3D {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    void Negate();
    void Normalize();

    double LengthSquared() const;
    double Length() const;

    Vector3D& operator+=(const Vector3D& other);
    Vector3D& operator-=(const Vector3D& other);

    Vector3D& operator*=(double scalar);
    Vector3D& operator/=(double scalar);
  };

  double Dot(const Vector3D& lhs, const Vector3D& rhs);
  double Angle(const Vector3D& lhs, const Vector3D& rhs);

  Vector3D Cross(const Vector3D& lhs, const Vector3D& rhs);
  Vector3D Normalized(const Vector3D& vector);
  Vector3D Negated(const Vector3D& vector);

  inline Vector3D operator+(Vector3D lhs, const Vector3D& rhs) {
    lhs += rhs;
    return lhs;
  }

  inline Vector3D operator-(Vector3D lhs, const Vector3D& rhs) {
    lhs -= rhs;
    return lhs;
  }

  inline Vector3D operator*(Vector3D lhs, double rhs) {
    lhs *= rhs;
    return lhs;
  }

  inline Vector3D operator*(double lhs, Vector3D rhs) {
    rhs *= lhs;
    return rhs;
  }
} // namespace Math
