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
    } else {
        std::cout << "Число должно быть 1 или -1";
    }

    //Также можно использовать оператор switch/case
    switch (x)
    {
    case -1:
        std::cout << "Negative number" << std::endl;
        break;
    case 1:
        std::cout << "Positive number" << std::endl;
        break;
    default:
        std::cout << "Число должно быть 1 или -1";
        break;
    }

    //Также можно использовать тренарный оператор
    std::cout << (x == -1 ? "Negative number" : (x == 1 ? "Positive number" : "Число должно быть 1 или -1"));

    return 0;
}
