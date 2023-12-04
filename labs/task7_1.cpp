#include <iostream>
#include <algorithm> // Для std::sort


int main() {
    unsigned A[] = {30, 1, 100, 5, 10, 20, 30, 25, 77};
    int array_size = sizeof(A) / sizeof(A[0]);
    bool shouldSort = false;
    unsigned N;
    unsigned sum_digits;

    for (int i = 0; i < array_size; i++) {
        N = A[i];
        sum_digits = 0;
        while (N > 0) {
            int digit = N % 10;
            sum_digits += digit;
            N /= 10;
        }

        if (sum_digits == 14) {
            shouldSort = true;
            break;
        }
    }

    if (shouldSort) {
        std::sort(A, A + array_size);
    }

    std::cout << "Результат:" << std::endl;
    for (int i = 0; i < array_size; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
