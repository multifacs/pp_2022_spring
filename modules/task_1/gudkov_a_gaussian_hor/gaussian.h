// Copyright 2022 Gudkov Andrey
#ifndef MODULES_TASK_1_GUDKOV_A_GAUSSIAN_HOR_GAUSSIAN_H_
#define MODULES_TASK_1_GUDKOV_A_GAUSSIAN_HOR_GAUSSIAN_H_
#include <cstdint>
#include <vector>

struct Pixel {
    uint8_t r, g, b;
    Pixel() = default;
    ~Pixel() = default;
};
using Image = std::vector <Pixel>;

bool operator==(const Pixel &a, const Pixel &b);

Image generateRandomImage(int rows, int cols);
Image gaussianFilter(const Image &a, int rows, int cols);

#endif  // MODULES_TASK_1_GUDKOV_A_GAUSSIAN_HOR_GAUSSIAN_H_
