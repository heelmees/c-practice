#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <algorithm>
#include <cwctype>
#include <sstream>

bool isVowel(const wchar_t ch) {
    std::wstring vowels = L"аеёиоуыэюяАЕЁИОУЫЭЮЯ";
    if (vowels.find(ch) != std::wstring::npos) {
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
std::wstring processWord(const std::wstring& word) {
    if (countVowels(word) >= 3) {
        return word; // Возвращаем слово без изменений
    } else {
        std::wstring result;
        for (wchar_t ch : word) {
            if (!isVowel(ch)) {
                result.push_back(ch);
                result.push_back(ch);   
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
    std::wcin.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
    std::wcout.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));

    std::wstring line = L"1на 2наа 3нааа 4наааа";
    std::wstring words[MAX_WORDS];
    std::wstring results[MAX_WORDS];
    int wordCount = splitToWords(line, words, MAX_WORDS);
    for (int i = 0; i < wordCount; ++i) {
        std::wstring result = processWord(words[i]);
        results[i] = result;
    }

    std::sort(results, results + wordCount, reverseAlphabeticalOrder);

    // Выводим результат, в нашем примере будет 4наааа 3нааа 22нн 11нн (1 и 2 не гласные :)  )
    for (const auto& w : results) {
        std::wcout << w << L' ';
    }

    return 0;
}
