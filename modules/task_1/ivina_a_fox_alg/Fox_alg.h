// Copyright 2022 Ivina Anastasiya
#ifndef MODULES_TASK_1_IVINA_A_FOX_ALG_FOX_ALG_H_
#define MODULES_TASK_1_IVINA_A_FOX_ALG_FOX_ALG_H_

#include <vector>

using Matrix = std::vector<std::vector<double>>;
using MatrixRow = std::vector<double>;

Matrix FillMatrixRandom(const Matrix &matrix);
void PrintMatrix(const Matrix &Matrix);
Matrix DenseMatrixMultiplication(const Matrix &a, const Matrix &b);
Matrix BlockMatrixMultiplication(const Matrix &a, const Matrix &b);

#endif  // MODULES_TASK_1_IVINA_A_FOX_ALG_FOX_ALG_H_

