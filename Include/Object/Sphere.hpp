#pragma once

#include "Camera.hpp"
#include "Shape.hpp"

#include "Core/Ray.hpp"
#include "Math/Vector3D.hpp"
#include "Surface/Material.hpp"

namespace Object {
  class Sphere : public Shape {
  public:
    Sphere() = delete;
    Sphere(const Surface::Material& material, const Math::Vector3D& center, double radius);

    double DistanceFrom(const Camera& camera) const override;
    Math::Vector3D Normal(const Math::Vector3D& point) const override;
    bool Intersects(const Core::Ray& ray, Core::RayHit& hit) const override;

    Math::Vector3D GetCenter() const;
    double GetRadius() const;

  private:
    Math::Vector3D center_;
    double radius_;
  };
}
