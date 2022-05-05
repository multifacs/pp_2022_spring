// Copyright 2022 Lazarev Aleksey
#include <gtest/gtest.h>
#include <omp.h>

#include "./strassen.h"

TEST(STRASSEN_OMP, TEST_1) {
  int n = 2;

  int** A = initializeMatrix(n);
  int** B = initializeMatrix(n);

  setToRandom(A, n);
  setToRandom(B, n);

  int **C1, **C2;

  C1 = multiply(A, B, n);
  C2 = strassenMultiply(A, B, n);

  for (int i = 0; i < n; i++) {
    ASSERT_EQ(C1[i][0], C2[i][0]);
  }
}

TEST(STRASSEN_OMP, TEST_2) {
  int n = 4;

  int** A = initializeMatrix(n);
  int** B = initializeMatrix(n);

  setToRandom(A, n);
  setToRandom(B, n);

  int **C1, **C2;

  C1 = multiply(A, B, n);
  C2 = strassenMultiply(A, B, n);

  for (int i = 0; i < n; i++) {
    ASSERT_EQ(C1[i][0], C2[i][0]);
  }
}

TEST(STRASSEN_OMP, TEST_3) {
  int n = 8;

  int** A = initializeMatrix(n);
  int** B = initializeMatrix(n);

  setToRandom(A, n);
  setToRandom(B, n);

  int **C1, **C2;

  C1 = multiply(A, B, n);
  C2 = strassenMultiply(A, B, n);

  for (int i = 0; i < n; i++) {
    ASSERT_EQ(C1[i][0], C2[i][0]);
  }
}

TEST(STRASSEN_OMP, TEST_4) {
  int n = 16;

  int** A = initializeMatrix(n);
  int** B = initializeMatrix(n);

  setToRandom(A, n);
  setToRandom(B, n);

  int **C1, **C2;

  C1 = multiply(A, B, n);
  C2 = strassenMultiply(A, B, n);

  for (int i = 0; i < n; i++) {
    ASSERT_EQ(C1[i][0], C2[i][0]);
  }
}

TEST(STRASSEN_OMP, TEST_5) {
  int n = 20;

  int** A = initializeMatrix(n);
  int** B = initializeMatrix(n);

  setToRandom(A, n);
  setToRandom(B, n);

  int **C1, **C2;

  C1 = multiply(A, B, n);
  C2 = strassenMultiply(A, B, n);

  for (int i = 0; i < n; i++) {
    ASSERT_EQ(C1[i][0], C2[i][0]);
  }
}
