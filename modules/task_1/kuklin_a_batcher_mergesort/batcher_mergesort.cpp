// Copyright 2022 Kuklin Andrey
#include "../../../modules/task_1/kuklin_a_batcher_mergesort/batcher_mergesort.h"
#include <algorithm>
#include <vector>
#include <random>

using vector_d = std::vector<double>;

vector_d getRandVec(size_t sz, double lower_bound, double upper_bound) {
  vector_d vec(sz);
  std::uniform_real_distribution<double> distribution(lower_bound, upper_bound);
  std::random_device device;
  std::mt19937 rnd(device());

  for (size_t i = 0; i < sz; ++i) vec[i] = distribution(rnd);

  return vec;
}

std::vector<vector_d> genDigitCounters(vector_d* source_vec, size_t elem_num) {
  std::vector<vector_d> digitCounters(256);
  int j = 0;
  int curr_byte = 0;
  size_t local_size = 0;

  for (size_t byte_num = 0; byte_num < sizeof(double); ++byte_num) {
    for (size_t elem_ind = 0; elem_ind < elem_num; ++elem_ind) {
      curr_byte = static_cast<int>(
          *((unsigned char*)&(*source_vec)[elem_ind] + byte_num));
      digitCounters[curr_byte].push_back((*source_vec)[elem_ind]);
    }

    for (size_t i = 0; i < 256; ++i) {
      if (!digitCounters.empty()) {
        local_size = digitCounters[i].size();
        for (size_t k = 0; k < local_size; ++k) {
          (*source_vec)[j] = digitCounters[i][k];
          ++j;
        }
        digitCounters[i].clear();
      }
    }
    j = 0;
  }

  return digitCounters;
}

void radixPass(vector_d* source_vec, const std::vector<vector_d>& digitCounters) {
  size_t size;
  size_t j = 0;

  for (size_t i = 255; i >= 128; --i) {
    if (!digitCounters[i].empty()) {
      size = digitCounters[i].size();
      for (size_t k = size - 1; k >= 1; --k) {
        (*source_vec)[j] = digitCounters[i][k];
        j++;
      }
      (*source_vec)[j] = digitCounters[i][0];
      j++;
    }
  }

  for (size_t i = 0; i < 128; ++i) {
    if (!digitCounters[i].empty()) {
      size = digitCounters[i].size();
      for (size_t k = 0; k < size; ++k) {
        (*source_vec)[j] = digitCounters[i][k];
        j++;
      }
    }
  }
}

void floatRadixSort(vector_d* source_vec) {
  size_t elem_num = source_vec->size();

  auto digitCounters = genDigitCounters(source_vec, elem_num);

  int tmp = 0;
  for (size_t i = 0; i < elem_num; i++) {
    tmp = static_cast<int>(*((unsigned char*)&(*source_vec)[i] + 7));
    digitCounters[tmp].push_back((*source_vec)[i]);
  }

  radixPass(source_vec, digitCounters);
}
