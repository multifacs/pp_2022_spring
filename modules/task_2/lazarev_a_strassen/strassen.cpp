// Copyright 2022 Lazarev Aleksey

#include "../../../modules/task_1/lazarev_a_strassen/strassen.h"

#include <omp.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>

matrix generateMatrix(int n) {
  matrix C = std::vector<vec>(n, vec(n, 0));

  std::random_device dev;
  static std::mt19937 gen(dev());

  for (int row = 0; row < n; row++) {
    vec data(n);
    std::generate(data.begin(), data.end(), []() { return gen() % 100; });

    C[row] = data;
  }

  return C;
}

void matrixMultiplication(const matrix& A, const matrix& B, matrix* C) {
  int n = static_cast<int>(A.size());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      (*C)[i][j] = 0;
      for (int t = 0; t < n; t++) {
        (*C)[i][j] = (*C)[i][j] + A[i][t] * B[t][j];
      }
    }
  }
}

void matrixMultiplicationSimple(const matrix& A, const matrix& B, matrix* C) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      (*C)[i][j] = 0;
      for (int t = 0; t < 2; t++) {
        (*C)[i][j] = (*C)[i][j] + A[i][t] * B[t][j];
      }
    }
  }
}

void matrixAdd(int n, const matrix& A, const matrix& B, matrix* C) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      (*C)[i][j] = A[i][j] + B[i][j];
    }
  }
}

void matrixSub(int n, const matrix& A, const matrix& B, matrix* C) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      (*C)[i][j] = A[i][j] - B[i][j];
    }
  }
}

