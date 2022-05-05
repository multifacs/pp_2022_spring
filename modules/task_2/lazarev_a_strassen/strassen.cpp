// Copyright 2022 Lazarev Aleksey

#include "../../../modules/task_2/lazarev_a_strassen/strassen.h"

#include <omp.h>

#include <random>

int** initializeMatrix(int n) {
  int** C = new int*[n];
  for (int i = 0; i < n; ++i) C[i] = new int[n];
  return C;
}

void setToZero(int** A, int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++) A[i][j] = 0;
}

void setToRandom(int** A, int n) {
  std::random_device dev;
  static std::mt19937 gen(dev());

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++) A[i][j] = gen() % 100;
}

int** multiply(int** A, int** B, int n) {
  int** C = initializeMatrix(n);
  setToZero(C, n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++) C[i][j] += A[i][k] * B[k][j];
  return C;
}

void cleanup(int** A, int n) {
  for (int i = 0; i < n; i++) {
    delete[] A[i];
  }
  delete[] A;
}

int** add(int** M1, int** M2, int n) {
  int** temp = initializeMatrix(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) temp[i][j] = M1[i][j] + M2[i][j];
  return temp;
}

int** subtract(int** M1, int** M2, int n) {
  int** temp = initializeMatrix(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) temp[i][j] = M1[i][j] - M2[i][j];
  return temp;
}

int** strassenMultiply(int** A, int** B, int n) {
  if (n <= threshold) {
    int** C = initializeMatrix(n);
    C = multiply(A, B, n);
    return C;
  }

  int** C = initializeMatrix(n);
  int k = n / 2;

  int** A11 = initializeMatrix(k);
  int** A12 = initializeMatrix(k);
  int** A21 = initializeMatrix(k);
  int** A22 = initializeMatrix(k);
  int** B11 = initializeMatrix(k);
  int** B12 = initializeMatrix(k);
  int** B21 = initializeMatrix(k);
  int** B22 = initializeMatrix(k);

  for (int i = 0; i < k; i++)
    for (int j = 0; j < k; j++) {
      A11[i][j] = A[i][j];
      A12[i][j] = A[i][k + j];
      A21[i][j] = A[k + i][j];
      A22[i][j] = A[k + i][k + j];
      B11[i][j] = B[i][j];
      B12[i][j] = B[i][k + j];
      B21[i][j] = B[k + i][j];
      B22[i][j] = B[k + i][k + j];
    }

  int **P1, **P2, **P3, **P4, **P5, **P6, **P7;

#pragma omp parallel sections
  {
#pragma omp section
    P1 = strassenMultiply(A11, subtract(B12, B22, k), k);
#pragma omp section
    P2 = strassenMultiply(add(A11, A12, k), B22, k);
#pragma omp section
    P3 = strassenMultiply(add(A21, A22, k), B11, k);
#pragma omp section
    P4 = strassenMultiply(A22, subtract(B21, B11, k), k);
#pragma omp section
    P5 = strassenMultiply(add(A11, A22, k), add(B11, B22, k), k);
#pragma omp section
    P6 = strassenMultiply(subtract(A12, A22, k), add(B21, B22, k), k);
#pragma omp section
    P7 = strassenMultiply(subtract(A11, A21, k), add(B11, B12, k), k);
  }

  int** C11 = subtract(add(add(P5, P4, k), P6, k), P2, k);
  int** C12 = add(P1, P2, k);
  int** C21 = add(P3, P4, k);
  int** C22 = subtract(subtract(add(P5, P1, k), P3, k), P7, k);

  for (int i = 0; i < k; i++)
    for (int j = 0; j < k; j++) {
      C[i][j] = C11[i][j];
      C[i][j + k] = C12[i][j];
      C[k + i][j] = C21[i][j];
      C[k + i][k + j] = C22[i][j];
    }

  cleanup(A11, k);
  cleanup(A12, k);
  cleanup(A21, k);
  cleanup(A22, k);
  cleanup(B11, k);
  cleanup(B12, k);
  cleanup(B21, k);
  cleanup(B22, k);
  cleanup(P1, k);
  cleanup(P2, k);
  cleanup(P3, k);
  cleanup(P4, k);
  cleanup(P5, k);
  cleanup(P6, k);
  cleanup(P7, k);
  cleanup(C11, k);
  cleanup(C12, k);
  cleanup(C21, k);
  cleanup(C22, k);

  return C;
}

int** strassenSeq(int** A, int** B, int n) {
  if (n <= threshold) {
    int** C = initializeMatrix(n);
    C = multiply(A, B, n);
    return C;
  }

  int** C = initializeMatrix(n);
  int k = n / 2;

  int** A11 = initializeMatrix(k);
  int** A12 = initializeMatrix(k);
  int** A21 = initializeMatrix(k);
  int** A22 = initializeMatrix(k);
  int** B11 = initializeMatrix(k);
  int** B12 = initializeMatrix(k);
  int** B21 = initializeMatrix(k);
  int** B22 = initializeMatrix(k);

  for (int i = 0; i < k; i++)
    for (int j = 0; j < k; j++) {
      A11[i][j] = A[i][j];
      A12[i][j] = A[i][k + j];
      A21[i][j] = A[k + i][j];
      A22[i][j] = A[k + i][k + j];
      B11[i][j] = B[i][j];
      B12[i][j] = B[i][k + j];
      B21[i][j] = B[k + i][j];
      B22[i][j] = B[k + i][k + j];
    }

  int** P1 = strassenMultiply(A11, subtract(B12, B22, k), k);
  int** P2 = strassenMultiply(add(A11, A12, k), B22, k);
  int** P3 = strassenMultiply(add(A21, A22, k), B11, k);
  int** P4 = strassenMultiply(A22, subtract(B21, B11, k), k);
  int** P5 = strassenMultiply(add(A11, A22, k), add(B11, B22, k), k);
  int** P6 = strassenMultiply(subtract(A12, A22, k), add(B21, B22, k), k);
  int** P7 = strassenMultiply(subtract(A11, A21, k), add(B11, B12, k), k);

  int** C11 = subtract(add(add(P5, P4, k), P6, k), P2, k);
  int** C12 = add(P1, P2, k);
  int** C21 = add(P3, P4, k);
  int** C22 = subtract(subtract(add(P5, P1, k), P3, k), P7, k);

  for (int i = 0; i < k; i++)
    for (int j = 0; j < k; j++) {
      C[i][j] = C11[i][j];
      C[i][j + k] = C12[i][j];
      C[k + i][j] = C21[i][j];
      C[k + i][k + j] = C22[i][j];
    }

  cleanup(A11, k);
  cleanup(A12, k);
  cleanup(A21, k);
  cleanup(A22, k);
  cleanup(B11, k);
  cleanup(B12, k);
  cleanup(B21, k);
  cleanup(B22, k);
  cleanup(P1, k);
  cleanup(P2, k);
  cleanup(P3, k);
  cleanup(P4, k);
  cleanup(P5, k);
  cleanup(P6, k);
  cleanup(P7, k);
  cleanup(C11, k);
  cleanup(C12, k);
  cleanup(C21, k);
  cleanup(C22, k);

  return C;
}
