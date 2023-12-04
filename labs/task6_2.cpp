#include <iostream>

int main() {
    unsigned int N;  
    std::cout << "Введите натуральное число N: ";
    std::cin >> N;

    int sum = 0;
    while (N > 0) {
        int digit = N % 10;
        if (digit % 2 == 1) { 
            sum += digit;
        }
        N /= 10;
    }

    std::cout << "Сумма нечетных цифр числа: " << sum << std::endl;
    return 0;
}
