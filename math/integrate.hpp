#pragma once
#include <omp.h>

template <typename F> double integrate_1d(F f, double a, double b, int n) {
  double h = (b - a) / n;
  double sum = 0.0;

#pragma omp parallel for reduction(+ : sum)
  for (int i = 0; i < n; i++) {
    double x = a + i * h;
    double fx = f(x);
    sum += (i == 0 || i == n) ? fx / 2.0 : fx;
  }
  return sum * h;
}
