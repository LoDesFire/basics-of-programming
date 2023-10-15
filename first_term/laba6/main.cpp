#include <iostream>
#include <stdio.h>
#include "include/header.h"
#include "include/inputChecker.h"

void writeEmptyLine();
void writeLine();

void task1();
void task2();
void task3();
void task4();

int mainMenuInterfaceInput();
void action(int n);

int main() {
    int menuOption = 1;
    setlocale(LC_ALL, "Russian");

    while (menuOption)
    {
        menuOption = mainMenuInterfaceInput();
        action(menuOption);
    }
    return 0;
}

void writeInformationAboutAuthor()
{
    printf("Автор: Шумский Даниил Сергеевич\n");
}

int mainMenuInterfaceInput()
{
    writeEmptyLine();
    printf("-----------------Меню-----------------\n");
    printf("-1 - Вывести информацию про автора\n");
    printf("0 - Выход\n");
    printf("1 - Выполнить 1-е задание\n");
    printf("2 - Выполнить 2-е задание\n");
    printf("3 - Выполнить 3-е задание\n");
    printf("4 - Выполнить 4-е задание\n");
    return  inputLLCompare(-1, 4, "\nВведите номер пункта: ");
}

void action(int n)
{
    switch(n)
    {
        case -1:
            writeEmptyLine();
            writeInformationAboutAuthor();
            break;
        case 0:
            writeEmptyLine();
            printf("Выход...");
            break;
        case 1:
            writeEmptyLine();
            task1();
            break;
        case 2:
            writeEmptyLine();
            task2();
            break;
        case 3:
            writeEmptyLine();
            task3();
            break;
        case 4:
            writeEmptyLine();
            task4();
            break;
        default:
            break;
    }
}


void task4()
{
    writeLine();
    std::string s;
    printf("4 - Реформа английского языка\n");
    writeEmptyLine();
    printf("Введите строки, которые нужно переводить (введите 0, чтобы выйти): \n");
    while (s != "0" && getline(std::cin, s)) {
        if (s != "0")
            makeTask4(s);
    }
    writeLine();
}

void task3()
{
    writeLine();
    printf("3 - Ввести строку и определить наибольшее записанное в этой строке целую\nчасть числа (без учета знака числа).\n");
    writeEmptyLine();
    printf("Вводите строку (введите ~, чтобы закончить): \n");
    char *input = new char[1000];

    makeTask3(input);

    delete[] input;
    writeLine();
}

void task2()
{
    writeLine();
    printf("2 - В тексте найти и напечатать символы, встречающиеся наиболее часто.\n");
    writeEmptyLine();
    int *ct = new int[513]{};
    for (int i = 0; i < 513; i++)
        ct[i] = i;
    int *a = new int[513]{};

    printf("Вводите текст (введите ~, чтобы закончить): \n");

    makeTask2(a, ct);

    delete[] a;
    delete[] ct;
    writeLine();
}

void task1() {
    writeLine();
    char *c = new char[81], length = 0;
    printf("1 - Дана строка, состоящая из слов, разделенных пробелами. Разбить исходную\nстроку на две подстроки, причем первая длиной k символов, если на k-ю\nпозицию попадает слово, то его следует отнести ко второй строке.\nЗначение k вводится с клавиатуры.\n");
    writeEmptyLine();
    printf("Введите строку: \n");
    while (length < 80 && c[length - 1] != '\n')
        c[length++] = getchar();
    c[length] = '\0';
    int k = inputLLCompare(1, length - 1,
                           (char *) ("Введите значение К (от 1 до " + std::to_string(length - 1) + "): ").c_str()) - 1;
    makeTask1(c, length, k);

    delete[] c;
    writeLine();
}

void writeEmptyLine()
{
    printf("\n");
}

void writeLine()
{
    printf("----------------------------------------------------------------------\n");
}