// Copyright 2022 Kim Nikita
#ifndef MODULES_TASK_1_KIM_N_RADIX_SORT_RADIX_SORT_H_
#define MODULES_TASK_1_KIM_N_RADIX_SORT_RADIX_SORT_H_

#include <vector>

std::vector<int> getRandomVector(int size);

int getMax(std::vector<int> input_vec, int size);

void countSort(std::vector<int>& input_vec, int size, int place);

void radixSort(std::vector<int>& input_vec, int size);

#endif  // MODULES_TASK_1_KIM_N_RADIX_SORT_RADIX_SORT_H_
