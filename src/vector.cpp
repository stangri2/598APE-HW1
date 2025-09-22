#include <limits>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <printf.h>
#include "vector.h"
#include <iostream>
#include <map>
#include <sstream>
#include <stddef.h>
#include <vector>

Vector::Vector() : x(), y(), z() {}

Vector::Vector(double a, double b, double c) : x(a), y(b), z(c) {}

bool Vector::operator==(const Vector other) const {
  constexpr double EPS = 1e-6;
  auto eq = [&](double a, double b) {
    return std::abs(a - b) < EPS * (1.0 + std::abs(a) + std::abs(b));
  };

  bool same = eq(x, other.x) && eq(y, other.y) && eq(z, other.z);
  if (!same) {
    std::cerr << "Vector mismatch:\n"
              << "  lhs = (" << x << ", " << y << ", " << z << ")\n"
              << "  rhs = (" << other.x << ", " << other.y << ", " << other.z
              << ")\n";
  }
  return same;
}

bool Vector::operator!=(const Vector other) const { return !(*this == other); }

void Vector::operator-=(const Vector rhs) {
  x -= rhs.x;
  y -= rhs.y;
  z -= rhs.z;
}
void Vector::operator+=(const Vector rhs) {
  x += rhs.x;
  y += rhs.y;
  z += rhs.z;
}
void Vector::operator*=(const double rhs) {
  x *= rhs;
  y *= rhs;
  z *= rhs;
}
void Vector::operator*=(const float rhs) {
  x *= rhs;
  y *= rhs;
  z *= rhs;
}
void Vector::operator*=(const int rhs) {
  x *= rhs;
  y *= rhs;
  z *= rhs;
}
void Vector::operator/=(const double rhs) {
  x /= rhs;
  y /= rhs;
  z /= rhs;
}
void Vector::operator/=(const float rhs) {
  x /= rhs;
  y /= rhs;
  z /= rhs;
}
void Vector::operator/=(const int rhs) {
  x /= rhs;
  y /= rhs;
  z /= rhs;
}

Vector Vector::operator-(const Vector rhs) {
  return Vector(x - rhs.x, y - rhs.y, z - rhs.z);
}
Vector Vector::operator+(const Vector rhs) {
  return Vector(x + rhs.x, y + rhs.y, z + rhs.z);
}
/*
Vector Vector::operator * (const Vector a) {
   return Vector(y*a.z-z*a.y, z*a.x-x*a.z, x*a.y-y*a.x);
}*/
Vector Vector::operator*(const double rhs) {
  return Vector(x * rhs, y * rhs, z * rhs);
}
Vector Vector::operator*(const float rhs) {
  return Vector(x * rhs, y * rhs, z * rhs);
}
Vector Vector::operator*(const int rhs) {
  return Vector(x * rhs, y * rhs, z * rhs);
}
Vector Vector::operator/(const double rhs) {
  return Vector(x / rhs, y / rhs, z / rhs);
}
Vector Vector::operator/(const float rhs) {
  return Vector(x / rhs, y / rhs, z / rhs);
}
Vector Vector::operator/(const int rhs) {
  return Vector(x / rhs, y / rhs, z / rhs);
}
Vector Vector::cross(const Vector a) {
  return Vector(y * a.z - z * a.y, z * a.x - x * a.z, x * a.y - y * a.x);
}
double Vector::mag2() { return x * x + y * y + z * z; }
double Vector::mag() { return sqrt(x * x + y * y + z * z); }
double Vector::dot(const Vector a) { return x * a.x + y * a.y + z * a.z; }
Vector Vector::normalize() {
  double m = mag();
  return Vector(x / m, y / m, z / m);
}

Vector solveScalers(Vector v1, Vector v2, Vector v3, Vector C) {
  double denom = v1.dot(v3.cross(v2));
  double a = C.dot(v3.cross(v2));
  double b = C.dot(v1.cross(v3));
  double c = C.dot(v2.cross(v1));
  return Vector(a / denom, b / denom, c / denom);
}

Vector solveScalersFast(const SolveScalersCache &cache, Vector C) {
  double a = C.dot(cache.cross_v3v2);
  double b = C.dot(cache.cross_v1v3);
  double c = C.dot(cache.cross_v2v1);
  return Vector(a * cache.invDenom, b * cache.invDenom, c * cache.invDenom);
}

Ray::Ray(const Vector &po, const Vector &ve) : point(po), vector(ve) {}
