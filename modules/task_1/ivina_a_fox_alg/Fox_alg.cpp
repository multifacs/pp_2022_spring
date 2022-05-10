// Copyright 2022 Ivina Anastasiya
#include "../../../modules/task_1/ivina_a_fox_alg/Fox_alg.h"

#include <vector>
#include <random>
#include <iostream>
#include <iomanip>

Matrix FillMatrixRandom(Matrix &matrix)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1000.0);
    if (matrix.size() > 0)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                matrix[i][j] = dis(gen);
            }
        }
    }
    else
    {
        throw "Invalid matrix size";
    }

    return matrix;
}

void PrintMatrix(const Matrix &matrix)
{
    const int row = matrix.size();
    const int col = matrix[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << matrix[i][j] << std::setw(4) << "  ";
        }
        std::cout << std::endl;
    }
}

Matrix DenseMatrixMultiplication(const Matrix &a,
                                 const Matrix &b)
{

    if (a[0].size() != b.size())
    {
        throw "Matrices with different sizes cannot be multiplied";
    }
    const int row = a.size();
    const int col = b[0].size();
    Matrix c(row, MatrixRow(col, 0));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            for (int k = 0; k < a[0].size(); k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

Matrix BlockMatrixMultiplication(const Matrix &a,
                                 const Matrix &b)
{
    if (a.size() != b.size())
    {
        throw "Matrices with different sizes cannot be multiplied";
    }
    const int row = a.size();
    const int col = b[0].size();
    Matrix c(row, MatrixRow(col, 0));

    const int block_size = std::sqrt(row);

    for (int ii = 0; ii < row; ii += block_size)
    {
        for (int jj = 0; jj < row; jj += block_size)
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = ii; j < ((ii + block_size) > row ? row : (ii + block_size)); j++)
                {
                    double temp = 0;
                    for (int k = jj; k < ((jj + block_size) > row ? row : (jj + block_size)); k++)
                    {
                        temp += a[i][k] * b[k][j];
                    }
                    c[i][j] += temp;
                }
            }
        }
    }
    return c;
}