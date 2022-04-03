// Copyright 2018 Nesterov Alexander
#include <gtest/gtest.h>
#include <vector>
#include "./crs_mult.h"

/*
TEST(Parallel_Operations_OpenMP, Test_Sum) {
    std::vector<int> vec = getRandomVector(100);
    int sequential_sum = getSequentialOperations(vec, "+");
    int parallel_sum = getParallelOperations(vec, "+");
    ASSERT_EQ(sequential_sum, parallel_sum);
}

TEST(Parallel_Operations_OpenMP, Test_Diff) {
    std::vector<int> vec = getRandomVector(100);
    int sequential_diff = getSequentialOperations(vec, "-");
    int parallel_diff = getParallelOperations(vec, "-");
    ASSERT_EQ(sequential_diff, parallel_diff);
}

TEST(Parallel_Operations_OpenMP, Test_Diff_2) {
    std::vector<int> vec = getRandomVector(10);
    int sequential_diff = getSequentialOperations(vec, "-");
    int parallel_diff = getParallelOperations(vec, "-");
    ASSERT_EQ(sequential_diff, parallel_diff);
}

TEST(Parallel_Operations_OpenMP, Test_Mult) {
    std::vector<int> vec = getRandomVector(10);
    int sequential_mult = getSequentialOperations(vec, "*");
    int parallel_mult = getParallelOperations(vec, "*");
    ASSERT_EQ(sequential_mult, parallel_mult);
}

TEST(Parallel_Operations_OpenMP, Test_Mult_2) {
    std::vector<int> vec = getRandomVector(5);
    int sequential_mult = getSequentialOperations(vec, "*");
    int parallel_mult = getParallelOperations(vec, "*");
    ASSERT_EQ(sequential_mult, parallel_mult);
}
*/
int main(int argc, char **argv) {
      //  ::testing::InitGoogleTest(&argc, argv);
    std::vector<double> v1 = { 0, 10, 0, 10, 0};
    std::vector<double> v2 = { 0, 0, 21, 0, 1 };
    std::vector<double> v3 = { 0, 0, 0, 0, 0 };
    std::vector<double> v4 = { 3, 0, 0, 0, 25 };
    std::vector<double> v1T = { 0, 0, 0, 3 };
    std::vector<double> v2T = { 10, 0, 0, 0 };
    std::vector<double> v3T = { 0, 21, 0, 0 };
    std::vector<double> v4T = { 10, 0, 0, 0 };
    std::vector<double> v5T = { 0, 1, 0, 25};
    /*
    std::vector<double> v1 = { 0, 3, 0, 7 };
    std::vector<double> v2 = { 0, 0, 8, 0 };
    std::vector<double> v3 = { 0, 0, 0, 0};
    std::vector<double> v4 = { 9, 0, 15, 16 };
    */
    std::vector<std::vector<double>> v = { v1, v2, v3, v4 };
    std::vector<std::vector<double>> vT = { v1T, v2T, v3T, v4T, v5T };
    std::vector<std::vector<double>>  c = multMatrix(v, vT);

    std::cout << "Helo Nesterov\n";
    MatrixCRS crs(v);
    MatrixCRS crsT(v);
    crs.printArrays();
    crsT.printArrays();
    crs.dot(crsT).printArrays();
    MatrixCRS(c).printArrays();
      //  return RUN_ALL_TESTS();
}
