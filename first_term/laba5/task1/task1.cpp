#include <cstdio>
#include <clocale>
#include <cmath>
#include "include/myLibrary.h"
#include "include/inputChecker.h"

void writeEmptyLine();
void writeLine();
void writeInformationAboutTask(int taskNum, char* standingOfTask);

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
void task1()
{
    writeLine();
    int n = inputLLCompare(1, 1500, "Введите число строк массива А, B: "), k = inputLLCompare(1, 1500, "Введите число столбцов массива А, B: ");
    long long **a = createDArray(n, k), **b = createDArray(n, k), **c = createDArray(1, floor(k / 2.0)), **d = createDArray(1, floor(k / 2.0));

    fillDArrays(n, k, a, b, c, d);
    printf("Массив A:\n");
    printDArray(n, k, a);
    writeEmptyLine();
    printf("Суммы четных столбцов массива А:\n");
    printDArray(1, floor(k / 2.0), c);

    writeEmptyLine();
    printf("Массив B:\n");
    printDArray(n, k, b);
    writeEmptyLine();
    printf("Суммы четных столбцов массива В:\n");
    printDArray(1, floor(k / 2.0), d);

    a = deleteDArray(n, a);
    b = deleteDArray(n, b);
    writeLine();
}

void writeEmptyLine()
{
    printf("\n");
}

void writeLine()
{
    printf("--------------------------------------------------------\n");
}

void writeInformationAboutTask(int taskNum, char* standingOfTask)
{
    printf("Задание №%d\n", taskNum);
    printf("Условие: \n");
    printf("%s\n", standingOfTask);
    printf("\t");
    writeLine();
}

void writeInformationAboutAuthor()
{
    printf("Автор: Шумский Даниил Сергеевич\n");
}

int mainMenuInterfaceInput()
{
    writeEmptyLine();
    printf("---Меню---\n");
    printf("0 - Выход\n");
    printf("1 - Выполнить задание\n");
    printf("2 - Вывести условие таски\n");
    printf("3 - Вывести информацию про автора\n");
    return  inputLLCompare(0, 3, "Введите номер пункта: ");
}

void action(int n)
{
    switch(n)
    {
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
            writeInformationAboutTask(1, "\t| \tСформировать два двумерных динамических массива-матрицы\n\t| A и B размерностью n×k. Размерность массивов ввести с\n\t| клавиатуры. Значения элементов a_ij определить согласно\n\t| выражениям. \n\t| \tЗначения элементов b_ij определить путем возведения\n\t| в квадрат соответствующих элементов массива-матрицы A.\n\t| Определить сумму элементов четных столбцов для каждого\n\t| массива-матрицы. На экран вывести массивы-матрицы А, В\n\t| и значения сумм. Использовать функции.");
            break;
        case 3:
            writeEmptyLine();
            writeInformationAboutAuthor();
            break;
        default:
            break;
    }
}