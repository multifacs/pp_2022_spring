// Copyright 2022 Pichugin Ilya
#include "../../../modules/task_1/pichugin_i_sobel/operator_sobel.h"
#include <cmath>
#include <algorithm>

Sobel::Sobel() {
  mSize = 0;
  matrix = nullptr;
}

Sobel::~Sobel() {
  if (matrix) {
    delete[] matrix;
  }
}

Sobel::Sobel(int m_size) {
  mSize = m_size;
  matrix = new int[mSize * mSize];

  for (int i = 0; i < mSize * mSize; i++) {
    matrix[i] = 0;
  }
}

Sobel::Sobel(const Sobel& c) {
  mSize = c.mSize;
  matrix = new int[mSize * mSize];

  for (int i = 0; i < mSize * mSize; i++) {
    matrix[i] = c.matrix[i];
  }
}

Sobel Sobel::operator=(const Sobel& c) {
  mSize = c.mSize;
  matrix = new int[mSize * mSize];

  for (int i = 0; i < mSize * mSize; i++) {
    matrix[i] = c.matrix[i];
  }
  return *this;
}

Sobel Sobel::RandomMatrix(int m_size) {
  if (m_size <= 0) {
    throw -1;
  }
  Sobel sob_Class(m_size);
  int min = 0, max = 255;
  int* Matrix = new int[m_size];

  for (int i = 0; i < m_size; i++) {
    Matrix[i] = min + (std::rand() * ((max + 1) - min) / RAND_MAX);
    sob_Class.matrix[i] = Matrix[i];
  }

  delete[] Matrix;
  return sob_Class;
}

Sobel Sobel::operator_Sobel(Sobel c) {
  int _size = c.get_Size_Matrix();
  Sobel result(_size);
  _size--;

  int kern_x[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
  int kern_y[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};

  for (int i = 1; i < _size; i++) {
    for (int j = 1; j < _size; j++) {
      int x = 0, y = 0, ind = 0, min_pix = 0, max_pix = 255;

      for (int m_i = -1; m_i < 2; m_i++) {
        for (int m_j = -1; m_j < 2; m_j++) {
          x += kern_x[ind] * c.get_Matrix(i + m_i, j + m_j);
          y += kern_y[ind] * c.get_Matrix(i + m_i, j + m_j);
          ind++;
        }
      }

      double val = sqrt(x * x + y * y);
      int diap = val > max_pix ? max_pix : val < min_pix ? min_pix : val;
      result.set_Matrix(i, j, diap);
    }
  }
  return result;
}

int Sobel::get_Size_Matrix() { return mSize; }
int Sobel::get_Matrix(int i, int j) { return matrix[mSize * i + j]; }
void Sobel::set_Matrix(int i, int j, const int& val) {
  matrix[mSize * i + j] = val;
}
