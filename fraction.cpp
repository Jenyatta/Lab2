#include "fraction.h"
#include <stdexcept>  // ��� ��������� ����������
#include <algorithm>  // ��� ������� abs
#include <sstream>    // ��� ������ �� ��������

using namespace std;

// ������� ���������� ����������� ������ �������� (���)
// ���������� �������� �������
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b); //��������� ��������
}

// ������� �����, �������� ������������ � ���������� ����
Fraction createFraction(int numerator, int denominator) {
    // �������� �� ������� �����������
    if (denominator == 0) {
        throw invalid_argument("����������� �� ����� ���� �����"); // ����������
    }
    
    // ������������ ����� (����������� ������ �������������)
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    return {numerator, denominator};  
}

// ��������� �����, ��������� ���
Fraction reduceFraction(Fraction f) {
    int common_divisor = gcd(abs(f.numerator), abs(f.denominator));
    return {
        f.numerator / common_divisor,
        f.denominator / common_divisor
    };
}

// �������� ������: (a/b) + (c/d) = (ad + bc)/bd
Fraction addFractions(Fraction a, Fraction b) {
    int num = a.numerator * b.denominator + b.numerator * a.denominator;
    int denom = a.denominator * b.denominator;
    return reduceFraction({num, denom});  // ��������� ���������
}

// ��������� ������: (a/b) - (c/d) = (ad - bc)/bd
Fraction subtractFractions(Fraction a, Fraction b) {
    int num = a.numerator * b.denominator - b.numerator * a.denominator;
    int denom = a.denominator * b.denominator;
    return reduceFraction({num, denom});
}

// ��������� ������: (a/b) * (c/d) = ac/bd
Fraction multiplyFractions(Fraction a, Fraction b) {
    int num = a.numerator * b.numerator;
    int denom = a.denominator * b.denominator;
    return reduceFraction({num, denom});
}

// ������� ������: (a/b) / (c/d) = ad/bc
Fraction divideFractions(Fraction a, Fraction b) {
    // �������� ������� �� ����
    if (b.numerator == 0) {
        throw invalid_argument("������� �� ����");
    }
    int num = a.numerator * b.denominator;
    int denom = a.denominator * b.numerator;
    return reduceFraction({num, denom});
}

// ����������� ����� � ������
string fractionToString(Fraction f) {
    if (f.denominator == 1) {
        return to_string(f.numerator);  // ������� ��� ����� �����
    }
    return to_string(f.numerator) + "/" + to_string(f.denominator);
}