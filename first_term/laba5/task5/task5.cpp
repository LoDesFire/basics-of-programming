#include <cstdio>
#include <clocale>
#include <cmath>
#include "include/inputChecker.h"

void writeEmptyLine();
void writeLine();
void writeInformationAboutTask(int taskNum, char* standingOfTask);

long long ** createDArray(int, int);
void printDArray(int, int, long long **&);
long long ** deleteDArray(int, long long **&);


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
    int n = inputLLCompare(1, 2000, "Введите колчиество строк массива А: "), k = inputLLCompare(1, 2000, "Введите колчиество столбцов массива А: ");
    long long **a = createDArray(n, k);
    int lengthB = 0;
    printf("Введите двумерный массив А размером %d x %d:\n", n, k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            a[i][j] = inputLLCompare(INT32_MIN, INT32_MAX, "");
            if ((j + 1) % 2 == 0 && a[i][j] % 2) {
                lengthB++;
            }
        }
    }
    if (lengthB) {
        int ptr = 0;
        long double sum = 0;
        long long **b = createDArray(1, lengthB);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < k; j += 2) {
                if (a[i][j] % 2) {
                    b[0][ptr] = a[i][j];
                    sum += b[0][ptr];
                    ptr++;

                }
            }
        }
        printDArray(1, lengthB, b);
        printf("Среднее арифметическое: %.2Lf\n", sum / lengthB);
    }
    else {
        printf("Нет необходимых элементов.\n");
    }

    a = deleteDArray(n, a);
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
            writeInformationAboutTask(4, "\t| \tСоздать двумерный динамический массив вещественных\n\t| чисел. Определить, встречаются ли среди них элементы\n\t| с нулевым значением. Если встречаются такие элементы,\n\t| то определить их индексы и общее количество.\n\t| Переставить элементы этого массива в обратном порядке\n\t| и вывести на экран. Использовать функции.");
            break;
        case 3:
            writeEmptyLine();
            writeInformationAboutAuthor();
            break;
        default:
            break;
    }
}

long long ** createDArray(int n, int k)
{
    long long **b = new long long *[n];
    for (int i = 0; i < n; i++) {
        b[i] = new long long [k]{};
    }
    return b;
}

void printDArray(int n, int k, long long **&a)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++)
            printf("%lld ", a[i][j]);
        printf("\n");
    }
}

long long ** deleteDArray(int n, long long **&a)
{
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    return NULL;
}