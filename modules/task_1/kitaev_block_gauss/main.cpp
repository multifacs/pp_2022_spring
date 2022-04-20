// Copyright 2022 Kitaev Pavel

#include <gtest/gtest.h>
#include <vector>
#include "./block_gauss.h"

TEST(Sequential_gauss, CanCreateRandomMatrix) {
  ASSERT_NO_THROW(getRandomMatrix(100, 100));
}

TEST(Sequential_gauss, CanCreateGaussKernel) {
  ASSERT_NO_THROW(getGaussKernel(10));
}

TEST(Sequential_gauss, test_10x10) {
  std::vector<int> mtr = getRandomMatrix(10, 10);
  ASSERT_NO_THROW(SequentialGauss(mtr, 10, 10, 10));
}

TEST(Sequential_gauss, test_100x100) {
  std::vector<int> mtr = getRandomMatrix(100, 100);
  ASSERT_NO_THROW(SequentialGauss(mtr, 100, 100, 10));
}

TEST(Sequential_gauss, test_1000x1000) {
  std::vector<int> mtr = getRandomMatrix(1000, 1000);
  ASSERT_NO_THROW(SequentialGauss(mtr, 1000, 1000, 10));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
