// Copyright 2018 Nesterov Alexander
#ifndef MODULES_TASK_1_ZOTOV_M_SORT_WITH_BATCHER_MERGE_SORT_WITH_BATCHER_MERGE_H_
#define MODULES_TASK_1_ZOTOV_M_SORT_WITH_BATCHER_MERGE_SORT_WITH_BATCHER_MERGE_H_

#include <vector>
#include <string>

std::vector<int> getRandomVector(int  sz);
int GetMaxPower(std::vector<int> data);
void RadixSort(std::vector<int>* main_data, int size, int offset);

#endif  // MODULES_TASK_1_ZOTOV_M_SORT_WITH_BATCHER_MERGE_SORT_WITH_BATCHER_MERGE_H_
