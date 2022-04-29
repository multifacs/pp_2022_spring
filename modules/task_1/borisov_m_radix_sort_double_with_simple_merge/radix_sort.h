// Copyright 2022 Borisov Maxim

#ifndef MODULES_TASK_1_BORISOV_M_RADIX_SORT_DOUBLE_WITH_SIMPLE_MERGE_RADIX_SORT_H_
#define MODULES_TASK_1_BORISOV_M_RADIX_SORT_DOUBLE_WITH_SIMPLE_MERGE_RADIX_SORT_H_

#include <algorithm>
#include <random>
#include <utility>
#include <vector>

std::vector<double> random_vec(int size);
std::vector<double> merge(const std::vector<double>& lhs,
                          const std::vector<double>& rhs);

void count_sort(double* in, double* out, int len, int exp);
std::vector<double> radix_sort(const std::vector<double>& data);

#endif  // MODULES_TASK_1_BORISOV_M_RADIX_SORT_DOUBLE_WITH_SIMPLE_MERGE_RADIX_SORT_H_
