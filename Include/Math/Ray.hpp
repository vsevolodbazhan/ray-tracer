#include "Vector3D.hpp"

#include <utility>

namespace Math {
  class Ray {
  public:
    Ray();
    explicit Ray(const Vector3D& direction);
    Ray(const Vector3D& origin, const Vector3D& direction);
    Ray(const Ray& other);
    Ray(Ray&& other);

    Vector3D GetOrigin() const;
    Vector3D GetDirection() const;

  private:
    Vector3D origin_;
    Vector3D direction_;
  };
}
