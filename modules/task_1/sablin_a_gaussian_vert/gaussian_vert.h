// Copyright 2022 Sablin Alexandr
#ifndef MODULES_TASK_1_SABLIN_A_GAUSSIAN_VERT_GAUSSIAN_VERT_H_
#define MODULES_TASK_1_SABLIN_A_GAUSSIAN_VERT_GAUSSIAN_VERT_H_

#include <vector>
#include <random>
#include <iostream>

struct rgb_coub {
    int red, green, blue;
};
std::vector<rgb_coub> getRandomImage(size_t rows, size_t columns);
std::vector<rgb_coub> Gaussian_Filter_Seq(const std::vector<rgb_coub>& img,
    size_t rows, size_t columns, const double sigma);

#endif  // MODULES_TASK_1_SABLIN_A_GAUSSIAN_VERT_GAUSSIAN_VERT_H_
