#include "math/calculus.hpp"
#include <cmath>
#include <iostream>

double myFunc(double x) { return std::sin(x); }

int main() {
  double result1 = Math::integrate_1d(myFunc, 0, M_PI,
                                      1000); // integrates sin(x) from 0 to π
  auto f2 = [](double x) { return std::sin(x); };

  std::cout << "Result 1: " << result1 << "\n";
  std::cout << "f'(π/3) for sin(x) = "
            << Math::differentiate(f2, 3.1415926535 / 3) << "\n";
}
