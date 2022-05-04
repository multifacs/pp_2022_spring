// Copyright 2022 Gleb "belgad" Danshin
#include "integral_rectangle.hpp"

#include <tbb/tbb.h>

double Integrate(size_t dim, double* step, double* lower, double* upper, Function func, size_t thread_num) {
  double result = 0;
  int total = 1;
  auto size = new int[dim];
  for (size_t k = 0; k < dim; ++k)
    total *= size[k] = static_cast<int>((upper[k] - lower[k]) / step[k]);
  tbb::task_scheduler_init init{thread_num ? static_cast<int>(thread_num) : -1};
  result = tbb::parallel_reduce(tbb::blocked_range<int>(0, total), 0.0,
    [&](tbb::blocked_range<int> range, double temp){
      auto curr_point = new double[dim];
      int j;
      for (int i = range.begin(); i < range.end(); ++i) {
        j = i;
        for (size_t k = 0; k < dim; ++k) {
          curr_point[k] = lower[k] + static_cast<double>(j % size[k]) * step[k];
          j /= size[k];
        }
        temp += func(curr_point);
      }
      return temp;
    }, std::plus<double>());
  for (size_t k = 0; k < dim; ++k) {
    result *= step[k];
  }
  delete[] size;
  return result;
}
