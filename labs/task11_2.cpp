#include <iostream>
#include <vector>
#include "common.hpp"


int columnForMinElem(Matrix matrix) {
    int minElement = matrix[0][0];
    int minCol = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] < minElement) {
                minElement = matrix[i][j];
                minCol = j;
            }
        }
    }
    return minCol;
}

// Попробовать передавать матрицу не по ссылке (&), а по указателю
void set0ToNegativeElemInColumn(Matrix *pMatrix, int minCol) {
    for (int i = 0; i < (*pMatrix).size(); i++) {
        if ((*pMatrix)[i][minCol] < 0) {
            (*pMatrix)[i][minCol] = 0;
        }
    }

}

int main() {
    Matrix matrix = {
        {1, -2, 3, 4},
        {-5, 6, -7, 8},
        {9, 10, -11, -12},
        {13, -14, 15, 16},
        {-17, 18, -19, 20}
    };

    int minCol = columnForMinElem(matrix);

    set0ToNegativeElemInColumn(&matrix, minCol);

    std::cout << "Результат: " << std::endl;
    common::printIntMatrix(matrix);

    // Очистка матрицы
    // Этого делать не нужно, т.к. при выходе из области видимости (main) память освободится автоматически
    /*
    matrix.clear();
    std::cout << "Размер: " << matrix.size() << " Ёмкость: " << matrix.capacity() << std::endl;
    matrix.shrink_to_fit();
    std::cout << "Размер: " << matrix.size() << " Ёмкость: " << matrix.capacity() << std::endl;
    */

    return 0;
}
