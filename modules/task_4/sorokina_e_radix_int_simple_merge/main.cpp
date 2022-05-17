// Copyright 2022 Sorokina Ekaterina
#include <gtest/gtest.h>

#include "./radix_int_simple_merge.h"
#include "../../../3rdparty/unapproved/unapproved.h"

void measureTime(INT_VEC* vec1, INT_VEC* vec2, int parts, bool parallel, bool parallel_merge) {
  auto start = clock();
  radixSortSimpleMerge(vec1, parts, false);
  auto end = clock();
  double seq_time = (static_cast<float>(start - end) / CLOCKS_PER_SEC);

  start = clock();
  radixSortSimpleMerge(vec2, parts, parallel, parallel_merge);
  end = clock();
  double par_time = (static_cast<float>(start - end) / CLOCKS_PER_SEC);

  std::cout << "seq: " << seq_time << "\n";
  std::cout << "par: " << par_time << "\n";
  std::cout << "speed: " << seq_time / par_time << "\n\n";
}

TEST(RADIX_INT_SIMPLE_MERGE_STD, TEST_1) {
  int n = 10;
  int parts = 3;
  INT_VEC vec = getRandomVec(n);
  radixSortSimpleMerge(&vec, parts);
  // printVec(vec);
  ASSERT_TRUE(checkOrder(vec));
}

TEST(RADIX_INT_SIMPLE_MERGE_STD, TEST_2) {
  int n = 11;
  int parts = 11;
  INT_VEC vec = getRandomVec(n);
  radixSortSimpleMerge(&vec, parts);
  // printVec(vec);
  ASSERT_TRUE(checkOrder(vec));
}

TEST(RADIX_INT_SIMPLE_MERGE_STD, TEST_3) {
  int n = 12;
  int parts = 3;
  INT_VEC vec = getRandomVec(n);
  radixSortSimpleMerge(&vec, parts);
  // printVec(vec);
  ASSERT_TRUE(checkOrder(vec));
}

TEST(RADIX_INT_SIMPLE_MERGE_STD, TEST_4) {
  int n = 13;
  int parts = 3;
  INT_VEC vec = getRandomVec(n);
  radixSortSimpleMerge(&vec, parts);
  // printVec(vec);
  ASSERT_TRUE(checkOrder(vec));
}

TEST(RADIX_INT_SIMPLE_MERGE_STD, TEST_PARALLEL_SORT_SEQ_MERGE) {
  int runs = 1;
  int n = 10;
  int parts = std::thread::hardware_concurrency();
  for (int i = 0; i < runs; i++) {
    std::cout << "n: " << n << "\n";
    std::cout << "parts: " << parts << "\n";
    INT_VEC vec1 = getRandomVec(n);
    INT_VEC vec2(vec1);

    measureTime(&vec1, &vec2, parts, true, false);
    n *= 30;
    // parts += 10;
  }
}

TEST(RADIX_INT_SIMPLE_MERGE_STD, TEST_PARALLEL_SORT_PARALLEL_MERGE) {
  int runs = 1;
  int n = 10;
  int parts = std::thread::hardware_concurrency();
  for (int i = 0; i < runs; i++) {
    std::cout << "n: " << n << "\n";
    std::cout << "parts: " << parts << "\n";
    INT_VEC vec1 = getRandomVec(n);
    INT_VEC vec2(vec1);

    measureTime(&vec1, &vec2, parts, true, true);
    n *= 30;
    // parts += 10;
  }
}