void Strassen(int n, const matrix& A, const matrix& B, matrix* C) {
  matrix A11 = std::vector<vec>(n / 2, vec(n / 2, 0)),
         A12 = std::vector<vec>(n / 2, vec(n / 2, 0)),
         A21 = std::vector<vec>(n / 2, vec(n / 2, 0)),
         A22 = std::vector<vec>(n / 2, vec(n / 2, 0));
  matrix B11 = std::vector<vec>(n / 2, vec(n / 2, 0)),
         B12 = std::vector<vec>(n / 2, vec(n / 2, 0)),
         B21 = std::vector<vec>(n / 2, vec(n / 2, 0)),
         B22 = std::vector<vec>(n / 2, vec(n / 2, 0));
  matrix C11 = std::vector<vec>(n / 2, vec(n / 2, 0)),
         C12 = std::vector<vec>(n / 2, vec(n / 2, 0)),
         C21 = std::vector<vec>(n / 2, vec(n / 2, 0)),
         C22 = std::vector<vec>(n / 2, vec(n / 2, 0));
  matrix M1 = std::vector<vec>(n / 2, vec(n / 2, 0)),
         M2 = std::vector<vec>(n / 2, vec(n / 2, 0)),
         M3 = std::vector<vec>(n / 2, vec(n / 2, 0)),
         M4 = std::vector<vec>(n / 2, vec(n / 2, 0)),
         M5 = std::vector<vec>(n / 2, vec(n / 2, 0)),
         M6 = std::vector<vec>(n / 2, vec(n / 2, 0)),
         M7 = std::vector<vec>(n / 2, vec(n / 2, 0));

  if (n == 2) {
    matrixMultiplicationSimple(A, B, C);
  } else {
    for (int i = 0; i < n / 2; i++) {
      for (int j = 0; j < n / 2; j++) {
        A11[i][j] = A[i][j];
        A12[i][j] = A[i][j + n / 2];
        A21[i][j] = A[i + n / 2][j];
        A22[i][j] = A[i + n / 2][j + n / 2];

        B11[i][j] = B[i][j];
        B12[i][j] = B[i][j + n / 2];
        B21[i][j] = B[i + n / 2][j];
        B22[i][j] = B[i + n / 2][j + n / 2];
      }
    }

#pragma omp parallel sections shared(A11, A12, A21, A22, B11, B12, B21, B22)
    {
#pragma omp section
      {
        matrix AA = std::vector<vec>(n / 2, vec(n / 2, 0)),
               BB = std::vector<vec>(n / 2, vec(n / 2, 0));

        // Calculate M1 = (A0 + A3) * (B0 + B3)
        matrixAdd(n / 2, A11, A22, &AA);
        matrixAdd(n / 2, B11, B22, &BB);
        Strassen(n / 2, AA, BB, &M1);
      }

#pragma omp section
      {
        matrix AA = std::vector<vec>(n / 2, vec(n / 2, 0));
        // Calculate M2 = (A2 + A3) * B0
        matrixAdd(n / 2, A21, A22, &AA);
        Strassen(n / 2, AA, B11, &M2);
      }

#pragma omp section
      {
        matrix BB = std::vector<vec>(n / 2, vec(n / 2, 0));
        // Calculate M3 = A0 * (B1 - B3)
        matrixSub(n / 2, B12, B22, &BB);
        Strassen(n / 2, A11, BB, &M3);
      }

#pragma omp section
      {
        matrix BB = std::vector<vec>(n / 2, vec(n / 2, 0));
        // Calculate M4 = A3 * (B2 - B0)
        matrixSub(n / 2, B21, B11, &BB);
        Strassen(n / 2, A22, BB, &M4);
      }

#pragma omp section
      {
        matrix AA = std::vector<vec>(n / 2, vec(n / 2, 0));
        // Calculate M5 = (A0 + A1) * B3
        matrixAdd(n / 2, A11, A12, &AA);
        Strassen(n / 2, AA, B22, &M5);
      }

#pragma omp section
      {
        matrix AA = std::vector<vec>(n / 2, vec(n / 2, 0)),
               BB = std::vector<vec>(n / 2, vec(n / 2, 0));
        // Calculate M6 = (A2 - A0) * (B0 + B1)
        matrixSub(n / 2, A21, A11, &AA);
        matrixAdd(n / 2, B11, B12, &BB);
        Strassen(n / 2, AA, BB, &M6);
      }

#pragma omp section
      {
        matrix AA = std::vector<vec>(n / 2, vec(n / 2, 0)),
               BB = std::vector<vec>(n / 2, vec(n / 2, 0));
        // Calculate M7 = (A1 - A3) * (B2 + B3)
        matrixSub(n / 2, A12, A22, &AA);
        matrixAdd(n / 2, B21, B22, &BB);
        Strassen(n / 2, AA, BB, &M7);
      }
    }

    matrix AA = std::vector<vec>(n / 2, vec(n / 2, 0)),
           BB = std::vector<vec>(n / 2, vec(n / 2, 0));

    // Calculate C0 = M1 + M4 - M5 + M7
    matrixAdd(n / 2, M1, M4, &AA);
    matrixSub(n / 2, M7, M5, &BB);
    matrixAdd(n / 2, AA, BB, &C11);

    // Calculate C1 = M3 + M5
    matrixAdd(n / 2, M3, M5, &C12);

    // Calculate C2 = M2 + M4
    matrixAdd(n / 2, M2, M4, &C21);

    // Calculate C3 = M1 - M2 + M3 + M6
    matrixSub(n / 2, M1, M2, &AA);
    matrixAdd(n / 2, M3, M6, &BB);
    matrixAdd(n / 2, AA, BB, &C22);

    // Set the result to C[][N]
    for (int i = 0; i < n / 2; i++) {
      for (int j = 0; j < n / 2; j++) {
        (*C)[i][j] = C11[i][j];
        (*C)[i][j + n / 2] = C12[i][j];
        (*C)[i + n / 2][j] = C21[i][j];
        (*C)[i + n / 2][j + n / 2] = C22[i][j];
      }
    }
  }
}

void print(const std::string& title, const matrix& A) {
  std::cout << title << '\n';

  int m = A.size(), n = A[0].size();
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      double x = A[i][j];
      std::cout << x << ' ';
    }
    std::cout << '\n';
  }
}
