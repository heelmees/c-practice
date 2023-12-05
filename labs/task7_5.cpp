#include <iostream>
#include <cstring>

bool hasDuplicateDigits(int number) {
    bool digits[10] = {false}; // Массив для отслеживания встреченных цифр
    while (number > 0) {
        int digit = number % 10;
        if (digits[digit]) return true; // Если цифра уже встречалась, возвращаем true
        digits[digit] = true;
        number /= 10;
    }
    return false;
}

bool containsDigitFive(int number) {
    while (number > 0) {
        if (number % 10 == 5) return true;
        number /= 10;
    }
    return false;
}

int main() {
    const int n = 10;
    int sequence[n] = {303, 1, 100, 5, 10, 20, 30, 25, 77, 102};
    int result[n * 2], resultSize = 0;

    for (int i = 0; i < n; ++i) {
        if (!hasDuplicateDigits(sequence[i])) {
            result[resultSize++] = sequence[i]; // Добавляем число без повторяющихся цифр
            if (containsDigitFive(sequence[i])) {
                result[resultSize++] = sequence[i]; // Дублируем число, если оно содержит цифру 5
            }
        }
    }

    for (int i = 0; i < resultSize; ++i) {
        std::cout << result[i] << " "; // Выводим результат
    }

    return 0;
}
