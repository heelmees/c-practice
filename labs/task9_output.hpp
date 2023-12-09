#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <iostream>
#include <vector>

namespace output_space {

void printMatrix(std::vector<std::vector<int>> matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            std::cout << element << "\t";
        }
        std::cout << std::endl;
    }
}

} 
#endif
