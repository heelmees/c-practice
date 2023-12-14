#include <iostream>
#include <climits> // Для использования INT_MAX
#include "common.hpp"

void printIntMatrix(int** matrix, int n, int m) {
    /*
    // Обычный вариант
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    */
    // Вариант с арифметикой указателей
     for (int** rowPtr = matrix; rowPtr < matrix + n; ++rowPtr) {
        int* row = *rowPtr;
        for (int* elemPtr = row; elemPtr < row + m; ++elemPtr) {
            std::cout << *elemPtr << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    int n, m;
    std::cout << "Введите количество строк (n): ";
    std::cin >> n;
    std::cout << "Введите количество столбцов (m): ";
    std::cin >> m;

    if (n <= 0 || n > 100 || m <= 0 || m > 100) {
        std::cerr << "n и m должны быть в пределах от 1 до 100." << std::endl;
        return 1;
    }

    // Выделение памяти под матрицу
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[m];
    }

    // Заполнение матрицы и сразу поиск наименьшего элемента и его столбца
    int minElement = INT_MAX;
    int minColumn = 0;
    std::cout << "Введите элементы матрицы:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> matrix[i][j];
            if (matrix[i][j] < minElement) {
                minElement = matrix[i][j];
                minColumn = j;
            }
        }
    }

    // Вывод оригинальной матрицы
    std::cout << "Оригинальная матрица:" << std::endl;
    printIntMatrix(matrix, n, m);

    // Замена отрицательных элементов в столбце с наименьшим элементом на 0
    for (int i = 0; i < n; ++i) {
        if (matrix[i][minColumn] < 0) {
            matrix[i][minColumn] = 0;
        }
    }

    // Вывод измененной матрицы
    std::cout << "Измененная матрица:" << std::endl;
    printIntMatrix(matrix, n, m);

    // Освобождение памяти
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
