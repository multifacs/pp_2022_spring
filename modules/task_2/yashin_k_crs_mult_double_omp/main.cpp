// Copyright 2022 Yashin Kirill
#include <gtest/gtest.h>
#include <omp.h>
#include <vector>
#include "../../modules/task_2/yashin_k_crs_mult_double_omp/sparse_matrix_multiplication_omp.h"

TEST(Yashin_Kirill_Sparse_Matrix, Can_Multiply_Sparse_Omp) {
    int rows = 5;
    int columns = 5;
    std::vector<double> values = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    std::vector<int> col_index = {1, 4, 2, 3, 1, 3, 0};
    std::vector<int> row_index = {0, 2, 4, 5, 6, 7};

    Matrix true_result({{16.94, 0.0, 3.63, 4.84, 0.0},
                       {0.0, 18.15, 0.0, 29.04, 0.0},
                       {0.0, 0.0, 18.15, 24.2, 0.0},
                       {0.0, 0.0, 0.0, 43.56, 0.0},
                       {0.0, 8.47, 0.0, 0.0, 16.94}});

    sparse_matrix A(rows, columns, values, col_index, row_index);
    sparse_matrix result = sparse_multiplication_omp(A, A);
    sparse_matrix _true_result(true_result);

    ASSERT_TRUE(result == _true_result);
}

TEST(Yashin_Kirill_Sparse_Matrix, Can_Multiply_OMP_Random) {
    Matrix A(random_matrix(10, 10, 20));
    Matrix B(random_matrix(10, 10, 20));

    sparse_matrix sA(A);
    sparse_matrix sB(B);

    sparse_matrix result_sparse = sparse_multiplication_omp(sA, sB);
    Matrix result = matrix_multiplication(A, B);

    sparse_matrix _result(result);

    ASSERT_TRUE(result_sparse == result);
}

TEST(Yashin_Kirill_Sparse_Matrix, Test_Omp_Matrix_Multiplication_Size_50) {
    Matrix A(random_matrix(50, 50, 70));
    Matrix B(random_matrix(50, 50, 70));

    sparse_matrix sA(A);
    sparse_matrix sB(B);

    Matrix result = matrix_multiplication(A, B);
    sparse_matrix sparse_result(result);

    double t1_omp = omp_get_wtime();
    sparse_matrix _sparse_result_omp = sparse_multiplication_omp(sA, sB);
    double t2_omp = omp_get_wtime();

    double t1_no_omp = omp_get_wtime();
    sparse_matrix _sparse_result = sparse_multiplication(sA, sB);
    double t2_no_omp = omp_get_wtime();

    double acceleration = (t2_no_omp - t1_no_omp) / (t2_omp - t1_omp);
    std::cout << "OMP time for size 50: " << t2_omp - t1_omp
              << "\nNo OMP time for size 50: " << t2_no_omp - t1_no_omp
              << "\nAcceleration: " << acceleration << std::endl;
    ASSERT_TRUE(sparse_result == _sparse_result_omp);
    ASSERT_TRUE(sparse_result == _sparse_result);
}

TEST(Yashin_Kirill_Sparse_Matrix, Test_Omp_Matrix_Multiplication_Size_100) {
    Matrix A(random_matrix(100, 100, 60));
    Matrix B(random_matrix(100, 100, 60));

    sparse_matrix sA(A);
    sparse_matrix sB(B);

    Matrix result = matrix_multiplication(A, B);
    sparse_matrix sparse_result(result);

    double t1_omp = omp_get_wtime();
    sparse_matrix _sparse_result_omp = sparse_multiplication_omp(sA, sB);
    double t2_omp = omp_get_wtime();

    double t1_no_omp = omp_get_wtime();
    sparse_matrix _sparse_result = sparse_multiplication(sA, sB);
    double t2_no_omp = omp_get_wtime();

    double acceleration = (t2_no_omp - t1_no_omp) / (t2_omp - t1_omp);
    std::cout << "OMP time for size 100: " << t2_omp - t1_omp
              << "\nNo OMP time for size 100: " << t2_no_omp - t1_no_omp
              << "\nAcceleration: " << acceleration << std::endl;
    ASSERT_TRUE(sparse_result == _sparse_result_omp);
    ASSERT_TRUE(sparse_result == _sparse_result);
}

TEST(Yashin_Kirill_Sparse_Matrix, Test_Omp_Matrix_Multiplication_Size_250) {
    Matrix A(random_matrix(250, 250, 50));
    Matrix B(random_matrix(250, 250, 50));

    sparse_matrix sA(A);
    sparse_matrix sB(B);

    Matrix result = matrix_multiplication(A, B);
    sparse_matrix sparse_result(result);

    double t1_omp = omp_get_wtime();
    sparse_matrix _sparse_result_omp = sparse_multiplication_omp(sA, sB);
    double t2_omp = omp_get_wtime();

    double t1_no_omp = omp_get_wtime();
    sparse_matrix _sparse_result = sparse_multiplication(sA, sB);
    double t2_no_omp = omp_get_wtime();

    double acceleration = (t2_no_omp - t1_no_omp) / (t2_omp - t1_omp);
    std::cout << "OMP time for size 250: " << t2_omp - t1_omp
              << "\nNo OMP time for size 250: " << t2_no_omp - t1_no_omp
              << "\nAcceleration: " << acceleration << std::endl;
    ASSERT_TRUE(sparse_result == _sparse_result_omp);
    ASSERT_TRUE(sparse_result == _sparse_result);
}

TEST(Yashin_Kirill_Sparse_Matrix, Test_Omp_Matrix_Multiplication_Size_500) {
    Matrix A(random_matrix(500, 500, 50));
    Matrix B(random_matrix(500, 500, 50));

    sparse_matrix sA(A);
    sparse_matrix sB(B);

    Matrix result = matrix_multiplication(A, B);
    sparse_matrix sparse_result(result);

    double t1_omp = omp_get_wtime();
    sparse_matrix _sparse_result_omp = sparse_multiplication_omp(sA, sB);
    double t2_omp = omp_get_wtime();

    double t1_no_omp = omp_get_wtime();
    sparse_matrix _sparse_result = sparse_multiplication(sA, sB);
    double t2_no_omp = omp_get_wtime();

    double acceleration = (t2_no_omp - t1_no_omp) / (t2_omp - t1_omp);
    std::cout << "OMP time for size 500: " << t2_omp - t1_omp
              << "\nNo OMP time for size 500: " << t2_no_omp - t1_no_omp
              << "\nAcceleration: " << acceleration << std::endl;
    ASSERT_TRUE(sparse_result == _sparse_result_omp);
    ASSERT_TRUE(sparse_result == _sparse_result);
}
