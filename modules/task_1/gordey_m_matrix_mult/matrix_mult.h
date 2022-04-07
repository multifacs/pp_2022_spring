// Copyright 2022 Gordey Maria
#ifndef MODULES_TASK_1_GORDEY_M_MATRIX_MULT_MATRIX_MULT_H_
#define MODULES_TASK_1_GORDEY_M_MATRIX_MULT_MATRIX_MULT_H_

#include <complex>
#include <ctime>
#include <random>
#include <vector>

struct SparseMatrix {
  int rows, cols;
  std::vector<int> col_idx;
  std::vector<int> row;
  std::vector<int> value;

  SparseMatrix() : rows(0), cols(0){};
  SparseMatrix(int _rows, int _cols) : rows(_rows), cols(_cols) {}
  SparseMatrix(int _rows, int _cols, const std::vector<int>& _col_idx,
               const std::vector<int>& _row, const std::vector<int>& _value)
      : rows(_rows), cols(_cols), col_idx(_col_idx), row(_row), value(_value) {}
  SparseMatrix(int _rows, int _cols, std::vector<int> matrix);
  SparseMatrix transpose();
};

SparseMatrix Multiplication(SparseMatrix A, SparseMatrix B);

#endif  // MODULES_TASK_1_GORDEY_M_MATRIX_MULT_MATRIX_MULT_H_