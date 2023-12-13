#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

const unsigned char START_ALPHABET = 32;
const unsigned char END_ALPHABET = 127;
const unsigned char CHAR_RANGE = END_ALPHABET - START_ALPHABET + 1;

// Функция шифрования/дешифрования текста по шифру Цезаря
std::string caesarCipher(std::string text, int key, bool encrypt) {
    std::string modifiedText;
    for (unsigned char c : text) {
        // Шифровать только печатные символы, а остальные брать как есть
        if (c >= START_ALPHABET && c <= END_ALPHABET) {
            if (encrypt) {
                c = static_cast<char>(START_ALPHABET + (c - START_ALPHABET + key + CHAR_RANGE) % CHAR_RANGE);
            } else {
                c = static_cast<char>(START_ALPHABET + (c - START_ALPHABET - key + CHAR_RANGE) % CHAR_RANGE);
            }
        }
        modifiedText += c;
    }
    return modifiedText;
}

// Функция для добавления случайных символов в текст
std::string addRandomChars(std::string text, int key) {
    std::string modifiedText;
    
    srand(static_cast<unsigned int>(time(nullptr))); // Инициализация генератора случайных чисел
    
    for (size_t i = 0; i < text.size(); ++i) {
        if (i != 0 && i % key == 0) {
            for (size_t j = 0; j < key; ++j) {
                char randomChar = static_cast<char>(START_ALPHABET + rand() % CHAR_RANGE); 
                modifiedText += randomChar;
            }
        }
        modifiedText += text[i];
    }
    return modifiedText;
}

// Функция для удаления случайных символов из текста
std::string removeRandomChars(std::string text, int key) {
    std::string modifiedText;    
    for (size_t i = 0; i < text.size(); ++i) {
        if (i != 0 && i % key == 0) {
            i += key;
        }
        if (i < text.size()) {
            modifiedText += text[i];
        }
    }
    return modifiedText;
}

int main() {
    std::string inputFileName, outputFileName;
    std::string text, processedText;
    int key;
    char choice;

    // Запрос у пользователя, что делать с текстом (TODO проверить валидность ввода)
    std::cout << "Шифровать или дешифровать (e/d): ";
    std::cin >> choice;
    switch (choice) {
    case 'e':
        inputFileName = "decrypted_caesar.txt";
        outputFileName = "encrypted_caesar.txt";
        break;
    case 'd':
        inputFileName = "encrypted_caesar.txt";
        outputFileName = "decrypted_caesar.txt";
        break;
    default:
        std::cout << "Ожидается e или d";
        return 1;
    }

    // Запрос ключа шифрования
    std::cout << "Введите ключ (сдвиг): ";
    std::cin >> key;

    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cerr << "Ошибка открытия входного файла" << std::endl;
        return 1;
    }

    // Чтение текста из файла
    std::getline(inputFile, text, '\0');
    inputFile.close();

    // Если дешифруем, удаляем случайные символы (до дешифрования)
    if (choice == 'd') {
        text = removeRandomChars(text, key);
        std::cout << "Строка до шифрования: " << text << std::endl; 
    }

    // Шифрование или дешифрование текста
    processedText = caesarCipher(text, key, choice == 'e');
    
    // Если шифруем, добавляем случайные символы (после шифрования)
    if (choice == 'e') {
        std::cout << "Строка после шифрования: " << processedText << std::endl; 
        processedText = addRandomChars(processedText, key);
    }

    // Запись обработанного текста в файл
    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        std::cerr << "Ошибка открытия выходного файла" << std::endl;
        return 1;
    }
    outputFile << processedText;
    outputFile.close();

    std::cout << "Текст был обработан: " << processedText << std::endl;

    return 0;
}
