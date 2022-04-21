// Copyright 2022 Gleb "belgad" Danshin
#include "../../../modules/task_1/danshin_g_integral_rectangle/integral_rectangle.hpp"

double Integrate(size_t dim, double* step, double* lower, double* upper, Function func) {
  double result = 0;
  // auto curr_point = new double[dim];
  // size_t total = 1;
  // for (int k = 0; k < dim; ++k) {
  //   curr_point[k] = lower[k];
  //   total *= static_cast<size_t>((upper[k] - lower[k]) / step[k]);
  // }
  // for (;total--;) {
  //   result += func(curr_point);
  //   for (size_t k = 0; k < dim; ++k) {
  //     curr_point[k] += step[k];
  //     if (curr_point[k] >= upper[k]) {
  //       curr_point[k] = lower[k];
  //     } else {
  //       break;
  //     }
  //   }
  // }
  size_t total = 1;
  auto size = new size_t[dim];
  for (int k = 0; k < dim; ++k) {
    total *= size[k] = static_cast<size_t>((upper[k] - lower[k]) / step[k]);
  }
  auto curr_point = new double[dim];
  size_t j;
  for (int i = 0; i < total; ++i) {
    j = i;
    for (int k = 0; k < dim; ++k) {
      curr_point[k] = lower[k] + static_cast<double>(j % size[k]) * step[k];
        j /= size[k];
    }
    result += func(curr_point);
  }
  delete[] curr_point;
  for (size_t k = 0; k < dim; ++k) {
    result *= step[k];
  }
  return result;
}
