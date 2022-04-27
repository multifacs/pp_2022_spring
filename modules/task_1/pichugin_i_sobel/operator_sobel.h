#ifndef MODULES_TASK_1_PICHUGIN_I_SOBEL_OPERATOR_SOBEL_H_
#define MODULES_TASK_1_PICHUGIN_I_SOBEL_OPERATOR_SOBEL_H_

// Copyright 2022 Pichugin Ilya
#include <iostream>

class Sobel {
 private:
  int* matrix;
  int mSize;

 public:
  Sobel();
  explicit Sobel(int m_size);
  Sobel(const Sobel& c);
  ~Sobel();

  Sobel operator=(const Sobel& c);
  Sobel RandomMatrix(int m_size);
  Sobel operator_Sobel(Sobel c);

  int get_Size_Matrix();
  int get_Matrix(int i, int j);
  void set_Matrix(int i, int j, const int& val);
};
#endif  // MODULES_TASK_1_PICHUGIN_I_SOBEL_OPERATOR_SOBEL_H_
