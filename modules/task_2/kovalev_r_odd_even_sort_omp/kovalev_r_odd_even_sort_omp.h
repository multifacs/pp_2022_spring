// Copyright 2022 Kovalev Ruslan
#ifndef MODULES_TEST_TASKS_TEST_OMP_OPS_OMP_H_
#define MODULES_TEST_TASKS_TEST_OMP_OPS_OMP_H_

#include <string>
#include <vector>

bool check(std::vector<int>* arr_1, std::vector<int>* arr_2, int sz);
void vec_gen(std::vector<int>* vec, int len);
void copy_vectors(std::vector<int>* arr_1, std::vector<int>* arr_2, int sz);
void getSequantialSort(std::vector<int>* arr, int sz);
std::vector<int> getParallelSort(const std::vector<int>& commonVector);

#endif  // MODULES_TEST_TASKS_TEST_OMP_OPS_OMP_H_
