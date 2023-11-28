#include <iostream>


// Задание №1
int main() {
    int A, B, C;
    
    // Ввод чисел A, B и C
    std::cout << "Введите число A: ";
    scanf("%d", &A);
    std::cout << "Введите число B: ";
    scanf("%d", &B);
    std::cout << "Введите число C: ";
    scanf("%d", &C);

    // Проверка условий и вывод результата
    if (A > B && B > C) {
        std::cout << "Результат: " << A - B - C << std::endl;
    } else if (B > A && B % C == 0) {
        std::cout << "Результат: " << B / C + B - A << std::endl;
    } else {
        std::cout << "Результат: " << A + B + C << std::endl;
    }

    return 0;
}

