#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>
#include "fraction.h"

using namespace std;

// Функция для отображения справочной информации
void showHelp() {
    cout << "Доступные команды:" << endl;
    cout << "  --help       показать это меню" << endl;
    cout << "  --op <операция>  выполнить операцию:" << endl;
    cout << "     create    создать дробь" << endl;
    cout << "     add       сложить две дроби" << endl;
    cout << "     sub       вычесть две дроби" << endl;
    cout << "     mul       умножить две дроби" << endl;
    cout << "     div       разделить две дроби" << endl;
    cout << "     reduce    сократить дробь" << endl;
    cout << "     print     вывести дробь" << endl;
}

// Функция чтения входных данных из файла input.txt
vector<string> readInputData() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        throw runtime_error("Не удалось открыть файл input.txt");
    }

    vector<string> tokens;
    string token;
    while (inputFile >> token) {
        tokens.push_back(token);
    }
    inputFile.close();
    
    return tokens;
}

// Функция записи результата в файл output.txt
void writeOutputData(const string& result) {
    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        throw runtime_error("Не удалось открыть файл output.txt");
    }
    outputFile << result;
    outputFile.close();
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    locale::global(locale(""));

    // Если нет аргументов командной строки, показать помощь и выйти
    if (argc == 1) {
        showHelp();
        return 0;
    }

    string operation;
    bool hasOperation = false;

    // Обработка аргументов командной строки
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
                cerr << "Ошибка: после --op требуется указать операцию" << endl;
                showHelp();
                return 1;
            }
        }
    }

    // Если не указана операция, показать помощь и выйти
    if (!hasOperation) {
        showHelp();
        return 0;
    }

    try {
        vector<string> inputData = readInputData();
        string result;
if (operation == "create") {
            if (inputData.size() < 2) throw runtime_error("Нужно 2 числа");
            Fraction f = createFraction(stoi(inputData[0]), stoi(inputData[1]));
            result = fractionToString(f);
        }
        else if (operation == "add") {
            if (inputData.size() < 4) throw runtime_error("Нужно 4 числа");
            Fraction a = createFraction(stoi(inputData[0]), stoi(inputData[1]));
            Fraction b = createFraction(stoi(inputData[2]), stoi(inputData[3]));
            result = fractionToString(addFractions(a, b));
        }
        else if (operation == "sub") {
            if (inputData.size() < 4) throw runtime_error("Нужно 4 числа");
            Fraction a = createFraction(stoi(inputData[0]), stoi(inputData[1]));
            Fraction b = createFraction(stoi(inputData[2]), stoi(inputData[3]));
            result = fractionToString(subtractFractions(a, b));
        }
        else if (operation == "mul") {
            if (inputData.size() < 4) throw runtime_error("Нужно 4 числа");
            Fraction a = createFraction(stoi(inputData[0]), stoi(inputData[1]));
            Fraction b = createFraction(stoi(inputData[2]), stoi(inputData[3]));
            result = fractionToString(multiplyFractions(a, b));
        }
        else if (operation == "div") {
            if (inputData.size() < 4) throw runtime_error("Нужно 4 числа");
            Fraction a = createFraction(stoi(inputData[0]), stoi(inputData[1]));
            Fraction b = createFraction(stoi(inputData[2]), stoi(inputData[3]));
            result = fractionToString(divideFractions(a, b));
        }
        else if (operation == "reduce") {
            if (inputData.size() < 2) throw runtime_error("Нужно 2 числа");
            Fraction f = createFraction(stoi(inputData[0]), stoi(inputData[1]));
            result = fractionToString(reduceFraction(f));
        }
        else if (operation == "print") {
            if (inputData.size() < 2) throw runtime_error("Нужно 2 числа");
            Fraction f = createFraction(stoi(inputData[0]), stoi(inputData[1]));
            cout << "Результат: " << fractionToString(f) << endl;
            return 0;
        }
        else {
            throw runtime_error("Неизвестная операция: " + operation);
        }

        writeOutputData(result);
        cout << "Результат записан в output.txt" << endl;

    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }

    return 0;
}