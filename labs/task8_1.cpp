#include <iostream>
#include <fstream>
#include <string>
#include <codecvt>
#include <locale>
#include <cstring>
#include <unordered_map>
#include <algorithm>

const int MAX_WORDS = 2000;
const int MAX_WORD_LENGTH = 100;

// Функция для проверки, состоит ли слово из букв заданного слова плюс одна любая
bool isValidWord(const std::wstring& word, const std::unordered_map<wchar_t, int> charMap) {
    bool extraLetterUsed = false;
    for (wchar_t ch : word) {
        if (charMap.find(ch) == charMap.end()) {
            if (extraLetterUsed) {
                return false;
            }
            extraLetterUsed = true;
        }
    }
    // Обязательно должна быть одна лишняя буква)))
    return extraLetterUsed;
}

bool compareByLength(const std::wstring& a, const std::wstring& b) {
    return a.size() < b.size();
}

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    std::wifstream inFile("input_task8_1.txt");
    std::wofstream outFile("output_task8_1.txt");
    std::wstring baseWord = L"язык"; // Замените на ваше заданное слово
    
    // Cоставить map c кол-вом встречающихся букв
    // Можно было обойтись простым массивом, но было интересно поковырять)
    std::unordered_map<wchar_t, int> charMap;
    for (wchar_t c : baseWord) {
        charMap[c]++;
    }

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Не удалось открыть файлы." << std::endl;
        return 1;
    }

    inFile.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
    outFile.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));

    std::wstring words[MAX_WORDS];
    int wordCount = 0;

    std::wstring word;
    while (inFile >> word) {
        if (isValidWord(word, charMap)) {
            bool duplicate = false;
            for (int i = 0; i < wordCount; ++i) {
                if (words[i] == word) {
                    duplicate = true;
                    break;
                }
            }
            if (!duplicate && wordCount < MAX_WORDS) {
                words[wordCount++] = word;
            }
        }
    }

    std::sort(words, words + wordCount, compareByLength);

    for (int i = 0; i < wordCount; ++i) {
        outFile << words[i] << std::endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}
