#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <algorithm>
#include <cwctype>
#include <sstream>

void printStrSequence(std::wstring sequence[], int n) {
    for (int i = 0; i < n; i++) {
        std::wcout << sequence[i] << " ";
    }
    // std::cout << std::endl;
}

bool isVowel(const wchar_t ch) {
    std::wstring vowels = L"аеёиоуыэюяАЕЁИОУЫЭЮЯ";
    if (vowels.find(ch) != std::wstring::npos) {
        return true;
    }
    return false;
}

bool isConsonant(const wchar_t ch) {
    std::wstring consonants = L"бвгджзйклмнпрстфхцчшщБВГДЖЗЙКЛМНПРСТФХЦЧШЩ";
    if (consonants.find(ch) != std::wstring::npos) {
        return true;
    }
    return false;
}

// Функция для подсчета гласных в слове
int countVowels(const std::wstring& word) {
    int count = 0;
    for (wchar_t ch : word) {
        if (isVowel(ch)) {
            ++count;
        }
    }
    return count;
}

// Функция для обработки слова
std::wstring processWord(const std::wstring& word, bool& needToSort) {
    if (countVowels(word) >= 3) {
        needToSort = true;
        return word; // Возвращаем слово без изменений
    } else {
        needToSort = false;
        std::wstring result;
        for (wchar_t ch : word) {
            if (isConsonant(ch)) {
                result.push_back(ch);
                result.push_back(ch);   
            } else {
                if (isVowel(ch)) {
                    // Не брать
                } else {
                    // Брать 1 раз
                    result.push_back(ch);
                }
            }
        }
        return result;
    }
}

int splitToWords(const std::wstring& str, std::wstring words[], int max_words) {
    std::wistringstream wiss(str);
    std::wstring word;
    int count = 0;

    while (count < max_words && wiss >> word) {
        words[count++] = word;
    }

    return count; // Возвращает количество слов
}

bool reverseAlphabeticalOrder(const std::wstring& a, const std::wstring& b) {
    return a > b;
}

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    const int MAX_WORDS = 1000;
    //std::wcin.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
    std::wcout.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));

    std::wstring line = L"1на 2наа 3нааа 4наааа";
    std::wstring words[MAX_WORDS];
    std::wstring resultsSorted[MAX_WORDS];
    std::wstring resultsUnSorted[MAX_WORDS];
    int indexSorted = 0;
    int indexUnSorted = 0;

    int wordCount = splitToWords(line, words, MAX_WORDS);
    for (int i = 0; i < wordCount; ++i) {
        bool needToSort;
        std::wstring result = processWord(words[i], needToSort);
        if (needToSort) {
            resultsSorted[indexSorted++] = result;
        } else {
            resultsUnSorted[indexUnSorted++] = result;
        }
    }

    std::sort(resultsSorted, resultsSorted + indexSorted + 1, reverseAlphabeticalOrder);

    // Выводим результат 
    printStrSequence(resultsSorted, indexSorted + 1);
    printStrSequence(resultsUnSorted, indexUnSorted + 1);

    return 0;
}
