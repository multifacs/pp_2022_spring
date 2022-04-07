// Copyright 2022 Ermakov Pavel
#ifndef MODULES_TASK_1_ERMAKOV_P_GRACKHAM_GRACKHAM_H_
#define MODULES_TASK_1_ERMAKOV_P_GRACKHAM_GRACKHAM_H_

#include "gtest/gtest.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>

std::vector<std::pair<int, int>> gen_dots(int vectorSize);
int rotation(const std::pair<int, int>& dot1,
const std::pair<int, int>& dot2, const std::pair<int, int>& dot3);
bool distance(const std::pair<int, int>& dot1, const std::pair<int, int>& dot2);
std::vector<std::pair<int, int>> greckham_seq(std::vector<std::pair<int, int>> vec);

#endif // MODULES_TASK_1_ERMAKOV_P_GRACKHAM_GRACKHAM_H_
