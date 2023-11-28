#include <iostream>

//Задание №2
int main() {
    int N;

    // Ввод цифры N
    std::cout << "Введите цифру N (от 0 до 9): ";
    scanf("%d", &N);

    // Здесь мы будем использовать оператор switch для определения цифры
    switch (N) {
        case 0:
            std::cout << "Ноль" << std::endl;
            break;
        case 1:
            std::cout << "Один" << std::endl;
            break;
        case 2:
            std::cout << "Два" << std::endl;
            break;
        case 3:
            std::cout << "Три" << std::endl;
            break;
        case 4:
            std::cout << "Четыре" << std::endl;
            break;
        case 5:
            std::cout << "Пять" << std::endl;
            break;
        case 6:
            std::cout << "Шесть" << std::endl;
            break;
        case 7:
            std::cout << "Семь" << std::endl;
            break;
        case 8:
            std::cout << "Восемь" << std::endl;
            break;
        case 9:
            std::cout << "Девять" << std::endl;
            break;
        default:
            std::cout << "Ошибка: введено не цифра или число вне диапазона 0-9." << std::endl;
    }

    return 0;
}
