// Copyright 2022 Kolesnikov Ilya
#include "../../../modules/task_1/kolesnikov_i_Cannon_dense_matrix/matrix.h"

void Matrix::generateMatrix() {
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            matrix[i][j] = (double)(rand() % 10);
        }
    }
}

std::vector< std::vector<double>> Matrix::multiplyByMatrix(Matrix matrix) {
    Matrix res_matrix(size);
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            for (size_t k = 0; k < size; ++k) {
                res_matrix.matrix[i][j] += this->matrix[i][k] * matrix.matrix[k][j];
            }
        }
    }
    return res_matrix.matrix;
}

void Matrix::shiftLeft(std::vector< std::vector<double>> &mat, size_t pos, size_t skew) {
    std::vector<double> tmp_matr(size);
    for (size_t i = 0; i < size; ++i) {
        tmp_matr[i] = mat[pos][ (i + skew) % size];
    }

    for (size_t i = 0; i < size; ++i) {
        mat[pos][i] = tmp_matr[i];
    }
}

void Matrix::shiftUp(std::vector< std::vector<double>> &mat, size_t pos, size_t skew) {
    std::vector<double> tmp_matr(size);
    for (size_t i = 0; i < size; ++i) {
        tmp_matr[i] = mat[ (i + skew) % size][pos];
    }
    for (size_t i = 0; i < size; ++i) {
        mat[i][pos] = tmp_matr[i];
    }
}

std::vector< std::vector<double>> Matrix::cannonAlgorithmSeq(Matrix matrix1, Matrix matrix2) {
    std::vector< std::vector<double>> res_matrix, matr1 = matrix1.matrix, matr2 = matrix2.matrix;
    for (size_t i = 0; i < size; ++i) {
        shiftLeft(matr1, i, i);
    }
    for (size_t j = 0; j < size; ++j) {
        shiftUp(matr2, j, j);
    }
    for (size_t i = 0; i < size; ++i) {
        std::vector<double> vec(size);
        res_matrix.push_back(vec);
        for (size_t j = 0; j < size; ++j) {
            res_matrix[i][j] = 0;
        }
    }
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            for (size_t k = 0; k < size; ++k) {
                res_matrix[j][k] += matr1[j][k] * matr2[j][k];
            }
        }
        for (size_t l = 0; l < size; ++l) {
            shiftLeft(matr1, l, 1);
        }
        for (size_t l = 0; l < size; ++l) {
            shiftUp(matr2, l, 1);
        }
    }
    return res_matrix;
}
