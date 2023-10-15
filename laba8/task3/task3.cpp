#include "include/task3.h"

int main() {
    FILE *f;
    f = fopen("../task3/dat.bin", "rb+");

    int menuOption = 1;
    setlocale(LC_ALL, "Russian");

    int arraySize;
    fseek(f, 0, SEEK_SET);
    fread(&arraySize, sizeof(arraySize), 1, f);

    trip *trips;
    trips = new trip[arraySize];
    initStrF(trips, arraySize, f);

    while (menuOption)
    {
        menuOption = mainMenuInterfaceInput();
        action(menuOption, trips, arraySize, f);
    }

    fclose(f);

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
    printf("2 - Добавить рейсы\n");
    printf("3 - Удалить рейс\n");
    printf("4 - Изменить рейс\n");
    printf("5 - Просмотр рейсов\n");
    printf("6 - Выполнить задание\n");
    printf("7 - Отсортировать список\n");
    printf("8 - Вывести условие таски\n");
    printf("9 - Вывести информацию про автора\n");
    return inputLLCompare(0, 9, "Введите номер пункта: ");
}

void action(int n, trip *&trips, int &arraySize, FILE *f)
{
    writeEmptyLine();
    switch(n)
    {
        case 0:
            printf("Выход...");
            break;
        case 1:
            initStrF(trips, arraySize, f);
            break;
        case 2:
            resizeStr(trips, arraySize, f); ///tutb
            break;
        case 3:
            if (arraySize) {
                deleteStr(trips, arraySize, f); ///tutb
            }
            else {
                printf("Введите хотя бы один рейс.\n");
            }
            break;
        case 4:
            if (arraySize) {
                changeStr(trips, arraySize, f); ///tutb
            }
            else {
                printf("Введите хотя бы один рейс.\n");
            }
            break;

        case 5:
            if (arraySize) {
                printStr(trips, arraySize);
            }
            else {
                printf("Введите хотя бы один рейс.\n");
            }
            break;
        case 6:
            if (arraySize) {
                searchStr(trips, arraySize);
            }
            else {
                printf("Введите хотя бы один рейс.\n");
            }
            break;
        case 7:
            if (arraySize > 1) {
                sortStr(trips, arraySize, f);
            }
            else {
                printf("Введите хотя бы два рейса.\n");
            }
            break;
        case 8:
            writeInformationAboutTask(2, "\n\t| \tВ справочной автовокзала имеется расписание движения автобусов. Для каждого рейса указаны его номер, тип автобуса, пункт назначения,\n\t| время отправления и прибытия. Вывести информацию о рейсах, которыми\n\t| можно воспользоваться для прибытия в пункт назначения раньше \n\t| заданного времени (сортировка выбором по убыванию).");
            break;
        case 9:
            writeInformationAboutAuthor();
            break;
        default:
            break;
    }
    writeEmptyLine();
}