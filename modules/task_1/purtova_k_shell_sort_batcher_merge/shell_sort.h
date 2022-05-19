// Copyright 2022 Purtova Ksenia 
#ifndef MODULES_TASK_1_PURTOVA_K_SHELL_SORT_BATCHER_MERGE_SHELL_SORT_H_
#define MODULES_TASK_1_PURTOVA_K_SHELL_SORT_BATCHER_MERGE_SHELL_SORT_H_

#include <vector> 

void Shell(std::vector<int>& A, int n);
std::vector <int> MergerEvenOdd(std::vector<int>& arr1, std::vector<int>& arr2, int i1, int i2);
std::vector<int> BatcherEvenNumber(std::vector<int>& arr1, std::vector<int>& arr2);
std::vector<int> BatcherOddNumber(std::vector<int>& arr1, std::vector<int>& arr2);
std::vector<int> BatcherMerger(std::vector<int>& arr1, std::vector<int>& arr2);
std::vector<int> ShellWithBatcher(std::vector<int>& A, int n);
std::vector<int> VectorRandomizer(int size);
#endif // MODULES_TASK_1_PURTOVA_K_SHELL_SORT_BATCHER_MERGE_SHELL_SORT_H_