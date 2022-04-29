// Copyright 2022 Pichugin Ilya
#include <omp.h>

#include "../../../modules/task_2/pichugin_ilya_sobel_omp/operator_sobel.h"
#include "gtest/gtest.h"

TEST(TEST_SOBOL, SIZE_MATR_500_OMP) {
  double time1, time2;
  Sobel s1, s2, rand, t_1, t_2;
  rand = rand.RandomMatrix(500);

  time1 = omp_get_wtime();
  s1.operator_Sobel(rand);
  time2 = omp_get_wtime();
  t_1 = time2 - time1;

  time1 = omp_get_wtime();
  s2.operator_Sobel_parr(rand);
  time2 = omp_get_wtime();
  t_2 = time2 - time1;
  std::cout << "Execution time of the sequential algorithm: " << t_1
            << std::endl;
  std::cout << "Execution time of the parallel algorithm: " << t_2 << std::endl;

  ASSERT_NO_FATAL_FAILURE(s2.operator_Sobel(rand));
}

TEST(TEST_SOBOL, SIZE_MATR_750_OMP) {
  double time1, time2;
  Sobel s1, s2, rand, t_1, t_2;
  rand = rand.RandomMatrix(750);

  time1 = omp_get_wtime();
  s1.operator_Sobel(rand);
  time2 = omp_get_wtime();
  t_1 = time2 - time1;

  time1 = omp_get_wtime();
  s2.operator_Sobel_parr(rand);
  time2 = omp_get_wtime();
  t_2 = time2 - time1;
  std::cout << "Execution time of the sequential algorithm: " << t_1
            << std::endl;
  std::cout << "Execution time of the parallel algorithm: " << t_2 << std::endl;

  ASSERT_NO_FATAL_FAILURE(s2.operator_Sobel(rand));
}

TEST(TEST_SOBOL, SIZE_MATR_1000_OMP) {
  double time1, time2;
  Sobel s1, s2, rand, t_1, t_2;
  rand = rand.RandomMatrix(1000);

  time1 = omp_get_wtime();
  s1.operator_Sobel(rand);
  time2 = omp_get_wtime();
  t_1 = time2 - time1;

  time1 = omp_get_wtime();
  s2.operator_Sobel_parr(rand);
  time2 = omp_get_wtime();
  t_2 = time2 - time1;
  std::cout << "Execution time of the sequential algorithm: " << t_1
            << std::endl;
  std::cout << "Execution time of the parallel algorithm: " << t_2 << std::endl;

  ASSERT_NO_FATAL_FAILURE(s2.operator_Sobel(rand));
}

TEST(TEST_SOBOL, SIZE_MATR_1250_OMP) {
  double time1, time2;
  Sobel s1, s2, rand, t_1, t_2;
  rand = rand.RandomMatrix(1250);

  time1 = omp_get_wtime();
  s1.operator_Sobel(rand);
  time2 = omp_get_wtime();
  t_1 = time2 - time1;

  time1 = omp_get_wtime();
  s2.operator_Sobel_parr(rand);
  time2 = omp_get_wtime();
  t_2 = time2 - time1;
  std::cout << "Execution time of the sequential algorithm: " << t_1
            << std::endl;
  std::cout << "Execution time of the parallel algorithm: " << t_2 << std::endl;

  ASSERT_NO_FATAL_FAILURE(s2.operator_Sobel(rand));
}

TEST(TEST_SOBOL, SIZE_MATR_1500_OMP) {
  double time1, time2;
  Sobel s1, s2, rand, t_1, t_2;
  rand = rand.RandomMatrix(1500);

  time1 = omp_get_wtime();
  s1.operator_Sobel(rand);
  time2 = omp_get_wtime();
  t_1 = time2 - time1;

  time1 = omp_get_wtime();
  s2.operator_Sobel_parr(rand);
  time2 = omp_get_wtime();
  t_2 = time2 - time1;
  std::cout << "Execution time of the sequential algorithm: " << t_1
            << std::endl;
  std::cout << "Execution time of the parallel algorithm: " << t_2 << std::endl;

  ASSERT_NO_FATAL_FAILURE(s2.operator_Sobel(rand));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  omp_set_num_threads(2);
  return RUN_ALL_TESTS();
}
