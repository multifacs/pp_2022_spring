// Copyright 2022 Tyrina Anastasia
#ifndef MODULES_TASK_2_TYRINA_A_DEICSTRA_ALGORITHM_DEICSTRA_ALGORITHM_H_
#define MODULES_TASK_2_TYRINA_A_DEICSTRA_ALGORITHM_DEICSTRA_ALGORITHM_H_

#include <string>
#include <vector>

std::vector<std::vector<int>> getRandomVector(const int count);

std::vector<int> getDeicstra(const std::vector<std::vector<int>>& graf,
                             const int count, const int top);
std::vector<int> getOMPDeicstra(const std::vector<std::vector<int>>& graf,
                                const int count);

#endif  // MODULES_TASK_2_TYRINA_A_DEICSTRA_ALGORITHM_DEICSTRA_ALGORITHM_H_
