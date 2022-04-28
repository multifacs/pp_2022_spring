// Copyright 2022 Lazarev Aleksey
#ifndef MODULES_TASK_2_LAZAREV_A_STRASSEN_STRASSEN_H_
#define MODULES_TASK_2_LAZAREV_A_STRASSEN_STRASSEN_H_

#include <array>
#include <string>
#include <vector>

using vec = std::vector<double>;
using matrix = std::vector<vec>;

matrix generateMatrix(int n);

void matrixMultiplication(const matrix& A, const matrix& B, matrix* C);
void Strassen(int n, const matrix& A, const matrix& B, matrix* C);
void print(const std::string& title, const matrix& A);

#endif  // MODULES_TASK_2_LAZAREV_A_STRASSEN_STRASSEN_H_
