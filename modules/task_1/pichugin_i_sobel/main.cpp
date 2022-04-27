// Copyright 2022 Pichugin Ilya
#include "../../../modules/task_1/pichugin_i_sobel/operator_sobel.h"
#include "gtest/gtest.h"

TEST(TEST_SOBOL, SIZE_MATR_10) {
  Sobel s1, s2;
  s1.RandomMatrix(10);
  ASSERT_NO_FATAL_FAILURE(s2.operator_Sobel(s1));
}
TEST(TEST_SOBOL, SIZE_MATR_50) {
  Sobel s1, s2;
  s1.RandomMatrix(50);
  ASSERT_NO_FATAL_FAILURE(s2.operator_Sobel(s1));
}
TEST(TEST_SOBOL, SIZE_MATR_100) {
  Sobel s1, s2;
  s1.RandomMatrix(100);
  ASSERT_NO_FATAL_FAILURE(s2.operator_Sobel(s1));
}
TEST(TEST_SOBOL, SIZE_MATR_150) {
  Sobel s1, s2;
  s1.RandomMatrix(150);
  ASSERT_NO_FATAL_FAILURE(s2.operator_Sobel(s1));
}
TEST(TEST_SOBOL, SIZE_MATR_200) {
  Sobel s1, s2;
  s1.RandomMatrix(200);
  ASSERT_NO_FATAL_FAILURE(s2.operator_Sobel(s1));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
