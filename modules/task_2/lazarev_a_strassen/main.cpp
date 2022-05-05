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

  int **C1 = nullptr, **C2 = nullptr;

  C1 = multiply(A, B, n);
  C2 = strassenMultiply(A, B, n);

  for (int i = 0; i < n; i++) {
    ASSERT_EQ(C1[i][0], C2[i][0]);
  }

  cleanup(A, n);
  cleanup(B, n);
  cleanup(C1, n);
  cleanup(C2, n);
}

TEST(STRASSEN_OMP, TEST_2) {
  int n = 4;

  int** A = initializeMatrix(n);
  int** B = initializeMatrix(n);

  setToRandom(A, n);
  setToRandom(B, n);

  int **C1 = nullptr, **C2 = nullptr;

  C1 = multiply(A, B, n);
  C2 = strassenMultiply(A, B, n);

  for (int i = 0; i < n; i++) {
    ASSERT_EQ(C1[i][0], C2[i][0]);
  }

  cleanup(A, n);
  cleanup(B, n);
  cleanup(C1, n);
  cleanup(C2, n);
}

TEST(STRASSEN_OMP, TEST_3) {
  int n = 8;

  int** A = initializeMatrix(n);
  int** B = initializeMatrix(n);

  setToRandom(A, n);
  setToRandom(B, n);

  int **C1 = nullptr, **C2 = nullptr;

  C1 = multiply(A, B, n);
  C2 = strassenMultiply(A, B, n);

  for (int i = 0; i < n; i++) {
    ASSERT_EQ(C1[i][0], C2[i][0]);
  }

  cleanup(A, n);
  cleanup(B, n);
  cleanup(C1, n);
  cleanup(C2, n);
}

TEST(STRASSEN_OMP, TEST_4) {
  int n = 16;

  int** A = initializeMatrix(n);
  int** B = initializeMatrix(n);

  setToRandom(A, n);
  setToRandom(B, n);

  int **C1 = nullptr, **C2 = nullptr;

  C1 = multiply(A, B, n);
  C2 = strassenMultiply(A, B, n);

  for (int i = 0; i < n; i++) {
    ASSERT_EQ(C1[i][0], C2[i][0]);
  }

  cleanup(A, n);
  cleanup(B, n);
  cleanup(C1, n);
  cleanup(C2, n);
}

TEST(STRASSEN_OMP, TEST_5) {
  int n = 256;

  int** A = initializeMatrix(n);
  int** B = initializeMatrix(n);

  setToRandom(A, n);
  setToRandom(B, n);

  int** C = nullptr;

  double time1 = omp_get_wtime();
  C = multiply(A, B, n);
  double time2 = omp_get_wtime();
  double native = time2 - time1;
  std::cout << "native: " << native << std::endl;

  time1 = omp_get_wtime();
  C = strassenSeq(A, B, n);
  time2 = omp_get_wtime();
  double seq_time = time2 - time1;
  std::cout << "strassen seq: " << seq_time << std::endl;

  time1 = omp_get_wtime();
  C = strassenMultiply(A, B, n);
  time2 = omp_get_wtime();
  double parallel_time = time2 - time1;
  std::cout << "strassen par: " << parallel_time << std::endl;

  std::cout << "times: " << seq_time / parallel_time << std::endl;

  cleanup(A, n);
  cleanup(B, n);
  cleanup(C, n);
}
