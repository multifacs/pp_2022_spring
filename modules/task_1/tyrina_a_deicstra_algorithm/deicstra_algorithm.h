// Copyright 2022 Tyrina Anastasia
#ifndef MODULES_TASK_1_TYRINA_A_DEICSTRA_ALGORITHM_DEICSTRA_ALGORITHM_H_
#define MODULES_TASK_1_TYRINA_A_DEICSTRA_ALGORITHM_DEICSTRA_ALGORITHM_H_

#include <string>
#include <vector>

std::vector<std::vector<int>> getRandomVector(const size_t count);

std::vector<int> getDeicstra(const std::vector<std::vector<int>>& graf,
                             const size_t count, const size_t top);
std::vector<int> getSeqDeicstra(const std::vector<std::vector<int>>& graf,
                                const size_t count);

#endif  // MODULES_TASK_1_TYRINA_A_DEICSTRA_ALGORITHM_DEICSTRA_ALGORITHM_H_
