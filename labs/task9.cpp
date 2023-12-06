#include <iostream>
#include <vector>
#include <limits>

bool containsDigit(int number, int digit) {
    while (number > 0) {
        if (number % 10 == digit) return true;
        number /= 10;
    }
    return false;
}

bool checkDiagonal(const std::vector<std::vector<int>>& matrix) {
    //Матрица квадратная, можно обойтись одним циклом
    for (size_t i = 0; i < matrix.size(); ++i) {
        int element = matrix[i][i];
        if (element <= 0 || (!containsDigit(element, 3) && !containsDigit(element, 5))) {
            return false;
        }
    }
    return true;
}

int main() {
    const size_t n = 4; // Пример размера матрицы, должно быть n <= 100
    std::vector<std::vector<int>> matrix = {
        {13, 2, -6, 4},
        {5, 5, 7, 8},
        {1, 10, 3, 11},
        {12, 13, -7, 5}
    };

    if (checkDiagonal(matrix)) {
        std::cout << "Все диагональные элементы матрицы содержат цифру 3 или 5" << std::endl;
        for (size_t j = 0; j < n; ++j) {
            int minElement = std::numeric_limits<int>::max(); // Присвоить максимальное значение
            int sumOfSquares = 0;
            size_t minIndex = 0; // Привыкать использовать size_t

            // Находим минимальный элемент и сумму квадратов в столбце
            for (size_t i = 0; i < n; ++i) {
                sumOfSquares += matrix[i][j] * matrix[i][j];
                if (matrix[i][j] < minElement) {
                    minElement = matrix[i][j];
                    minIndex = i;
                }
            }

            // Заменяем минимальный элемент на сумму квадратов
            matrix[minIndex][j] = sumOfSquares;
        }
    }

    // Выводим измененную матрицу
    for (const auto& row : matrix) {
        for (int element : row) {
            std::cout << element << "\t";
        }
        std::cout << std::endl;
    }

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
