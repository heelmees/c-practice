#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <cctype>
#include <locale>
#include <codecvt>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cwctype>

wchar_t RARE_SYMBOL = L'`';

std::wstring toUpper(std::wstring& str) {
    for (auto& ch : str) {
        ch = std::towupper(ch);
    } 
    return str;
}

void countChars(std::wstring word, std::map<wchar_t, int>& charCount) {
    for (wchar_t ch : word) {
        if (iswalpha(ch)) {
            ++charCount[ch];
        }
    }
}

bool valueComparator(const std::pair<wchar_t, int>& a, const std::pair<wchar_t, int>& b) {
    return a.second > b.second;
}

bool isPopularChar(wchar_t ch, std::vector<std::pair<wchar_t, int>> vec){
    for (const std::pair<wchar_t, int> p: vec){
        if (p.first == ch) {
            return true;
        }
    }
    return false;
}

wchar_t isValidWord(std::wstring word, std::vector<std::pair<wchar_t, int>> vec){
    wchar_t popularChar = RARE_SYMBOL; // Редко встречающийся символ
    for (wchar_t ch: word) {
        if (isPopularChar(ch, vec)) {
            if (popularChar == RARE_SYMBOL) {
                popularChar = ch;
            } else {
                return RARE_SYMBOL;
            }
        }
    }
    return popularChar;
}

int main() {
    const int POPULAR_LETTERS = 10;
    std::map<wchar_t, int> charCount;
    std::wifstream inFile("input_task8_3.txt");
    std::wofstream outFile("output_task8_3.txt");
    std::wstring word;
    
    setlocale(LC_ALL, "en_US.UTF-8"); // Нужна для работы с многобайтами (wchar_t, std::wstring...)

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Не удалось открыть файлы." << std::endl;
        return 1;
    }

    //Прочитать файл по словам (можно было по строкам или целиком), 
    //Но дальше нам понадобится чтение по словам, поэтому пусть будет так
    //Посчитать кол-во вхождений каждой буквы
    while (inFile >> word) {
        countChars(word, charCount);
    }

    //Для сортировки по убыванию популярности используем вектор пар (wchat_t p.first, int p.second)
    std::vector<std::pair<wchar_t, int>> vec(charCount.begin(), charCount.end());
    //Отсортировать вектор, с нашей функцией сравнения
    std::sort(vec.begin(), vec.end(), valueComparator);
    // Обрезать вектор до 10 элементов
    if (vec.size() > POPULAR_LETTERS) {
        vec.resize(POPULAR_LETTERS);
    }

    // Очистка всех флагов ошибок
    inFile.clear();
    // Перемещение указателя в начало файла для повторного чтения
    inFile.seekg(0, std::ios::beg);

    while (inFile >> word) {
        wchar_t popularChar = isValidWord(word, vec);
        if (popularChar != RARE_SYMBOL) {
            std::wstring wc(1, popularChar);
            std::wstring ww = toUpper(word);
            outFile << ww << "(" << wc << ") ";
            std::wcout << ww << "(" << wc << ") ";
        } else {
            outFile << word << " ";
            std::wcout << word << " ";
        }
    }

    inFile.close();
    outFile.close();

    // Вход: море солнце ааа, ббб. ввв! ггг: ддд? ееежжжзззииийййккк
    // Выход: МОРЕ(е) СОЛНЦЕ(е) ааа, ббб. ввв! ггг: ддд? ееежжжзззииийййккк 

    return 0;
}
