// Copyright 2022 Nazarov Nikita
#include "../../../modules/task_1/nazarov_n_simpson/simpson.h"

double simpson(double (*func)(const std::vector<double>&),
               const std::vector<std::pair<double, double>>& borders,
               const std::vector<int>& steps) {
  int iteration = 1;
  int dimensions = steps.size();
  double integral_simpson = 0;
  std::vector<double> h(dimensions);
  int a = std::pow(6, dimensions);
  std::vector<std::vector<double>> parameters(dimensions,
                                              std::vector<double>(6));
  std::vector<double> argument(dimensions);

  for (int i = 0; i < dimensions; i++) {
    h[i] = (borders[i].second - borders[i].first) / steps[i];
    iteration *= steps[i];
  }

  for (int i = 0, x = i; i < iteration; i++, x = i) {
    for (int dim = 0; dim < dimensions; dim++) {
      parameters[dim][0] = borders[dim].first + (x % steps[dim]) * h[dim];
      parameters[dim][1] =
          borders[dim].first + (x % steps[dim]) * h[dim] + h[dim] / 2;
      parameters[dim][2] = parameters[dim][1];
      parameters[dim][3] = parameters[dim][1];
      parameters[dim][4] = parameters[dim][1];
      parameters[dim][5] = parameters[dim][0] + h[dim];
      x /= steps[dim];
    }
    for (int i = 0, x = i; i < a; i++, x = i) {
      for (int dim = 0; dim < dimensions; dim++) {
        argument[dim] = parameters[dim][x % 6];
        x /= 6;
      }
      integral_simpson += func(argument);
    }
  }

  for (int i = 0; i < dimensions; i++) {
    integral_simpson *= h[i] / 6.0;
  }

  return integral_simpson;
}
