// Copyright 2022 Myasnikova Varvara

#include <gtest/gtest.h>
#include <vector>
#include "../../../modules/task_4/myasnikova_gaussian_block_filtering/gaussian_block_filtering.h"

TEST(TBBGaussian, Creating_a_Matrix_small) {
  int row = 10, column = 10;
  ASSERT_NO_THROW(CreateMatrix(row, column));
}

TEST(TBBGaussian, Creating_a_Matrix_big) {
  int row = 100, column = 100;
  ASSERT_NO_THROW(CreateMatrix(row, column));
}

TEST(TBBGaussian, Creating_a_Kernel_1) {
  ASSERT_NO_THROW(CreateKernel(1));
}

TEST(TBBGaussian, Creating_a_Kernel_2) {
  ASSERT_NO_THROW(CreateKernel(5));
}

TEST(TBBGaussian, Creating_a_Kernel_3) {
  ASSERT_NO_THROW(CreateKernel(10));
}

TEST(TBBGaussian, GaussFilterSeq) {
  int row = 10, column = 10;
  std::vector<int> matrix = CreateMatrix(row, column);
  std::vector<int> kernel = CreateKernel(5);
  ASSERT_NO_THROW(GaussFilterSeq(matrix, kernel, row, column));
}

TEST(TBBGaussian, GaussFilterParallel) {
  int row = 10, column = 10;
  std::vector<int> matrix = CreateMatrix(row, column);
  std::vector<int> kernel = CreateKernel(5);
  ASSERT_NO_THROW(GaussFilterParallel(matrix, kernel, row, column));
}

TEST(TBBGaussian, GaussFilterParallelAndSeq1) {
  int row = 3000, column = 3000;
  std::vector<int> matrix = CreateMatrix(row, column);
  std::vector<int> kernel = CreateKernel(5);

  double t1_seq = clock();
  std::vector<int> seq_res = GaussFilterSeq(matrix, kernel, row, column);
  double t2_seq = clock();

  double t1_pp = clock();
  std::vector<int> parallel_res =
    GaussFilterParallel(matrix, kernel, row, column);
  double t2_pp = clock();

  std::cout << "1000 x 1000\n";
  std::cout << "SQ TIME: " << static_cast<float>(t2_seq - t1_seq) / CLOCKS_PER_SEC << std::endl;
  std::cout << "PP TIME: " << static_cast<float>(t2_pp - t1_pp) / CLOCKS_PER_SEC << std::endl;
  ASSERT_EQ(seq_res, parallel_res);
}

TEST(TBBGaussian, GaussFilterParallelAndSeq2) {
  int row = 6000, column = 6000;
  std::vector<int> matrix = CreateMatrix(row, column);
  std::vector<int> kernel = CreateKernel(5);

  double t1_seq = clock();
  std::vector<int> seq_res = GaussFilterSeq(matrix, kernel, row, column);
  double t2_seq = clock();

  double t1_pp = clock();
  std::vector<int> parallel_res =
    GaussFilterParallel(matrix, kernel, row, column);
  double t2_pp = clock();

  std::cout << "1000 x 1000\n";
  std::cout << "SQ TIME: " << static_cast<float>(t2_seq - t1_seq) / CLOCKS_PER_SEC << std::endl;
  std::cout << "PP TIME: " << static_cast<float>(t2_pp - t1_pp) / CLOCKS_PER_SEC << std::endl;
  ASSERT_EQ(seq_res, parallel_res);
}

TEST(TBBGaussian, GaussFilterParallelAndSeq3) {
  int row = 8000, column = 8000;
  std::vector<int> matrix = CreateMatrix(row, column);
  std::vector<int> kernel = CreateKernel(5);

  double t1_seq = clock();
  std::vector<int> seq_res = GaussFilterSeq(matrix, kernel, row, column);
  double t2_seq = clock();

  double t1_pp = clock();
  std::vector<int> parallel_res =
    GaussFilterParallel(matrix, kernel, row, column);
  double t2_pp = clock();

  std::cout << "1000 x 1000\n";
  std::cout << "SQ TIME: " << static_cast<float>(t2_seq - t1_seq) / CLOCKS_PER_SEC << std::endl;
  std::cout << "PP TIME: " << static_cast<float>(t2_pp - t1_pp) / CLOCKS_PER_SEC << std::endl;
  ASSERT_EQ(seq_res, parallel_res);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
