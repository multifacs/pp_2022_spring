// Copyright 2022 Kitaev Pavel

#include <gtest/gtest.h>
#include <tbb/tbb.h>
#include <vector>
#include "../../../modules/task_3/kitaev_p_block_gauss/block_gauss.h"

TEST(Gauss, CanCreateRandomMatrix) {
  ASSERT_NO_THROW(getRandomMatrix(100, 100));
}

TEST(Gauss, CanCreateGaussKernel) {
  ASSERT_NO_THROW(getGaussKernel(10));
}

TEST(Gauss, CanSequentialAlg) {
  std::vector<int> mtr = getRandomMatrix(10, 10);
  std::vector<int> gauss_kernel = getGaussKernel(10);
  ASSERT_NO_THROW(SequentialGauss(mtr, gauss_kernel, 10, 10));
}

TEST(Gauss, CanParallelAld) {
  std::vector<int> mtr = getRandomMatrix(10, 10);
  std::vector<int> gauss_kernel = getGaussKernel(10);
  ASSERT_NO_THROW(ParallelGauss(mtr, gauss_kernel, 10, 10));
}

TEST(Gauss, test_10x10) {
  std::vector<int> mtr = getRandomMatrix(10, 10);
  std::vector<int> gauss_kernel = getGaussKernel(10);
  std::vector<int> res_sq = SequentialGauss(mtr, gauss_kernel, 10, 10);
  std::vector<int> res_pp = ParallelGauss(mtr, gauss_kernel, 10, 10);
  ASSERT_EQ(res_sq, res_pp);
}

TEST(Gauss, test_50x50) {
  std::vector<int> mtr = getRandomMatrix(50, 50);
  std::vector<int> gauss_kernel = getGaussKernel(10);
  std::vector<int> res_sq = SequentialGauss(mtr, gauss_kernel, 50, 50);
  std::vector<int> res_pp = ParallelGauss(mtr, gauss_kernel, 50, 50);
  ASSERT_EQ(res_sq, res_pp);
}

/*
TEST(Gauss, test_time) {
  std::vector<int> mtr = getRandomMatrix(5000, 5000);
  std::vector<int> gauss_kernel = getGaussKernel(10);

  tbb::tick_count seq_start = tbb::tick_count::now();
  std::vector<int> res_sq = SequentialGauss(mtr, gauss_kernel, 5000, 5000);
  tbb::tick_count seq_end = tbb::tick_count::now();

  double t_seq = (seq_end - seq_start).seconds();
  std::cout << "SEQ: " << t_seq << "\n";

  tbb::tick_count par_start = tbb::tick_count::now();
  std::vector<int> res_pp = ParallelGauss(mtr, gauss_kernel, 5000, 5000);
  tbb::tick_count par_end = tbb::tick_count::now();

  double t_par = (par_end - par_start).seconds();

  std::cout << "PAR: " << t_par << std::endl;

  ASSERT_EQ(res_sq, res_pp);
}
*/

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
