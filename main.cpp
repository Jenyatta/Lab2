#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>
#include "fraction.h"

using namespace std;

// ������� ��� ����������� ���������� ����������
void showHelp() {
    cout << "��������� �������:" << endl;
    cout << "  --help       �������� ��� ����" << endl;
    cout << "  --op <��������>  ��������� ��������:" << endl;
    cout << "     create    ������� �����" << endl;
    cout << "     add       ������� ��� �����" << endl;
    cout << "     sub       ������� ��� �����" << endl;
    cout << "     mul       �������� ��� �����" << endl;
    cout << "     div       ��������� ��� �����" << endl;
    cout << "     reduce    ��������� �����" << endl;
    cout << "     print     ������� �����" << endl;
}

// ������� ������ ������� ������ �� ����� input.txt
vector<string> readInputData() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        throw runtime_error("�� ������� ������� ���� input.txt");
    }

    vector<string> tokens;
    string token;
    while (inputFile >> token) {
        tokens.push_back(token);
    }
    inputFile.close();
    
    return tokens;
}

// ������� ������ ���������� � ���� output.txt
void writeOutputData(const string& result) {
    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        throw runtime_error("�� ������� ������� ���� output.txt");
    }
    outputFile << result;
    outputFile.close();
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    locale::global(locale(""));

    // ���� ��� ���������� ��������� ������, �������� ������ � �����
    if (argc == 1) {
        showHelp();
        return 0;
    }

    string operation;
    bool hasOperation = false;

    // ��������� ���������� ��������� ������
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "--help") {
            showHelp();
            return 0;
        } else if (arg == "--op") {
            if (i + 1 < argc) {
                operation = argv[++i];
                hasOperation = true;
            } else {
                cerr << "������: ����� --op ��������� ������� ��������" << endl;
                showHelp();
                return 1;
            }
        }
    }

    // ���� �� ������� ��������, �������� ������ � �����
    if (!hasOperation) {
        showHelp();
        return 0;
    }

    try {
        vector<string> inputData = readInputData();
        string result;
if (operation == "create") {
            if (inputData.size() < 2) throw runtime_error("����� 2 �����");
            Fraction f = createFraction(stoi(inputData[0]), stoi(inputData[1]));
            result = fractionToString(f);
        }
        else if (operation == "add") {
            if (inputData.size() < 4) throw runtime_error("����� 4 �����");
            Fraction a = createFraction(stoi(inputData[0]), stoi(inputData[1]));
            Fraction b = createFraction(stoi(inputData[2]), stoi(inputData[3]));
            result = fractionToString(addFractions(a, b));
        }
        else if (operation == "sub") {
            if (inputData.size() < 4) throw runtime_error("����� 4 �����");
            Fraction a = createFraction(stoi(inputData[0]), stoi(inputData[1]));
            Fraction b = createFraction(stoi(inputData[2]), stoi(inputData[3]));
            result = fractionToString(subtractFractions(a, b));
        }
        else if (operation == "mul") {
            if (inputData.size() < 4) throw runtime_error("����� 4 �����");
            Fraction a = createFraction(stoi(inputData[0]), stoi(inputData[1]));
            Fraction b = createFraction(stoi(inputData[2]), stoi(inputData[3]));
            result = fractionToString(multiplyFractions(a, b));
        }
        else if (operation == "div") {
            if (inputData.size() < 4) throw runtime_error("����� 4 �����");
            Fraction a = createFraction(stoi(inputData[0]), stoi(inputData[1]));
            Fraction b = createFraction(stoi(inputData[2]), stoi(inputData[3]));
            result = fractionToString(divideFractions(a, b));
        }
        else if (operation == "reduce") {
            if (inputData.size() < 2) throw runtime_error("����� 2 �����");
            Fraction f = createFraction(stoi(inputData[0]), stoi(inputData[1]));
            result = fractionToString(reduceFraction(f));
        }
        else if (operation == "print") {
            if (inputData.size() < 2) throw runtime_error("����� 2 �����");
            Fraction f = createFraction(stoi(inputData[0]), stoi(inputData[1]));
            cout << "���������: " << fractionToString(f) << endl;
            return 0;
        }
        else {
            throw runtime_error("����������� ��������: " + operation);
        }

        writeOutputData(result);
        cout << "��������� ������� � output.txt" << endl;

    } catch (const exception& e) {
        cerr << "������: " << e.what() << endl;
        return 1;
    }

    return 0;
}