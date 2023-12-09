#ifndef INPUT_HPP
#define INPUT_HPP

#include <iostream>

namespace input_space {

std::vector<std::vector<int>> getMatrix() {
    std::vector<std::vector<int>> matrix = {
        {13, 2, -6, 4},
        {5, 5, 7, 8},
        {1, 10, 3, 11},
        {12, 13, -7, 5}
    };
    return matrix;
}

} 
#endif
