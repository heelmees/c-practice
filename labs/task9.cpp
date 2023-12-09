#include <iostream>
#include <vector>
#include <limits>
#include "task9_input.hpp"
#include "task9_process.hpp"
#include "task9_output.hpp"


int main() {
    const size_t n = 4; // Пример размера матрицы, должно быть n <= 100
    std::vector<std::vector<int>> matrix = input_space::getMatrix();

    if (process_space::checkDiagonal(matrix)) {
        process_space::process_matrix(matrix, n);
    }

    // Выводим измененную матрицу
    output_space::printMatrix(matrix);

    /*
    Вход: 
        {13, 2, -6, 4},
        {5, 5, 7, 8},
        {1, 10, 3, 11},
        {12, 13, -7, 5}
    Выход:
        13 298 -6 226
        5 5 7 8
        339 10 3 11
        12 13 143 5
    */
        
    return 0;
}
