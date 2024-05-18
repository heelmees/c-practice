#include <iostream>
#include <cstring>
#include <windows.h>

class String {
private:
    char* data;
    size_t length;

public:
    // Конструктор по умолчанию
    String() : data(nullptr), length(0) {}

    // Конструктор с параметром
    String(const char* str) {
        if (str) {
            length = std::strlen(str);
            data = new char[length + 1];
            std::strcpy(data, str);
        } else {
            data = nullptr;
            length = 0;
        }
    }

    // Конструктор копирования
    String(const String& other) {
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }

    // Оператор присваивания копированием
    String& operator=(const String& other) {
        if (this == &other)
            return *this;

        delete[] data;

        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);

        return *this;
    }

    // Деструктор
    ~String() {
        delete[] data;
        std::cout << "Вызван Деструктор" << "\n";
     }

    // Метод для получения длины строки
    size_t size() const {
        return length;
    }

    // Метод для получения строки
    const char* getString() const {
        return data;
    }
};

void createAndDestroyStrings() {
    {
        // Создание строки с использованием конструктора с параметром
        String str1("Hello, world!");

        // Использование конструктора копирования
        String str2 = str1;

        // Использование оператора присваивания копированием
        String str3;
        str3 = str1;

        std::cout << "Str1: " << str1.getString() << " (Length: " << str1.size() << ")" << std::endl;
        std::cout << "Str2: " << str2.getString() << " (Length: " << str2.size() << ")" << std::endl;
        std::cout << "Str3: " << str3.getString() << " (Length: " << str3.size() << ")" << std::endl;
    }
    //Переменные str1, str2, str3 не существуют, их деструкторы вызваны
    //std::cout << "Str3: " << str3.getString() << " (Length: " << str3.size() << ")" << std::endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    createAndDestroyStrings();
    return 0;
}