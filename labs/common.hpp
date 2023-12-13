#ifndef COMMON_HPP
#define COMMON_HPP

#include <iostream>
#include <vector>

typedef std::vector<int> Vector;
typedef std::vector<std::vector<int>> Matrix;

namespace common {

void sortInt(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int* a, int* b);
int sumOfDigits(int number);
void printIntVector(std::vector<int> v);

// Функция для подсчета суммы цифр числа
int sumOfDigits(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

void printIntVector(Vector v) {
   for (int elem: v) {
      std::cout << elem << " ";
   }
   std::cout << std::endl;
}

void printIntMatrix(Matrix matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}

// Функция быстрой сортировки
void sortInt(int arr[], int low, int high) {
    if (low < high) {
        // pi - индекс разбиения, элемент arr[pi] теперь на правильном месте
        int pi = partition(arr, low, high);

        // Рекурсивная сортировка элементов до и после разбиения
        sortInt(arr, low, pi - 1);
        sortInt(arr, pi + 1, high);
    }
}

// Функция для разбиения массива, принимает последний элемент в качестве опорного,
// размещает опорный элемент на правильное место в отсортированном массиве,
// перемещает все элементы меньше опорного влево от него и все большие элементы - вправо
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Опорный элемент
    int i = (low - 1); // Индекс меньшего элемента

    for (int j = low; j <= high - 1; j++) {
        // Если текущий элемент меньше или равен опорному
        if (arr[j] <= pivot) {
            i++; // Увеличение индекса меньшего элемента
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Вспомогательная функция для обмена двух элементов
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}


} 
#endif
