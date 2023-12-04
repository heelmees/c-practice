#include <iostream>
#include <algorithm>


int getFirstDigit(int number) {
    while (number >= 10) {
        number /= 10;
    }
    return number;
}

int getMaxDigit(int number) {
    int maxDigit = 0;
    while (number > 0) {
        int digit = number % 10;
        if (digit > maxDigit) {
            maxDigit = digit;
        }
        number /= 10;
    }
    return maxDigit;
}

bool customCompare(int a, int b) {
    //std::cout << "customCompare " << a << " " << b << std::endl;
    int firstDigitA = getFirstDigit(a);
    int firstDigitB = getFirstDigit(b);

    if (firstDigitA != firstDigitB) {
        return firstDigitA < firstDigitB;
    }

    int maxDigitA = getMaxDigit(a);
    int maxDigitB = getMaxDigit(b);

    if (maxDigitA != maxDigitB) {
        return maxDigitA < maxDigitB;
    }

    return a < b;
}

int main() {
    int numbers[] = {30, 1, 100, 5, 10, 20, 30, 25, 77, 102, 101, 103};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    //Нам нужна нестандартная сортировка, потому в функцию sort передадим customCompare
    //Эта функция сравнивает два числа по условиям задачи
    std::sort(numbers, numbers + n, customCompare);

    std::cout << "Результат: ";
    for (int i = 0; i < n; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
