#include "fraction.h"
#include <stdexcept>  // Для обработки исключений
#include <algorithm>  // Для функции abs
#include <sstream>    // Для работы со строками

using namespace std;

// Функция вычисления наибольшего общего делителя (НОД)
// Использует алгоритм Евклида
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b); //ТЕРНАРНЫЙ ОПЕРАТОР
}

// Создает дробь, проверяя корректность и нормализуя знак
Fraction createFraction(int numerator, int denominator) {
    // Проверка на нулевой знаменатель
    if (denominator == 0) {
        throw invalid_argument("Знаменатель не может быть нулем"); // ИСКЛЮЧЕНИЕ
    }
    
    // Нормализация знака (знаменатель всегда положительный)
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    return {numerator, denominator};  
}

// Сокращает дробь, используя НОД
Fraction reduceFraction(Fraction f) {
    int common_divisor = gcd(abs(f.numerator), abs(f.denominator));
    return {
        f.numerator / common_divisor,
        f.denominator / common_divisor
    };
}

// Сложение дробей: (a/b) + (c/d) = (ad + bc)/bd
Fraction addFractions(Fraction a, Fraction b) {
    int num = a.numerator * b.denominator + b.numerator * a.denominator;
    int denom = a.denominator * b.denominator;
    return reduceFraction({num, denom});  // Сокращаем результат
}

// Вычитание дробей: (a/b) - (c/d) = (ad - bc)/bd
Fraction subtractFractions(Fraction a, Fraction b) {
    int num = a.numerator * b.denominator - b.numerator * a.denominator;
    int denom = a.denominator * b.denominator;
    return reduceFraction({num, denom});
}

// Умножение дробей: (a/b) * (c/d) = ac/bd
Fraction multiplyFractions(Fraction a, Fraction b) {
    int num = a.numerator * b.numerator;
    int denom = a.denominator * b.denominator;
    return reduceFraction({num, denom});
}

// Деление дробей: (a/b) / (c/d) = ad/bc
Fraction divideFractions(Fraction a, Fraction b) {
    // Проверка деления на ноль
    if (b.numerator == 0) {
        throw invalid_argument("Деление на ноль");
    }
    int num = a.numerator * b.denominator;
    int denom = a.denominator * b.numerator;
    return reduceFraction({num, denom});
}

// Преобразует дробь в строку
string fractionToString(Fraction f) {
    if (f.denominator == 1) {
        return to_string(f.numerator);  // Выводим как целое число
    }
    return to_string(f.numerator) + "/" + to_string(f.denominator);
}