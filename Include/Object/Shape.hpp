#pragma once

#include "Color/RGBColor.hpp"
#include "Math/Ray.hpp"
#include "Math/Vector3D.hpp"
#include "Surface/Material.hpp"

namespace Object {
  class Shape {
  public:
    Shape() = delete;
    explicit Shape(const Surface::Material& material);

    virtual ~Shape() = default;

    virtual double Anchor() const = 0;
    virtual Math::Vector3D Normal(const Math::Vector3D& point) const = 0;
    virtual bool Intersects(const Math::Ray& ray, Math::Vector3D& intersection) const = 0;

    Color::RGBColor GetAmbient() const;

  private:
    Surface::Material material_;
  };
}
