#pragma once

#include "Camera.hpp"

#include "Color/RGBColor.hpp"
#include "Core/Ray.hpp"
#include "Math/Vector3D.hpp"
#include "Surface/Material.hpp"

namespace Object {
  class Shape {
  public:
    Shape() = delete;
    explicit Shape(const Surface::Material& material);

    virtual ~Shape() = default;

    virtual double DistanceFrom(const Camera& camera) const = 0;
    virtual Math::Vector3D Normal(const Math::Vector3D& point) const = 0;
    virtual bool Intersects(const Core::Ray& ray, Core::RayHit& hit) const = 0;

    Surface::Material GetMaterial() const;

  private:
    Surface::Material material_;
  };
}
