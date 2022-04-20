// Copyright 2022 Cheremushkin Kirill
#include "../../../modules/task_1/cheremushkin_a_matrix_multiplication/ComplexMatrix.h"

MatrixComplex::MatrixComplex() : Size{ 3 }, NonZero{ 3 },
values{ {3, 2}, {4, 3}, {2, 4} }, rows { 0, 1, 2 },
columnIndexes { 0, 1, 2, 2 } {
}
MatrixComplex::MatrixComplex(const MatrixComplex &tmp) : Size{ tmp.Size },
NonZero{ tmp.NonZero },
values{ tmp.values }, rows{ tmp.rows },
columnIndexes{ tmp.columnIndexes } {
}
MatrixComplex::MatrixComplex(int size) {
    std::vector<std::vector<std::complex<int>>> matrix = getRandomMatrix(size);
    Size = matrix.size();
    NonZero = 0;
    std::complex<int> zero(0, 0);
    this->columnIndexes.push_back(0);
    int counter = 0;
    for (int i = 0; i < static_cast<int>(matrix.size()); i++) {
        for (int j = 0; j < static_cast<int>(matrix[i].size()); j++) {
            if (matrix[i][j] != zero) {
                values.push_back(matrix[i][j]);
                rows.push_back(j);
                NonZero++;
                counter++;
            }
        }
        columnIndexes.push_back(counter);
    }
}
MatrixComplex::MatrixComplex(
    std::vector<std::vector<std::complex<int>>> matrix) {
    Size = matrix.size();
    NonZero = 0;
    std::complex<int> zero(0, 0);
    this->columnIndexes.push_back(0);
    int counter = 0;
    for (int i = 0; i < static_cast<int>(matrix.size()); i++) {
        for (int j = 0; j < static_cast<int>(matrix[i].size()); j++) {
            if (matrix[i][j] != zero) {
                values.push_back(matrix[i][j]);
                rows.push_back(j);
                NonZero++;
                counter++;
            }
        }
        columnIndexes.push_back(counter);
    }
}
MatrixComplex& MatrixComplex::operator=(const MatrixComplex& tmp) {
    Size = tmp.Size;
    NonZero = tmp.NonZero;
    values = tmp.values;
    rows = tmp.rows;
    columnIndexes = tmp.columnIndexes;
    return *this;
}
std::complex<int> MatrixComplex::get(int row, int col) const {
    if (row > Size || col > Size || row < 0 || col < 0) {
        throw std::invalid_argument("index out of matrix range");
    }
    int currRow;
    for (int pos = columnIndexes[row]; pos < columnIndexes[row + 1]; pos++) {
        currRow = rows[pos];
        if (currRow == col) {
            return values[pos];
        }
    }
    return std::complex<int>();
}
MatrixComplex::~MatrixComplex() {
    Size = 0;
    NonZero = 0;
    values.~vector();
    rows.~vector();
    columnIndexes.~vector();
}

int MatrixComplex::getSize() {
    return Size;
}

int MatrixComplex::getNonZero() {
    return NonZero;
}

void MatrixComplex::setSize(int s) {
     Size = s;
}

void MatrixComplex::setNonZero(int n) {
     NonZero = n;
}

std::vector<std::complex<int>> MatrixComplex::getValues() {
     return values;
}

std::vector<int> MatrixComplex::getRows() {
     return rows;
}

std::vector<int> MatrixComplex::getColumnIndex() {
     return columnIndexes;
}
std::vector<std::vector<std::complex<int>>>
MatrixComplex::getRandomMatrix(int size) {
    std::random_device dev;
    std::mt19937 gen(dev());
    std::vector<std::vector<std::complex<int>>> result;
    for (int i = 0; i < size; i++) {
        std::vector<std::complex<int>> vec;
        for (int j = 0; j < size; j++) {
            if (gen() % 100 <= 30) {
                std::complex<int> complexNumber(gen() % 10, (gen() % 10));
                vec.push_back(complexNumber);
            } else {
                std::complex<int> complexNumber(0, 0);
                vec.push_back(complexNumber);
            }
        }
        result.push_back(vec);
    }
    return result;
}
MatrixComplex MatrixComplex::Multiply(
    MatrixComplex left, MatrixComplex right, MatrixComplex*result) {
    if (left.Size != right.Size) {
        throw std::invalid_argument("invalid matrix");
    }
    int size = left.Size;
    std::vector<std::complex<int>> values;
    std::vector<int> rows;
    std::vector<int> columnIndexes;
    int* temp = new int[size];
    int nonZero = 0;
    columnIndexes.push_back(0);
    for (int i = 0; i < size; i++) {
        memset(temp, -1, size * sizeof(int));
		/*if (right.columnIndexes[i] == -2 || right.columnIndexes[i + 1] == -2) {
			continue;
		}*/
        for (int j = right.columnIndexes[i];
            j < right.columnIndexes[i + 1]; j++) {
            int row = right.rows[j];
            temp[row] = j;
        }
        for (int j = 0; j < size; j++) {
            std::complex<int> sum = 0;
			/*if (left.columnIndexes[j] == -2 || left.columnIndexes[j + 1] == -2) {
				continue;
			}*/
            for (int k = left.columnIndexes[j];
                k < left.columnIndexes[j + 1]; k++) {
                int row = left.rows[k];
                int index = temp[row];
                if (index != -1) {
                    sum = {sum.real() + (left.values[k].real() * right.values[index].real()) -
                        left.values[k].imag() * right.values[index].imag(),
                        sum.imag()+
                        (left.values[k].real() * right.values[index].imag()+
                        left.values[k].imag() * right.values[index].real())
                    };
                }
            }
            if (sum != 0) {
                rows.push_back(j);
                values.push_back(sum);
                nonZero++;
            }
        }
        columnIndexes.push_back(nonZero);
    }
    delete[] temp;
    // Initialize(result, size, nonZero);
    result->Size = size;
    result->rows.resize(rows.size());
    result->values.resize(values.size());
    result->columnIndexes.resize(columnIndexes.size());
    for (int i = 0; i < nonZero; i++) {
        result->rows[i] = rows[i];
        result->values[i] = values[i];
    }
    for (size_t i = 0; i < columnIndexes.size(); i++) {
        result->columnIndexes[i] = columnIndexes[i];
    }
    return *result;
}