#pragma once
#include <cmath>

namespace Vector {

struct Vector {
  float i, j, k;
  
  Vector() : i(0.0f), j(0.0f), k(0.0f) {}
  Vector(float i_, float j_, float k_) : i(i_), j(j_), k(k_) {}
};

inline Vector add(const Vector& a, const Vector& b) {
  return Vector(a.i + b.i, a.j + b.j, a.k + b.k);
}

inline Vector sub(const Vector& a, const Vector& b) {
  return Vector(a.i - b.i, a.j - b.j, a.k - b.k);
}

inline Vector scale(const Vector& a, float k) {
  return Vector(a.i * k, a.j * k, a.k * k);
}

inline float dot(const Vector& a, const Vector& b) {
  return a.i * b.i + a.j * b.j + a.k * b.k;
}

inline Vector cross(const Vector& a, const Vector& b) {
  return Vector(
    a.j * b.k - a.k * b.j,
    a.k * b.i - a.i * b.k,
    a.i * b.j - a.j * b.i
  );
}

inline float magnitude(const Vector& a) {
  return std::sqrt(a.i * a.i + a.j * a.j + a.k * a.k);
}

inline Vector normalize(const Vector& a) {
  float mag = magnitude(a);
  if (mag == 0.0f) {
    return Vector(0.0f, 0.0f, 0.0f);
  }
  return Vector(a.i / mag, a.j / mag, a.k / mag);
}

inline float distance(const Vector& a, const Vector& b) {
  Vector diff = sub(a, b);
  return magnitude(diff);
}

} // namespace Vector
