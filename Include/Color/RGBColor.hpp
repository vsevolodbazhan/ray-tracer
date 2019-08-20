#pragma once

#include <algorithm>

namespace Color {
  class RGBColor {
  public:
    RGBColor();
    RGBColor(double red, double green, double blue);

    RGBColor& operator+=(const RGBColor& other);
    RGBColor& operator-=(const RGBColor& other);
    RGBColor& operator*=(const RGBColor& other);
    RGBColor& operator/=(const RGBColor& other);
    RGBColor& operator*=(double scalar);
    RGBColor& operator/=(double scalar);

    double GetRed() const;
    double GetGreen() const;
    double GetBlue() const;

  private:
    double Map(double value);
    void MapAll();

    double red_, green_, blue_;
  };

  inline RGBColor operator+(RGBColor lhs, const RGBColor& rhs) {
    lhs += rhs;
    return lhs;
  }

  inline RGBColor operator-(RGBColor lhs, const RGBColor& rhs) {
    lhs -= rhs;
    return lhs;
  }

  inline RGBColor operator*(RGBColor lhs, const RGBColor& rhs) {
    lhs *= rhs;
    return lhs;
  }

  inline RGBColor operator/(RGBColor lhs, const RGBColor& rhs) {
    lhs *= rhs;
    return lhs;
  }

  inline RGBColor operator*(RGBColor lhs, double rhs) {
    lhs *= rhs;
    return lhs;
  }

  inline RGBColor operator*(double lhs, RGBColor rhs) {
    rhs *= lhs;
    return rhs;
  }

  inline RGBColor operator/(RGBColor lhs, double rhs) {
    lhs /= rhs;
    return lhs;
  }

  inline RGBColor operator/(double lhs, RGBColor rhs) {
    rhs /= lhs;
    return rhs;
  }
}
