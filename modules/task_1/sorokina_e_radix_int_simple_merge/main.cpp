// Copyright 2022 Sorokina Ekaterina
#include <gtest/gtest.h>

#include "./radix_int_simple_merge.h"

TEST(RADIX_INT_SIMPLE_MERGE_SEQ, TEST_1) {
  int n = 10;
  int parts = 3;
  INT_VEC vec = getRandomVec(n);
  radixSortSimpleMerge(&vec, parts);
  // printVec(vec);
  ASSERT_TRUE(checkOrder(vec));
}

TEST(RADIX_INT_SIMPLE_MERGE_SEQ, TEST_2) {
  int n = 11;
  int parts = 11;
  INT_VEC vec = getRandomVec(n);
  radixSortSimpleMerge(&vec, parts);
  // printVec(vec);
  ASSERT_TRUE(checkOrder(vec));
}

TEST(RADIX_INT_SIMPLE_MERGE_SEQ, TEST_3) {
  int n = 12;
  int parts = 3;
  INT_VEC vec = getRandomVec(n);
  radixSortSimpleMerge(&vec, parts);
  // printVec(vec);
  ASSERT_TRUE(checkOrder(vec));
}

TEST(RADIX_INT_SIMPLE_MERGE_SEQ, TEST_4) {
  int n = 13;
  int parts = 3;
  INT_VEC vec = getRandomVec(n);
  radixSortSimpleMerge(&vec, parts);
  // printVec(vec);
  ASSERT_TRUE(checkOrder(vec));
}

TEST(RADIX_INT_SIMPLE_MERGE_SEQ, TEST_5) {
  int n = 15;
  int parts = 16;
  INT_VEC vec = getRandomVec(n);
  radixSortSimpleMerge(&vec, parts);
  // printVec(vec);
  ASSERT_TRUE(checkOrder(vec));
}
