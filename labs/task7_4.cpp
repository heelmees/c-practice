#include <iostream>
#include <algorithm>

void printIntSequence(int sequence[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int maxN = 1000;
    int sequence[maxN * 2];
    int n;  
    std::cout << "Введите количество элементов до (" << maxN << "): ";
    std::cin >> n;


    std::cout << "Введите элементы последовательности:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> sequence[i];
    }

    std::sort(sequence, sequence + n);

    // Удаление продублированных элементов
    for (int i = 1; i < n; ++i) {
        if (sequence[i] == sequence[i - 1]) {
            for (int j = i; j < n - 1 ; ++j) {
                sequence[j] = sequence[j + 1];
            }
            --n;
            --i;
        }
    }

    std::cout << "Последовательность после удаления дубликатов:" << std::endl;
    printIntSequence(sequence, n);
 
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j >= i; --j) {
            sequence[j + 1] = sequence[j];
        }
        ++n;
        ++i;
    }
    
    std::cout << "Последовательность после дублирования:" << std::endl;
    printIntSequence(sequence, n);

    std::cout << "Итоговый результат задачи (каждый элемент по одному разу)" << std::endl;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || sequence[i] != sequence[i - 1]) {
            std::cout << sequence[i] << " ";
        }
    }
    std::cout << std::endl;
    
    return 0;
}
