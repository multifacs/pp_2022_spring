// Copyright 2022 Nazarov Nikita
#ifndef MODULES_TASK_3_NAZAROV_N_SIMPSON_SIMPSON_H_
#define MODULES_TASK_3_NAZAROV_N_SIMPSON_SIMPSON_H_

#include <cmath>
#include <functional>
#include <vector>
#include <algorithm>
#include <utility>

double simpson(double (*func)(const std::vector<double>&), const std::vector<std::pair<double, double>>& borders, const std::vector<int>& steps);


#endif  // MODULES_TASK_3_NAZAROV_N_SIMPSON_SIMPSON_H_