# Калькулятор дробей
![Build Status](https://github.com/Jenyatta/fraction/actions/workflows/build.yml/badge.svg)

Программный комплекс для работы с дробями на C++.

## Возможности
- Создание дробей
- Арифметические операции (сложение, вычитание, умножение, деление)
- Сокращение дробей
- Конвертация в строку

## Сборка
1) Вызов меню: Win+R 
2) Открытие консоли: cmd
3) Перейти в папку проекта: cd C:\Users\username\Desktop\progect 
4) Компиляция библиотеки: g++ -c fraction.cpp -o fraction.o
5) Создание DLL: g++ -shared -o fraction.dll fraction.o
6) Компиляция программы: g++ main.cpp -o fractionapp.exe -L. -lfraction
7) Настройка консоли под русский язык: chcp 65001
8) Вводим нужные команды:
 8.1) Подсказка по функциям: fractionapp.exe --help
 8.2) Шаблон остальных операций: fractionapp.exe --op (операция)
9) Проверка результатов: notepad output.txt
