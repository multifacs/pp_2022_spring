// Copyright 2022 Lazarev Aleksey
#ifndef MODULES_TASK_1_LAZAREV_A_STRASSEN_STRASSEN_H_
#define MODULES_TASK_1_LAZAREV_A_STRASSEN_STRASSEN_H_

#include <string>
#include <vector>
#include <array>

using vec = std::vector<double>;
using matrix = std::vector<vec>;

matrix generateMatrix(int n);

void matrixMultiplication(const matrix& A, const matrix& B, matrix* C);
void Strassen(int n, const matrix& A, const matrix& B, matrix* C);
void print(const std::string& title, const matrix& A);

#endif  // MODULES_TASK_1_LAZAREV_A_STRASSEN_STRASSEN_H_
