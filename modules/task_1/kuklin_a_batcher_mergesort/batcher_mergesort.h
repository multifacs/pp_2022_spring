// Copyright 2022 Kuklin Andrey
#ifndef MODULES_TASK_1_KUKLIN_A_BATCHER_MERGESORT_BATCHER_MERGESORT_H_
#define MODULES_TASK_1_KUKLIN_A_BATCHER_MERGESORT_BATCHER_MERGESORT_H_

#include <vector>

using vector_d = std::vector<double>;

std::vector<double> getRandVec(size_t sz, double lower_bound,
                               double upper_bound);
std::vector<vector_d> genDigitCounters(vector_d* source_vec, size_t elem_num);
void radixPass(vector_d* source_vec, const std::vector<vector_d>& digitCounters);
void floatRadixSort(vector_d* source_vec);

#endif  // MODULES_TASK_1_KUKLIN_A_BATCHER_MERGESORT_BATCHER_MERGESORT_H_
