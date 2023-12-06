// Лабораторная №1

#include <iostream>
#include <cmath>



int main()
{
    unsigned char v_uchar = 65;
    std::cout << "unsigned char значение: "  << v_uchar << " размер: " << sizeof(v_uchar)<< " байта, max: " << pow(2, sizeof(v_uchar) * 8) - 1 << std::endl;

    unsigned int v_uint = 65;
    std::cout << "unsigned int значение: "  << v_uint << " размер: " << sizeof(v_uint)<< " байта, max: " << pow(2, sizeof(v_uint) * 8) - 1 << std::endl;

    unsigned short v_ushort = 88;
    std::cout << "unsigned short значение: "  << v_ushort << " размер: " << sizeof(v_ushort)<< " байта, max: " << pow(2, sizeof(v_ushort) * 8) - 1 << std::endl;

    unsigned long long v_ulolo = -4096;
    std::cout << "unsigned long long значение: "  << v_ulolo << " размер: " << sizeof(v_ulolo)<< " байта, max: " << pow(2, sizeof(v_ulolo) * 8) - 1 << std::endl;

    char v_char = 'A';
    std::cout << "char значение: "  << v_char << " размер: " << sizeof(v_char)<< " байта " << pow(2, sizeof(char) * 8) - 1 << std::endl;

    int v_int = -1024;
    std::cout << "int значение: "  << v_int << " размер: " << sizeof(v_int)<< " байта, max: " << pow(2, sizeof(v_int) * 8) - 1 << std::endl;

    short v_short = -88;
    std::cout << "short значение: "  << v_short << " размер: " << sizeof(v_short)<< " байта, max: " << pow(2, sizeof(v_short) * 8) - 1 << std::endl;

    long long v_lolo = -4096;
    std::cout << "long long значение: "  << v_lolo << " размер: " << sizeof(v_lolo)<< " байта, max: " << pow(2, sizeof(v_lolo) * 8) - 1 << std::endl;

    float v_float = 10.45;
    std::cout << "float значение: " << v_float << " размер: " << sizeof(v_float) << " байта, max " << pow(2, sizeof(v_float * 8) - 1) << std::endl;

    double v_double = 10.45;
    std::cout << "double значение: " << v_double << " размер: " << sizeof(v_double) << " байта, max " << pow(2, sizeof(v_double * 8) - 1) << std::endl;


    //Задание 3
    v_uint = pow(2, sizeof(v_uint) * 8) - 1;
    unsigned int v_uint_overflow = v_uint + 1;
    std::cout << "max unsigned int: " << v_uint << ", переполнение: " << v_uint_overflow << std::endl;
    // max unsigned int: 4294967295, переполнение: 0
    // При переполнении максимального значения числа на 1 (характерный пример), все биты числа обнуляются, 
    // а единица "уходит" в разряд, находящийся за пределами (левее) ячейки памяти, выделенной под число
    
}