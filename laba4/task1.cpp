#include <cstdio>
#include <string>
#include <clocale>


long long inputLL(long long interval_begin, long long interval_end, char* purpose);
void writeEmptyLine();
void writeLine();
void writeInformationAboutTask(int taskNum, char* standingOfTask);
int mainMenuInterfaceInput();
void task1();
void action(int n);
char* ending1(int k);

int main() {
    int menuOption = 1;
    setlocale(LC_ALL, "Russian");
    writeInformationAboutTask(1, "\t| \tВвести одномерный статический массив из K чисел.\n\t| Выполнить в соответствии с номером варианта\n\t| индивидуальное задание и вывести на экран исходные\n\t| данные и полученный результат.\n\t| \tОпределить количество инверсий в массиве (таких пар\n\t| элементов,в которых большее значение находится слева\n\t| от меньшего).");

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
    long long k = inputLL(1, 100, "размер массива(от 1 до 100): "), prev = LLONG_MIN, ans = 0, i = 1;
    while (k) {
        int tmp = inputLL(LLONG_MIN, LLONG_MAX, (char *)("элемент №" + std::to_string(i) + ": ").c_str());
        if (prev > tmp) ans++;
        prev = tmp;
        k--;
        i++;
    }
    printf("Всего %lld %s\n", ans, ending1(ans));
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
    printf("Автор: Шумский Даниил Сергеевич\n");
    printf("Вариант: 12\n");
    printf("Задание №%d\n", taskNum);
    printf("Условие: \n");
    printf("%s\n", standingOfTask);
    printf("\t");
    writeLine();
}

int mainMenuInterfaceInput()
{
    writeEmptyLine();
    printf("---Меню---\n");
    printf("0 - Выход\n");
    printf("1 - Выполнить задание\n");
    return  inputLL(0, 1, "номер пункта: ");
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
        default:
            break;
    }
}

char* ending1(int k)
{
    char* res;
    k %= 100;
    if (k >= 11 && k <= 14) res = "инверсий";
    else {
        k %= 10;
        switch (k) {
            case 1:
                res = "инверсия";
                break;
            case 2:
            case 3:
            case 4:
                res = "инверсии";
                break;
            default:
                res = "инверсий";
                break;
        }
    }
    return res;
}

enum types
{
    INTEGER,
    FLOAT,
};

bool isNumberF(char c)
{
    return c >= '0' && c <= '9';
}

void inputValue(char s[400], bool &isFail, bool isFloat) {
    bool isNumber = false, isDot = false, isE = false, isMinus = false, isPlus = false;
    char *p;
    int length = 0;

    isFail = false;
    p = s;

    while (*(p - 1) != '\n' && *(p - 1) != ' ' && *(p - 1) != EOF && !isFail) {

        char input = getchar();

        if ((isNumberF(input) || ((input == '\n' || input == ' ' || input == EOF ||
                                   ((input == '.' && !isDot) || (input == 'e' && !isE)) && isFloat) &&
                                  isNumberF(*(p - 1))) ||
             ((input == '-'  || input == '+' ) && !isNumber && !isPlus && !isMinus)) && (!isFloat && length < 21 || isFloat && length < 310)) {

            *p = input;

            if (isNumberF(input)) isNumber = true;
            if (input == '.') isDot = true;
            if (input == '-') isMinus = true;
            if (input == '+') isPlus = true;
            if (input == 'e') {
                isE = true;
                isDot = true;
                isNumber = false;
                isMinus = false;
                isPlus = false;
            }

            p++;
            length++;

        } else {

            while (input != '\n' && input != ' ' && input != EOF) {
                isFail = true;
                input = getchar();
            }
        }
    }

    *(--p) = '\0';
}

void checkLLValue(char s[400], bool &isFail)
{
    char checker[21] = "9223372036854775807\0";
    char *ptr1 = s;
    int length = 0;
    while (*ptr1 != '\0') {
        if (isNumberF(*ptr1)) length++;
        ptr1++;
    }
    if (length > 19)
    {
        isFail = true;
        return;
    }
    if (length == 19) {
        ptr1 = s;
        char *ptr2 = checker;
        if (*s == '-') {
            ptr1++;
            checker[18] = '8';
        }
        while (*ptr1 != '\0')
        {
            if (*ptr1 < *ptr2)
                return;
            if (*ptr1 == *ptr2) {
                ptr1++;
                ptr2++;
            }
            if (*ptr1 > *ptr2) {
                isFail = true;
                return;
            }
        }
    }
}

long long inputLL(long long interval_begin, long long interval_end, char* purpose = "значение: ")
{
    while (true) {
        char s[400];
        long long res;
        bool isFail = false;
        printf("Введите %s", purpose);
        inputValue(s, isFail, INTEGER);
        checkLLValue(s, isFail);
        if (!isFail) {
            res = std::stoll(s); //STRING EXPLOIT
            if (res <= interval_end && res >= interval_begin)
                return res;
        }
        writeEmptyLine();
        printf("---Ошибка ввода. Попробуйте ещё раз.---\n");
    }
}

