// Copyright 2022 Gordey Maria
#include "../../../modules/task_1/gordey_m_matrix_mult/matrix_mult.h"

SparseMatrix::SparseMatrix(int _rows, int _cols, std::vector<int> matrix) {
  rows = _rows;
  cols = _cols;
  int non_zero = 0;
  col_idx.push_back(0);
  for (int j = 0; j < _cols; j++) {
    for (int i = 0; i < _rows; i++) {
      if (matrix[cols * i + j] != 0) {
        non_zero++;
        value.push_back(matrix[cols * i + j]);
        row.push_back(i);
      }
    }
    col_idx.push_back(non_zero);
  }
}

SparseMatrix SparseMatrix::transpose() {
  std::vector<int> valueT(value.size());
  std::vector<int> col_idxT(col_idx.size());
  std::vector<int> rowT(row.size());
  int size = row.size();
  for (int i = 0; i < size; i++) {
    col_idxT[row[i] + 1]++;
  }
  int tmp, index, r;
  int s = 0;
  for (int i = 1; i <= rows; i++) {
    tmp = col_idxT[i];
    col_idxT[i] = s;
    s += tmp;
  }
  for (int i = 0; i < cols; i++) {
    for (int j = col_idx[i]; j < col_idx[i + 1]; ++j) {
      r = row[j];
      index = col_idxT[r + 1];
      rowT[index] = i;
      valueT[index] = value[j];
      col_idxT[r + 1]++;
    }
  }
  SparseMatrix res = SparseMatrix(rows, cols, col_idxT, rowT, valueT);
  return res;
}

SparseMatrix Multiplication(SparseMatrix A, SparseMatrix B) {
  SparseMatrix result;
  A.transpose();
  int non_zero = 0;
  std::vector<int> tmp(A.rows, 0);
  result.col_idx.push_back(0);
  for (int j = 0; j < B.cols; j++) {
    for (int k = B.col_idx[j]; k < B.col_idx[j + 1];
         k++) {  // get column from matrix B
      non_zero = B.row[k];
      for (int i = A.col_idx[non_zero];
           i < A.col_idx[non_zero + 1];  // get column from matrix A
           i++) {
        tmp[A.row[i]] += B.value[k] * A.value[i];  // multiply
      }
    }
    for (int c = 0; c < A.rows; c++) {
      if (tmp[c] != 0) {
        result.row.push_back(c);
        result.value.push_back(tmp[c]);
        tmp[c] = 0;
      }
    }
    result.col_idx.push_back(result.value.size());
  }
  return result;
}
