#include <iostream>
#include <cmath>

int main() {
    int A[] = {-3, -1, -2, 5, 10, 20, 25, 30};
    int array_size = sizeof(A) / sizeof(A[0]);
    int multiply_res = 1;
    int min_value = pow(2, sizeof(int) * 8) - 1;
    int min_index = -1;

    std::cout << "Массив целых чисел:" << std::endl;
    for (int i = 0; i < array_size; i++) {
        if (-2 <= A[i] && A[i] <= 20) {
            multiply_res *= A[i];
            if (A[i] < min_value) {
                min_value = A[i];
                min_index = i;
            } 
        }
    }
    
    std::cout << "Произведение: " << multiply_res << ", наименьшее: " << min_value << ", номер: " << min_index + 1 << std::endl;

    return 0;
}
