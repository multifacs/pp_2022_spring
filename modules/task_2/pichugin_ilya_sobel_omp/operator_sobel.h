// Copyright 2022 Pichugin Ilya
#ifndef MODULES_TASK_2_PICHUGIN_ILYA_SOBEL_OMP_OPERATOR_SOBEL_H_
#define MODULES_TASK_2_PICHUGIN_ILYA_SOBEL_OMP_OPERATOR_SOBEL_H_

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
  Sobel operator_Sobel_parr(Sobel c);

  int get_Size_Matrix();
  int get_Matrix(int i, int j);
  void set_Matrix(int i, int j, int val);
};
#endif  // MODULES_TASK_2_PICHUGIN_ILYA_SOBEL_OMP_OPERATOR_SOBEL_H_
