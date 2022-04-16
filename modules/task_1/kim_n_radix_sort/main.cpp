// Copyright 2022 Kim Nikita
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include "./radix_sort.h"

TEST(Sequential, Vector_One_Size) {
  int size = 1;
  std::vector<int> input_vec = getRandomVector(size);
  std::vector<int> res = input_vec;

  radixSort(input_vec, size);

  ASSERT_EQ(res, input_vec);
}

TEST(Sequential, Vector_Two_Size) {
  int size = 2;
  std::vector<int> input_vec = getRandomVector(size);
  std::vector<int> res = input_vec;

  sort(res.begin(), res.end());
  radixSort(input_vec, size);

  ASSERT_EQ(res, input_vec);
}

TEST(Sequential, Vector_Odd_Size) {
  int size = 21;
  std::vector<int> input_vec = getRandomVector(size);
  std::vector<int> res = input_vec;

  sort(res.begin(), res.end());
  radixSort(input_vec, size);

  ASSERT_EQ(res, input_vec);
}

TEST(Sequential, Vector_Even_Size) {
  int size = 20;
  std::vector<int> input_vec = getRandomVector(size);
  std::vector<int> res = input_vec;

  sort(res.begin(), res.end());
  radixSort(input_vec, size);

  ASSERT_EQ(res, input_vec);
}

TEST(Sequential, Vector_Odd_Large_Size) {
  int size = 121;
  std::vector<int> input_vec = getRandomVector(size);
  std::vector<int> res = input_vec;

  sort(res.begin(), res.end());
  radixSort(input_vec, size);

  ASSERT_EQ(res, input_vec);
}

TEST(Sequential, Vector_Even_Large_Size) {
  int size = 120;
  std::vector<int> input_vec = getRandomVector(size);
  std::vector<int> res = input_vec;

  sort(res.begin(), res.end());
  radixSort(input_vec, size);

  ASSERT_EQ(res, input_vec);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
