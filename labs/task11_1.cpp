#include <vector>
#include <iostream>
#include <algorithm>
#include "common.hpp"

bool shouldSort(std::vector<int> array) {
    int sum_digits;
    for (int i = 0; i < array.size(); i++) {
        sum_digits = common::sumOfDigits(array[i]);
        if (sum_digits == 14) {
            return true;
        }
    }
    return false;
}

int main() {
    std::vector<int> array = {30, 1, 100, 5, 10, 20, 30, 25, 77, 24};

    if (shouldSort(array)) {
        std::sort(array.begin(), array.end());
    }

    std::cout << "Результат:" << std::endl;
    common::printIntVector(array);

    return 0;
}
