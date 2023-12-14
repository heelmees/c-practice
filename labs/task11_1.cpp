#include <iostream>
#include <algorithm>

// Функция для вычисления суммы цифр числа
int sumOfDigits(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main() {
    int n;

    std::cout << "Введите количество элементов последовательности: " << std::endl;
    std::cin >> n;
    int* sequence = new int[n];
    std::cout << "Введите " << n << " элеметнов последовательности: " << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> *(sequence + i);
    }

    bool shouldSort = false;
    for (int* ptr = sequence; ptr < sequence + n; ++ptr) {
        if (sumOfDigits(*ptr) == 14) {
            shouldSort = true;
            break;
        }
    }

    if (shouldSort) {
        std::sort(sequence, sequence + n);
    }

    for (const int* ptr = sequence; ptr < sequence + n; ++ptr) {
        std::cout << *ptr << " ";
    }
    std::cout << std::endl;

    // Освободить память
    delete[] sequence;

    return 0;
}
