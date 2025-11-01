#include "math/calculus.hpp"
#include "math/vector.hpp"
#include <cmath>
#include <iostream>

int main() {
  auto v1 = Vector::create_vector(1.0f, 2.0f, 3.0f);
  auto v2 = Vector::create_vector(4.0f, 5.0f, 6.0f);
  auto v3 = Vector::create_vector(0.0f, 1.0f, 2.0f);

  std::cout << "Vector Operations:\n";
  std::cout << "v1 = (" << v1->i << ", " << v1->j << ", " << v1->k << ")\n";
  std::cout << "v2 = (" << v2->i << ", " << v2->j << ", " << v2->k << ")\n";
  std::cout << "v3 = (" << v3->i << ", " << v3->j << ", " << v3->k << ")\n\n";

  auto v_add = Vector::add(v1.get(), v2.get());
  std::cout << "v1 + v2 = (" << v_add->i << ", " << v_add->j << ", " << v_add->k << ")\n";

  auto v_sub = Vector::sub(v2.get(), v1.get());
  std::cout << "v2 - v1 = (" << v_sub->i << ", " << v_sub->j << ", " << v_sub->k << ")\n";

  float scale_factor = 2.5f;
  auto v_scaled = Vector::scale(v1.get(), scale_factor);
  std::cout << scale_factor << " * v1 = (" << v_scaled->i << ", " << v_scaled->j << ", " << v_scaled->k << ")\n";

  float dot_product = Vector::dot(v1.get(), v2.get());
  std::cout << "v1 . v2 = " << dot_product << "\n";

  auto v_cross = Vector::cross(v1.get(), v2.get());
  std::cout << "v1 x v2 = (" << v_cross->i << ", " << v_cross->j << ", " << v_cross->k << ")\n";

  float mag_v1 = Vector::magnitude(v1.get());
  std::cout << "|v1| = " << mag_v1 << "\n";

  auto v_normalized = Vector::normalize(v1.get());
  std::cout << "v1 normalized = (" << v_normalized->i << ", " << v_normalized->j << ", " << v_normalized->k << ")\n";
  float mag_normalized = Vector::magnitude(v_normalized.get());
  std::cout << "Magnitude of normalized v1 = " << mag_normalized << "\n";

  float dist = Vector::distance(v1.get(), v2.get());
  std::cout << "Distance between v1 and v2 = " << dist << "\n\n";

  std::cout << "Calculus Operations:\n";

  auto f1 = [](double x) { return x * x; };
  double integral_result = Calculus::integrate_1d(f1, 0.0, 2.0, 1000);
  std::cout << "Integral of x^2 from 0 to 2 = " << integral_result << "\n";
  std::cout << "Expected (exact): " << (2.0 * 2.0 * 2.0 / 3.0) << "\n\n";

  auto f2 = [](double x) { return std::sin(x); };
  double integral_sin = Calculus::integrate_1d(f2, 0.0, 3.14159, 1000);
  std::cout << "Integral of sin(x) from 0 to pi = " << integral_sin << "\n";
  std::cout << "Expected (exact): 2.0\n\n";

  auto f3 = [](double x) { return x * x * x; };
  double derivative_at_2 = Calculus::differentiate(f3, 2.0);
  std::cout << "Derivative of x^3 at x=2 = " << derivative_at_2 << "\n";
  std::cout << "Expected (exact): " << (3.0 * 2.0 * 2.0) << "\n\n";

  auto f4 = [](double x) { return std::exp(x); };
  double derivative_exp = Calculus::differentiate(f4, 1.0);
  std::cout << "Derivative of exp(x) at x=1 = " << derivative_exp << "\n";
  std::cout << "Expected (exact): " << std::exp(1.0) << "\n\n";

  auto f5 = [](double x) { return std::cos(x); };
  double derivative_cos = Calculus::differentiate(f5, 0.0);
  std::cout << "Derivative of cos(x) at x=0 = " << derivative_cos << "\n";
  std::cout << "Expected (exact): 0.0\n\n";

  auto f6 = [](double x) { return x * x + 3.0 * x + 2.0; };
  double integral_quad = Calculus::integrate_1d(f6, 0.0, 5.0, 10000);
  std::cout << "Integral of x^2 + 3x + 2 from 0 to 5 = " << integral_quad << "\n";

  double derivative_quad = Calculus::differentiate(f6, 3.0);
  std::cout << "Derivative of x^2 + 3x + 2 at x=3 = " << derivative_quad << "\n";
  std::cout << "Expected (exact): " << (2.0 * 3.0 + 3.0) << "\n";

  return 0;
}
