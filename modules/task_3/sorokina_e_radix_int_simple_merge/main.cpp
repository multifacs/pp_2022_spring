// Copyright 2022 Sorokina Ekaterina
#include <gtest/gtest.h>
#include <omp.h>

#include "./radix_int_simple_merge.h"

void measureTime(INT_VEC* vec1, INT_VEC* vec2, int parts, bool parallel, bool parallel_merge) {
  double start = omp_get_wtime();
  radixSortSimpleMerge(vec1, parts, false);
  double end = omp_get_wtime();
  double seq_time = end - start;

  start = omp_get_wtime();
  radixSortSimpleMerge(vec2, parts, parallel, parallel_merge);
  end = omp_get_wtime();
  double par_time = end - start;

  std::cout << "seq: " << seq_time << "\n";
  std::cout << "par: " << par_time << "\n";
  std::cout << "speed: " << seq_time / par_time << "\n\n";
}

TEST(RADIX_INT_SIMPLE_MERGE_TBB, TEST_1) {
  int n = 10;
  int parts = 3;
  INT_VEC vec = getRandomVec(n);
  radixSortSimpleMerge(&vec, parts);
  // printVec(vec);
  ASSERT_TRUE(checkOrder(vec));
}

TEST(RADIX_INT_SIMPLE_MERGE_TBB, TEST_2) {
  int n = 11;
  int parts = 11;
  INT_VEC vec = getRandomVec(n);
  radixSortSimpleMerge(&vec, parts);
  // printVec(vec);
  ASSERT_TRUE(checkOrder(vec));
}

TEST(RADIX_INT_SIMPLE_MERGE_TBB, TEST_3) {
  int n = 12;
  int parts = 3;
  INT_VEC vec = getRandomVec(n);
  radixSortSimpleMerge(&vec, parts);
  // printVec(vec);
  ASSERT_TRUE(checkOrder(vec));
}

TEST(RADIX_INT_SIMPLE_MERGE_TBB, TEST_4) {
  int n = 13;
  int parts = 3;
  INT_VEC vec = getRandomVec(n);
  radixSortSimpleMerge(&vec, parts);
  // printVec(vec);
  ASSERT_TRUE(checkOrder(vec));
}

TEST(RADIX_INT_SIMPLE_MERGE_TBB, TEST_PARALLEL_SORT_SEQ_MERGE) {
  int runs = 4;
  int n = 1000;
  int parts = omp_get_max_threads();
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

TEST(RADIX_INT_SIMPLE_MERGE_TBB, TEST_PARALLEL_SORT_PARALLEL_MERGE) {
  int runs = 4;
  int n = 1000;
  int parts = omp_get_max_threads();
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
