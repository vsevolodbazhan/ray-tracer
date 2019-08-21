#include "Object/Sphere.hpp"

namespace Object {
  Sphere::Sphere(
    const Surface::Material& material,
    const Math::Vector3D& center,
    double radius)
    : Shape(material),
    center_(center),
    radius_(radius) {}

  double Sphere::DistanceFrom(const Camera& camera) const {
    const Math::Vector3D anchor(camera.position.GetX(), camera.position.GetY(), (center_.GetZ() + radius_));
    return (anchor - camera.position).Length();
  }

  Math::Vector3D Sphere::Normal(const Math::Vector3D& point) const {
    return Normalized(point - center_);
  }

  bool Sphere::Intersects(const Math::Ray& ray, Math::Vector3D& intersection) const {
    const Math::Vector3D origin_center = center_ - ray.GetOrigin();
    // Find the distance from the ray origin to the intersection point or
    // the point located halfway between two intersection points.
    const double origin_point_distance = Dot(origin_center, ray.GetDirection());
    // If this distance is negative then the vector originating from the ray origin and pointing
    // to the center of the sphere is directed opposite to the ray direciton.
    // Which means that ray doesn't intersect the sphere.
    if (origin_point_distance < 0) {
      return false;
    }
    // Find the distance from the center of the sphere to the intersection point or
    // the point located halfway between two intersection points.
    const double center_point_distance = std::sqrt(
      origin_center.LengthSquared() - std::pow(origin_point_distance, 2)
    );
    // If this distance is greater than the radius of the sphere then the ray is outside of the sphere.
    if (center_point_distance > radius_) {
      return false;
    }
    // Otherwise the ray has one or two intersection points with the sphere.
    // Distance to each point of intersection.
    const double point_intersection_distance = std::sqrt(
      std::pow(radius_, 2) - std::pow(center_point_distance, 2)
    );
    // The closest (or the only) intersection point
    // is to the left of the point located halfway between two intersection points.
    intersection = ray.GetOrigin() + ray.GetDirection() * (origin_point_distance - point_intersection_distance);
    return true;
  }

  Math::Vector3D Sphere::GetCenter() const {
    return center_;
  }

  double Sphere::GetRadius() const {
    return radius_;
  }
}
