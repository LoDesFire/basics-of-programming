#include <cstdio>
#include <dlfcn.h>

void writeEmptyLine();
void writeLine();
void writeInformationAboutTask(int taskNum, char* standingOfTask);

int mainMenuInterfaceInput();
void action(int n);

char *mylib_path = "../lib/libmyLib.dylib";
void *mylib_handle = dlopen(mylib_path, RTLD_NOW);

using inputLLCompare_t = long long (*)(long long, long long, char*);
inputLLCompare_t inputLLCompare = (inputLLCompare_t)dlsym(mylib_handle, "inputLLCompare");

using doTheTask_t = void (*)(int);
doTheTask_t doTheTask = (doTheTask_t)dlsym(mylib_handle, "doTheTask");;

int main() {
    int menuOption = 1;

    while (menuOption)
    {
        menuOption = mainMenuInterfaceInput();
        action(menuOption);
    }

    dlclose(mylib_handle);
    return 0;
}
void task1()
{
    writeLine();
    doTheTask(inputLLCompare(1, 1000, "Введите размер массива(от 1 до 1000): \n"));
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
            writeInformationAboutTask(2, "\t| \tДля заданного одномерного массива X из N элементов\n\t| найти сумму выражений, вычисляемых по формуле X2.\n\t| Рекурсивную функцию применять каждый раз отдельно для\n\t| первой трети массива и для остальной части (2/3) массива.\n\t| Рекурсивные вызовы заканчивать, когда останется только\n\t| один или два элемента.");
            break;
        case 3:
            writeEmptyLine();
            writeInformationAboutAuthor();
            break;
        default:
            break;
    }
}