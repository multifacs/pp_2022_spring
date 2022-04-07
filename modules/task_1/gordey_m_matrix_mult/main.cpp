// Copyright 2022 Gordey Maria
#include <gtest/gtest.h>

#include "../../../modules/task_1/gordey_m_matrix_mult/matrix_mult.h"

TEST(SPARSE_MATRIX_MULT_SEQ, CREATE_MATRIX) {
  std::vector<int> a = {0, 3, 0, 7, 0, 0, 5, 0, 8, 0, 0, 0, 0, 0, 14, 16};
  SparseMatrix SMatrix(4, 4, a);
  std::vector<int> row1 = {2, 0, 1, 3, 0, 3};
  std::vector<int> colidx = {0, 1, 2, 4, 6};
  std::vector<int> val = {8, 3, 5, 14, 7, 16};
  ASSERT_EQ(SMatrix.value, val);
  ASSERT_EQ(SMatrix.row, row1);
  ASSERT_EQ(SMatrix.col_idx, colidx);
}

TEST(SPARSE_MATRIX_MULT_SEQ, TRANSPOSE) {
  std::vector<int> a = {0, 3, 0, 7, 0, 0, 8, 0, 0, 0, 0, 0, 9, 0, 15, 16};
  SparseMatrix SMatrix(4, 4, a);
  SparseMatrix SMatrixT = SMatrix.transpose();
  std::vector<int> row1 = {1, 3, 2, 0, 2, 3};
  std::vector<int> colidx = {0, 2, 3, 3, 6};
  std::vector<int> val = {3, 7, 8, 9, 15, 16};
  ASSERT_EQ(SMatrixT.value, val);
  ASSERT_EQ(SMatrixT.row, row1);
  ASSERT_EQ(SMatrixT.col_idx, colidx);
}

TEST(SPARSE_MATRIX_MULT_SEQ, MULT_1) {
  std::vector<int> a = {1, 0, 0, 2};
  SparseMatrix A(2, 2, a);
  std::vector<int> b = {0, 0, 0, 0};
  SparseMatrix B(2, 2, b);
  SparseMatrix result = Multiplication(A, B);
  std::vector<int> res = {};
  ASSERT_EQ(res, result.value);
}

TEST(SPARSE_MATRIX_MULT_SEQ, MULT_2) {
  std::vector<int> a = {1, 0, 0, 2};
  SparseMatrix A(2, 2, a);
  std::vector<int> b = {7, 5, 0, 0};
  SparseMatrix B(2, 2, b);
  SparseMatrix result = Multiplication(A, B);
  std::vector<int> res = {7, 5};
  ASSERT_EQ(res, result.value);
}

TEST(SPARSE_MATRIX_MULT_SEQ, MULT_3) {
  std::vector<int> a = {0, 12, 0, 1, 0, 5, 0, 4, 7};
  SparseMatrix A(3, 3, a);
  std::vector<int> b = {3, 0, 9, 0, 2, 0, 0, 0, 1};
  SparseMatrix B(3, 3, b);
  SparseMatrix result = Multiplication(A, B);
  std::vector<int> res = {3, 24, 8, 14, 7};
  ASSERT_EQ(res, result.value);
}

TEST(SPARSE_MATRIX_MULT_SEQ, MULT_4) {
  std::vector<int> a = {0, 12, 0, 1, 0, 5, 0, 4, 7};
  SparseMatrix A(3, 3, a);
  std::vector<int> b = {3, 0, 9, 0, 2, 0, 0, 0, 1};
  SparseMatrix B(3, 3, b);
  SparseMatrix result = Multiplication(A, B);
  std::vector<int> res = {3, 24, 8, 14, 7};
  ASSERT_EQ(res, result.value);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
