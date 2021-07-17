#include "Color/RGBColor.hpp"

namespace Color {
  RGBColor::RGBColor() : red_(0.0), green_(0.0), blue_(0.0) {}

  RGBColor::RGBColor(double red, double green, double blue)
    : red_(Map(red)), green_(Map(green)), blue_(Map(blue)) {}

  RGBColor::RGBColor(const RGBColor& other)
    : red_(other.red_), green_(other.green_), blue_(other.blue_) {}

  RGBColor::RGBColor(RGBColor&& other)
    : red_(std::move(other.red_)),
      green_(std::move(other.green_)),
      blue_(std::move(other.blue_)) {}

  RGBColor& RGBColor::operator=(const RGBColor& other) {
    if (this != &other) {
      red_   = other.red_;
      green_ = other.green_;
      blue_  = other.blue_;
    }
    return *this;
  }

  RGBColor& RGBColor::operator=(RGBColor&& other) {
    red_   = std::move(other.red_);
    green_ = std::move(other.green_);
    blue_  = std::move(other.blue_);
    return *this;
  }

  RGBColor& RGBColor::operator+=(const RGBColor& other) {
    red_ += other.red_;
    green_ += other.green_;
    blue_ += other.blue_;
    MapAll();
    return *this;
  }

  RGBColor& RGBColor::operator-=(const RGBColor& other) {
    red_ -= other.red_;
    green_ -= other.green_;
    blue_ -= other.blue_;
    MapAll();
    return *this;
  }

  RGBColor& RGBColor::operator*=(const RGBColor& other) {
    red_ *= other.red_;
    green_ *= other.green_;
    blue_ *= other.blue_;
    MapAll();
    return *this;
  }

  RGBColor& RGBColor::operator/=(const RGBColor& other) {
    red_ /= other.red_;
    green_ /= other.green_;
    blue_ /= other.blue_;
    MapAll();
    return *this;
  }

  RGBColor& RGBColor::operator*=(double scalar) {
    red_ *= scalar;
    green_ *= scalar;
    blue_ *= scalar;
    MapAll();
    return *this;
  }

  RGBColor& RGBColor::operator/=(double scalar) {
    red_ /= scalar;
    green_ /= scalar;
    blue_ /= scalar;
    MapAll();
    return *this;
  }

  void RGBColor::SetRed(double red) {
    red_ = Map(red);
  }

  void RGBColor::SetGreen(double green) {
    green_ = Map(green);
  }

  void RGBColor::SetBlue(double blue) {
    blue_ = Map(blue);
  }

  double RGBColor::GetRed() const {
    return red_;
  }

  double RGBColor::GetGreen() const {
    return green_;
  }

  double RGBColor::GetBlue() const {
    return blue_;
  }

  double RGBColor::Map(double value) {
    return std::max(0.0, std::min(1.0, value));
  }

  void RGBColor::MapAll() {
    red_   = Map(red_);
    green_ = Map(green_);
    blue_  = Map(blue_);
  }
} // namespace Color
