#pragma once
#include <memory>
#include <cmath>

namespace Vector {

struct Vector {
  float i, j, k;
  Vector(float i_, float j_, float k_): i(i_), j(j_), k(k_) {}
};

inline std::unique_ptr<Vector> create_vector(float i, float j, float k) {
  return std::make_unique<Vector>(i, j, k);
}

inline std::unique_ptr<Vector> add(const Vector* a, const Vector* b) {
  return std::make_unique<Vector>(a->i + b->i, a->j + b->j, a->k + b->k);
}

inline std::unique_ptr<Vector> sub(const Vector* a, const Vector* b) {
  return std::make_unique<Vector>(a->i - b->i, a->j - b->j, a->k - b->k);
}


inline std::unique_ptr<Vector> scale(const Vector* a, float k) {
  return std::make_unique<Vector>(a->i * k, a->j * k, a->k * k);
}

inline float dot(const Vector* a, const Vector* b) {
  return a->i * b->i + a->j * b->j + a->k * b->k;
}

inline std::unique_ptr<Vector> cross(const Vector* a, const Vector* b) {
  return std::make_unique<Vector>(
    a->j * b->k - a->k * b->j,
    a->k * b->i - a->i * b->k,
    a->i * b->j - a->j * b->i
  );
}

inline float magnitude(const Vector* a) {
  return std::sqrt(a->i * a->i + a->j * a->j + a->k * a->k);
}

inline std::unique_ptr<Vector> normalize(const Vector* a) {
  float mag = magnitude(a);
  if (mag == 0.0f) {
    return std::make_unique<Vector>(0.0f, 0.0f, 0.0f);
  }
  return std::make_unique<Vector>(a->i / mag, a->j / mag, a->k / mag);
}

inline float distance(const Vector* a, const Vector* b) {
  auto diff = sub(a, b);
  return magnitude(diff.get());
}

} // namespace Vector
