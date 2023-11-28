#include <iostream>

// Задание №3
int main() {
    int x;

    // Сделаем ввод в переменную х, которая может принять значения 1 либо -1.
    std::cout << "Введите число 1 или -1: ";
    scanf("%d", &x);

    // Далее мы выполним проверку числа х на знак (положительный или отрицательный) 
    if (x == -1) {
        std::cout << "Negative number" << std::endl;
    } else if (x == 1) {
        std::cout << "Positive number" << std::endl;
    }

    return 0;
}
