// Copyright 2022 Uglinskii Bogdan
#include <gtest/gtest.h>

#include <iostream>
#include <vector>

#include "./crs_multiplication.h"
#include "tbb/tick_count.h"

TEST(Multiplication_seq, crs_50x50_30) {
  MatrixCRS matrix_A = GenerateRandomMatrixCRS(50, 50, 30);
  MatrixCRS matrix_B = GenerateRandomMatrixCRS(50, 50, 30);

  MatrixCRS matrix_C;
  CRSMultiply(matrix_A, matrix_B, &matrix_C);

  std::vector<std::vector<double>> C;

  NormalMulty(ExpandMatrix(matrix_A), ExpandMatrix(matrix_B), &C);
  MatrixCRS crs_C;
  ConvertToCRS(C, &crs_C);
  ASSERT_TRUE(CompareMatrixCRS(matrix_C, crs_C));
}

TEST(Multiplication_parallel, 3x3_4) {
  tbb::tick_count t1, t2, t1_, t2_;

  MatrixCRS matrix_A = GenerateRandomMatrixCRS(3, 3, 4);
  MatrixCRS matrix_B = GenerateRandomMatrixCRS(3, 3, 4);

  MatrixCRS matrix_C;
  t1 = tbb::tick_count::now();
  CRSMultiply(matrix_A, matrix_B, &matrix_C);
  t2 = tbb::tick_count::now();

  MatrixCRS C_tbb;
  t1_ = tbb::tick_count::now();
  CRSMultiplyTBB(matrix_A, matrix_B, &C_tbb);
  t2_ = tbb::tick_count::now();
  std::cout << "NO TBB time = " << (t2 - t1).seconds()
            << "\nTBB time = " << (t2_ - t1_).seconds() << "\nAcceleration = "
            << (t2 - t1).seconds() / (t2_ - t1_).seconds() << "\n";
  ASSERT_TRUE(CompareMatrixCRS(matrix_C, C_tbb));
}

TEST(Multiplication_parallel, 50x50_30) {
  tbb::tick_count t1, t2, t1_, t2_;

  MatrixCRS matrix_A = GenerateRandomMatrixCRS(50, 50, 30);
  MatrixCRS matrix_B = GenerateRandomMatrixCRS(50, 50, 30);

  MatrixCRS matrix_C;
  t1 = tbb::tick_count::now();
  CRSMultiply(matrix_A, matrix_B, &matrix_C);
  t2 = tbb::tick_count::now();

  MatrixCRS C_tbb;
  t1_ = tbb::tick_count::now();
  CRSMultiplyTBB(matrix_A, matrix_B, &C_tbb);
  t2_ = tbb::tick_count::now();
  std::cout << "NO TBB time = " << (t2 - t1).seconds()
            << "\nTBB time = " << (t2_ - t1_).seconds() << "\nAcceleration = "
            << (t2 - t1).seconds() / (t2_ - t1_).seconds() << "\n";
  ASSERT_TRUE(CompareMatrixCRS(matrix_C, C_tbb));
}

TEST(Multiplication_parallel, 200x200_350) {
  tbb::tick_count t1, t2, t1_, t2_;

  MatrixCRS matrix_A = GenerateRandomMatrixCRS(200, 200, 350);
  MatrixCRS matrix_B = GenerateRandomMatrixCRS(200, 200, 350);

  MatrixCRS matrix_C;
  t1 = tbb::tick_count::now();
  CRSMultiply(matrix_A, matrix_B, &matrix_C);
  t2 = tbb::tick_count::now();

  MatrixCRS C_tbb;
  t1_ = tbb::tick_count::now();
  CRSMultiplyTBB(matrix_A, matrix_B, &C_tbb);
  t2_ = tbb::tick_count::now();
  std::cout << "NO TBB time = " << (t2 - t1).seconds()
            << "\nTBB time = " << (t2_ - t1_).seconds() << "\nAcceleration = "
            << (t2 - t1).seconds() / (t2_ - t1_).seconds() << "\n";
  ASSERT_TRUE(CompareMatrixCRS(matrix_C, C_tbb));
}

TEST(Multiplication_parallel, 250x250_400) {
  tbb::tick_count t1, t2, t1_, t2_;

  MatrixCRS matrix_A = GenerateRandomMatrixCRS(250, 250, 400);
  MatrixCRS matrix_B = GenerateRandomMatrixCRS(250, 250, 400);

  MatrixCRS matrix_C;
  t1 = tbb::tick_count::now();
  CRSMultiply(matrix_A, matrix_B, &matrix_C);
  t2 = tbb::tick_count::now();

  MatrixCRS C_tbb;
  t1_ = tbb::tick_count::now();
  CRSMultiplyTBB(matrix_A, matrix_B, &C_tbb);
  t2_ = tbb::tick_count::now();
  std::cout << "NO TBB time = " << (t2 - t1).seconds()
            << "\nTBB time = " << (t2_ - t1_).seconds() << "\nAcceleration = "
            << (t2 - t1).seconds() / (t2_ - t1_).seconds() << "\n";
  ASSERT_TRUE(CompareMatrixCRS(matrix_C, C_tbb));
}

TEST(Multiplication_parallel, 300x300_2000) {
  tbb::tick_count t1, t2, t1_, t2_;

  MatrixCRS matrix_A = GenerateRandomMatrixCRS(300, 300, 2000);
  MatrixCRS matrix_B = GenerateRandomMatrixCRS(300, 300, 2000);

  MatrixCRS matrix_C;
  t1 = tbb::tick_count::now();
  CRSMultiply(matrix_A, matrix_B, &matrix_C);
  t2 = tbb::tick_count::now();

  MatrixCRS C_tbb;
  t1_ = tbb::tick_count::now();
  CRSMultiplyTBB(matrix_A, matrix_B, &C_tbb);
  t2_ = tbb::tick_count::now();
  std::cout << "NO TBB time = " << (t2 - t1).seconds()
            << "\nTBB time = " << (t2_ - t1_).seconds() << "\nAcceleration = "
            << (t2 - t1).seconds() / (t2_ - t1_).seconds() << "\n";
  ASSERT_TRUE(CompareMatrixCRS(matrix_C, C_tbb));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}