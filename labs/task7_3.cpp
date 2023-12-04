#include <iostream>

int main() {
    const int rows = 5;
    const int cols = 4;
    int matrix[rows][cols] = {
        {1, -2, 3, 4},
        {-5, 6, -7, 8},
        {9, 10, -11, -12},
        {13, -14, 15, 16},
        {-17, 18, -19, 20}
    };

    int minElement = matrix[0][0];
    int minCol = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < minElement) {
                minElement = matrix[i][j];
                minCol = j;
            }
        }
    }

 
    for (int i = 0; i < rows; i++) {
        if (matrix[i][minCol] < 0) {
            matrix[i][minCol] = 0;
        }
    }

 
    std::cout << "Результат: " << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }

    return 0;
}
