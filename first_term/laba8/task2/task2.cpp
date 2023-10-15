#include "include/task2.h"

int main() {
    std::ifstream fin("../task2/in.txt");
    std::ofstream fout("../task2/out.txt");
    fout << "---НАЧАЛО---\n";

    int menuOption = 1;
    setlocale(LC_ALL, "Russian");


    int arraySize;
    fin >> arraySize;
    trip *trips;
    trips = new trip[arraySize];
    inputStrF(trips, arraySize, 0, fin);

    while (menuOption)
    {
        menuOption = mainMenuInterfaceInput();
        action(menuOption, trips, arraySize, fin, fout);
    }

    //printStrF(trips, arraySize, fout);
    fout << "---КОНЕЦ---";
    fout.close();
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
    printf("7 - Вывести условие таски\n");
    printf("8 - Вывести информацию про автора\n");
    return inputLLCompare(0, 8, "Введите номер пункта: ");
}

void action(int n, trip *&trips, int &arraySize, std::ifstream &fin, std::ofstream &fout)
{
    writeEmptyLine();
    switch(n)
    {
        case 0:
            printf("Выход...");
            break;
        case 1:
            initStrF(trips, arraySize, fin);
            break;
        case 2:
            resizeStr(trips, arraySize);
            break;
        case 3:
            if (arraySize) {
                deleteStr(trips, arraySize);
            }
            else {
                printf("Введите хотя бы один рейс.\n");
            }
            break;
        case 4:
            if (arraySize) {
                changeStr(trips, arraySize);
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
                searchStr(trips, arraySize, fout);
            }
            else {
                printf("Введите хотя бы один рейс.\n");
            }
            break;
        case 7:
            writeInformationAboutTask(2, "\n\t| \tВ справочной автовокзала хранится расписание движения\n\t| автобусов. Для каждого рейса указаны его номер, тип\n\t| автобуса, пункт назначения, время отправления и\n\t| прибытия. Вывести информацию о рейсах, которыми можно\n\t| воспользоваться для прибытия в пункт назначения раньше\n\t| заданного времени.");
            break;
        case 8:
            writeInformationAboutAuthor();
            break;
        default:
            break;
    }
    writeEmptyLine();
}