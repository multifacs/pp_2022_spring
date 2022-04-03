// Copyright 2022 Kolesnikov Gleb
#ifndef MODULES_TASKS_1_KOLESNIKOV_G_CRS_MULT_H_
#define MODULES_TASKS_1_KOLESNIKOV_G_CRS_MULT_H_

#include <vector>
#include <string>

class MatrixCRS {
public:
    int nColumns;
    int nRows;

    std::vector<double> values;
    std::vector<int> columns;
    std::vector<int> pointers;

    MatrixCRS(int nC, int nR, std::vector<double>& v, std::vector<int>& c, std::vector<int>& p);
    MatrixCRS(std::vector<std::vector<double>> mtx);
    MatrixCRS(int nC = 0, int nR = 0);
    MatrixCRS T();
    MatrixCRS dot(MatrixCRS mtx);
    MatrixCRS dot_omp(MatrixCRS mtx);
   
    void printArrays();

};
std::vector<std::vector<double>> multMatrix(std::vector<std::vector<double>> A, std::vector<std::vector<double>> B);
std::vector<std::vector<double>> zerpMatrix(int cols, int rows);
std::vector<std::vector<double>> generateMatrix(int cols, int rows, double density);
#endif  // MODULES_TASKS_1_KOLESNIKOV_G_CRS_MULT_H_
