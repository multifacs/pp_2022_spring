// Copyright 2022 Kolesnikov Ilya
#include <gtest/gtest.h>
#include "./matrix.h"

TEST(CannonTest, test_1) {
    size_t size = 4;
    Matrix matrix1(size);
    Matrix matrix2(size);

    matrix1.generateMatrix();
    matrix2.generateMatrix();

    Matrix matrix3(matrix1.multiplyByMatrix(matrix2), size);

    Matrix matrix4(matrix1.cannonAlgorithmSeq(matrix1, matrix2), size);

    std::vector<std::vector<double>> matr1 = matrix4.get_matrix(), matr2 = matrix3.get_matrix();

    ASSERT_EQ(matr1[0][0], matr2[0][0]);
}

TEST(CannonTest, test_2) {
    size_t size = 4;
    Matrix matrix1(size);
    Matrix matrix2(size);

    matrix1.generateMatrix();
    matrix2.generateMatrix();

    Matrix matrix3(matrix1.multiplyByMatrix(matrix2), size);

    Matrix matrix4(matrix1.cannonAlgorithmSeq(matrix1, matrix2), size);

    std::vector<std::vector<double>> matr1 = matrix4.get_matrix(), matr2 = matrix3.get_matrix();

    ASSERT_EQ(matr1[1][1], matr2[1][1]);
}

TEST(CannonTest, test_3) {
    size_t size = 4;
    Matrix matrix1(size);
    Matrix matrix2(size);

    matrix1.generateMatrix();
    matrix2.generateMatrix();

    Matrix matrix3(matrix1.multiplyByMatrix(matrix2), size);

    Matrix matrix4(matrix1.cannonAlgorithmSeq(matrix1, matrix2), size);

    std::vector<std::vector<double>> matr1 = matrix4.get_matrix(), matr2 = matrix3.get_matrix();

    ASSERT_EQ(matr1[size-1][size-1], matr2[size-1][size-1]);
}

TEST(CannonTest, test_4) {
    size_t size = 4;
    Matrix matrix1(size);
    Matrix matrix2(size);

    matrix1.generateMatrix();
    matrix2.generateMatrix();

    Matrix matrix3(matrix1.multiplyByMatrix(matrix2), size);

    Matrix matrix4(matrix1.cannonAlgorithmSeq(matrix1, matrix2), size);

    std::vector<std::vector<double>> matr1 = matrix4.get_matrix(), matr2 = matrix3.get_matrix();

    ASSERT_EQ(matr1[0], matr2[0]);
}

TEST(CannonTest, test_5) {
    size_t size = 4;
    Matrix matrix1(size);
    Matrix matrix2(size);

    matrix1.generateMatrix();
    matrix2.generateMatrix();

    Matrix matrix3(matrix1.multiplyByMatrix(matrix2), size);

    Matrix matrix4(matrix1.cannonAlgorithmSeq(matrix1, matrix2), size);

    std::vector<std::vector<double>> matr1 = matrix4.get_matrix(), matr2 = matrix3.get_matrix();

    ASSERT_EQ(matr1, matr2);
}