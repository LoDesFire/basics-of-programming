#include <cstdio>
#include <clocale>
#include "include/pattern.h"
#include "include/inputChecker.h"
#include "include/task1.h"

void action(int, flight *&, int &);

int main() {
    int menuOption = 1;
    setlocale(LC_ALL, "Russian");

    int arraySize = inputLLCompare(1, 100000, "Сколько рейсов вы хотите ввести: ");
    flight *flights;
    flights = new flight[arraySize];
    inputStr(flights, arraySize, 0);

    while (menuOption)
    {
        menuOption = mainMenuInterfaceInput();
        action(menuOption, flights, arraySize);
    }

    return 0;
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
    printf("Автор: Шумский Даниил Сергеевич, группа 253501\n");
}

int mainMenuInterfaceInput()
{
    writeEmptyLine();
    printf("---Меню---\n");
    printf("0 - Выход\n");
    printf("1 - Инициализировать данные\n");
    printf("2 - Вывести все данные\n");
    printf("3 - Дополнение массива\n");
    printf("4 - Поиск по пункту назначения\n");
    printf("5 - Удаление рейса\n");
    printf("6 - Изменение рейса\n");
    printf("7 - Сортировка списка\n");
    printf("8 - Вывести условие таски\n");
    printf("9 - Вывести информацию про автора\n");
    return inputLLCompare(0, 9, "Введите номер пункта: ");
}

void action(int n, flight *&flights, int &arraySize)
{
    writeEmptyLine();
    switch(n)
    {
        case 0:
            printf("Выход...");
            break;
        case 1:
            initStr(flights, arraySize);
            break;
        case 2:
            if (arraySize) {
                printStr(flights, arraySize);
            }
            else {
                printf("Введите хотя бы один рейс.\n");
            }
            break;
        case 3:
            resizeStr(flights, arraySize);
            break;
        case 4:
            if (arraySize) {
                searchStr(flights, arraySize);
            }
            else {
                printf("Введите хотя бы один рейс.\n");
            }
            break;
        case 5:
            if (arraySize) {
                deleteStr(flights, arraySize);
            }
            else {
                printf("Введите хотя бы один рейс.\n");
            }
            break;
        case 6:
            if (arraySize) {
                changeStr(flights, arraySize);
            }
            else {
                printf("Введите хотя бы один рейс.\n");
            }
            break;
        case 7:
            if (arraySize > 1) {
                sortStr(flights, arraySize);
            }
            else {
                printf("Введите хотя бы два рейса.\n");
            }
            break;
        case 8:
            writeInformationAboutTask(1, "\t| \tВ справочной аэропорта имеется расписание вылета\n\t| самолетов. Для каждого рейса указаны его номер, тип\n\t| самолета, пункт назначения, время вылета. Вывести все\n\t| номера рейсов, вылетающих в заданный пункт назначения\n\t| (быстрая сортировка по возрастанию).");
            break;
        case 9:
            writeInformationAboutAuthor();
            break;
        default:
            break;
    }
    writeEmptyLine();
}