// Copyright 2022 Chremushkin Kirill
#include <gtest/gtest.h>
#include <vector>
#include "./ComplexMatrix.h"

TEST(MatrixComplex_Seq, get_works) {
    MatrixComplex matrix(3);
    EXPECT_NO_THROW(matrix.get(1, 1));
}

TEST(MatrixComplex_Seq, get_throws_exception) {
    MatrixComplex matrix(3);
    EXPECT_ANY_THROW(matrix.get(4, 4));
}

TEST(MatrixComplex_Seq, multiplication_works) {
    MatrixComplex matrix1(6);
    MatrixComplex matrix2(6);
    MatrixComplex res;
    EXPECT_NO_THROW(matrix1.Multiply(matrix1, matrix2, &res));
}

TEST(Matrix_Multiplication_Seq, multiplication_throws_exception) {
    MatrixComplex matrix1(3);
    MatrixComplex matrix2(5);
    MatrixComplex res;
    EXPECT_ANY_THROW(matrix1.Multiply(matrix1, matrix2, &res));
}

TEST(Matrix_Multiplication_Seq, result_matrix_has_correct_size) {
    MatrixComplex matrix1(4);
    MatrixComplex matrix2(4);
    MatrixComplex res;
    matrix1.Multiply(matrix1, matrix2, &res);
    EXPECT_EQ(res.getSize(), matrix1.getSize());
    EXPECT_EQ(res.getSize(), matrix2.getSize());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
