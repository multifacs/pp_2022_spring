// Copyright 2022 Lazarev Aleksey
#include <gtest/gtest.h>

#include "./strassen.h"

TEST(STRASSEN_SEQ, TEST_1) {
  int n = 2;

  matrix A = generateMatrix(n);
  matrix B = generateMatrix(n);

  print("A", A);
  print("B", B);

  matrix C = std::vector<vec>(n, vec(n, 0));
  ASSERT_NO_THROW(Strassen(n, A, B, &C));

  print("C", C);

  matrix C_ref = std::vector<vec>(n, vec(n, 0));
  matrixMultiplication(A, B, &C_ref);

  for (int i = 0; i < n; i++) {
    ASSERT_TRUE(C[i] == C_ref[i]);
  }
}

TEST(STRASSEN_SEQ, TEST_2) {
  int n = 4;

  matrix A = generateMatrix(n);
  matrix B = generateMatrix(n);

  matrix C = std::vector<vec>(n, vec(n, 0));
  ASSERT_NO_THROW(Strassen(n, A, B, &C));

  matrix C_ref = std::vector<vec>(n, vec(n, 0));
  matrixMultiplication(A, B, &C_ref);

  for (int i = 0; i < n; i++) {
    ASSERT_TRUE(C[i] == C_ref[i]);
  }
}

TEST(STRASSEN_SEQ, TEST_3) {
  int n = 4;

  matrix A = generateMatrix(n);
  matrix B = generateMatrix(n);

  matrix C = std::vector<vec>(n, vec(n, 0));
  ASSERT_NO_THROW(Strassen(n, A, B, &C));

  matrix C_ref = std::vector<vec>(n, vec(n, 0));
  matrixMultiplication(A, B, &C_ref);

  for (int i = 0; i < n; i++) {
    ASSERT_TRUE(C[i] == C_ref[i]);
  }
}

TEST(STRASSEN_SEQ, TEST_4) {
  int n = 8;

  matrix A = generateMatrix(n);
  matrix B = generateMatrix(n);

  matrix C = std::vector<vec>(n, vec(n, 0));
  ASSERT_NO_THROW(Strassen(n, A, B, &C));

  matrix C_ref = std::vector<vec>(n, vec(n, 0));
  matrixMultiplication(A, B, &C_ref);

  for (int i = 0; i < n; i++) {
    ASSERT_TRUE(C[i] == C_ref[i]);
  }
}

TEST(STRASSEN_SEQ, TEST_5) {
  int n = 16;

  matrix A = generateMatrix(n);
  matrix B = generateMatrix(n);

  matrix C = std::vector<vec>(n, vec(n, 0));
  ASSERT_NO_THROW(Strassen(n, A, B, &C));
}

// TEST(STRASSEN_SEQ, TEST_6) {
//  int n = 256;
//
//  matrix A = generateMatrix(n);
//  matrix B = generateMatrix(n);
//
//  matrix C = std::vector<vec>(n, vec(n, 0));
//  ASSERT_NO_THROW(matrixMultiplication(A, B, &C));
//}
