// Copyright 2022 Fedoseyev Mikhail
#include <gtest/gtest.h>

#include "./shell_sort.h"

TEST(SHELL_SORT_OMP, TEST_1) {
  int size = 10;
  int* a = generate_vector(size);
  print_list(a, size);
  shell_sort(a, size);
  print_list(a, size);
  ASSERT_EQ(check_list(a, size), 0);
  delete[] a;
}

TEST(SHELL_SORT_OMP, TEST_2) {
  int size = 20;
  int* a = generate_vector(size);
  shell_sort(a, size);
  ASSERT_EQ(check_list(a, size), 0);
  delete[] a;
}

TEST(SHELL_SORT_OMP, TEST_3) {
  int size = 30;
  int* a = generate_vector(size);
  shell_sort(a, size);
  ASSERT_EQ(check_list(a, size), 0);
  delete[] a;
}

const int big_size = 1000;

TEST(SHELL_SORT_OMP, SIZE_BIG) {
  int* b = generate_vector(big_size);
  shell_sort(b, big_size);
  ASSERT_EQ(check_list(b, big_size), 0);
  delete[] b;
}

TEST(SHELL_SORT_OMP, TEST_SEQ) {
  int* a = generate_vector(big_size);
  shell_sort(a, big_size, false);
  ASSERT_EQ(check_list(a, big_size), 0);
  delete[] a;
}
