#include <iostream>
#include <algorithm>

int main() {
    const int maxN = 1000;
    int sequence[maxN];
    int n;
    std::cout << "Введите количество элементов до (" << maxN << "): ";
    std::cin >> n;


    std::cout << "Введите элементы последовательности:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> sequence[i];
    }

    std::sort(sequence, sequence + n);

    // Удаление продублированных элементов (в задании звучало как: "Затем удалите и продублируйте элементы".)
    int uniqueCount = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || sequence[i] != sequence[i - 1]) {
            sequence[uniqueCount++] = sequence[i];
        }
    }

    // Вывод уникальных элементов
    std::cout << "Полученная последовательность:" << std::endl;
    for (int i = 0; i < uniqueCount; i++) {
        std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
