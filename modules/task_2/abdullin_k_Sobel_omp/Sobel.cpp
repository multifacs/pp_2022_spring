// Copyright 2022 Abdullin Konstantin
#include <omp.h>
#include <iostream>
#include "../../../modules/task_2/abdullin_k_Sobel_omp/Sobel.h"

int Kernel[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
int radius = 1, size = 3;

std::vector<int> InitRandMatrix(int height, int width) {
  if (height <= 0 || width <= 0)
    throw "Size of matrix error!";
  std::mt19937 gen;
  gen.seed(static_cast<int>(time(0)));
  std::vector<int> result(height * width);
  for (int i = 0; i < height * width; i++)
    result[i] = gen() % 256;
  return result;
}

int Index(int x, int y, int width) {
  int result = y * width + x;
  return result;
}

int CalculatePixelValue(std::vector<int> source,
  int height, int width, int x, int y) {
  int pixel = 0;
  for (int i = -radius; i <= radius; i++)
    for (int j = -radius; j <= radius; j++) {
      int idx = (i + radius) * size + (j + radius);
      int index = Index(clamp(x + j, width - 1, 0),
        clamp(y + i, height - 1, 0), width);
      pixel += Kernel[idx] * source[index];
    }
  return clamp(pixel, 255, 0);
}

std::vector<int> SequentialSobelFilter(std::vector<int> source,
  int height, int width) {
  std::vector<int> result(height * width);

  for (int y = 0; y < height; y++)
    for (int x = 0; x < width; x++)
      result[Index(x, y, width)] = CalculatePixelValue(
        source, height, width, x, y);

  return result;
}

std::vector<int> ParallelSobelFilter(std::vector<int> source,
  int height, int width, int num_threads) {
  omp_set_num_threads(num_threads);
  std::vector<std::pair <int, std::vector<int>>> pre_result;
  std::vector<int> result;
  int part_size = (height * width) / num_threads;
  int shift = (height * width) % num_threads;
  std::vector<int> part;
#pragma omp parallel shared(source, shift) private(part)
  {
    int thread_id = omp_get_thread_num();
    if (thread_id == 0) {
      part.resize(part_size + shift);
      std::copy(source.begin(), source.begin() + part_size + shift,
        part.begin());
    } else {
      part.resize(part_size);
    }
    for (int i = 1; i < num_threads; i++) {
      if (thread_id == i) {
        std::copy(source.begin() + part_size * i + shift, source.end() -
          part_size * (num_threads - i - 1), part.begin());
      }
    }
    for (int i = 0; i < part.size(); i++) {
      int x, y;
      if (thread_id > 0) {
        x = (thread_id * part_size + shift + i) % width;
        y = (thread_id * part_size + shift + i) / width;
      } else {
        x = i % width; y = i / width;
      }
      part[i] = CalculatePixelValue(source, height, width, x, y);
    }
    pre_result.push_back({thread_id, part});
  }
  for (int i = 0; i < num_threads; i++) {
    for (int j = 0; j < num_threads; j++) {
      if (i == pre_result[j].first) {
        result.insert(result.end(), pre_result[j].second.begin(),
          pre_result[j].second.end());
        break;
      }
    }
  }
  return result;
}
