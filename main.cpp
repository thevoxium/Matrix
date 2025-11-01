#include "math/integrate.hpp"
#include <cmath>
#include <iostream>

double myFunc(double x) { return std::sin(x); }

int main() {
  double result1 =
      integrate_1d(myFunc, 0, M_PI, 1000); // integrates sin(x) from 0 to π

  std::cout << "Result 1: " << result1 << "\n";
}
