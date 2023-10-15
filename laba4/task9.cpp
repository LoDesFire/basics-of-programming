#include <cstdio>
#include <string>
#include <clocale>


long long inputLLCompare(long long interval_begin, long long interval_end, char* purpose);
long double inputLDCompare(long double interval_begin, long double interval_end, char* purpose);

void writeEmptyLine();
void writeLine();
void writeInformationAboutTask(int taskNum, char* standingOfTask);

int mainMenuInterfaceInput();
void action(int n);

int main() {
    int menuOption = 1;
    setlocale(LC_ALL, "Russian");
    writeInformationAboutTask(9, "\t| \tДан трёхмерный динамический массив размером n^3 целых\n\t| неотрицательных чисел. Необходимо определить диагональ\n\t| с наибольшей суммой чисел. Для обхода диагоналей нельзя\n\t| использовать вложенные циклы.\n\t| \tВыделение памяти через функции языка С.");

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
    short size = inputLLCompare(1, 2000, "Введите n для куба(от 1 до 2000): ");
    int ***a = (int ***)malloc(sizeof(int **) * size);
    for (int i = 0; i < size; i++) {
        a[i] = (int **)malloc(sizeof(int *) * size);
        printf("Введите %d матрицу(%dx%d) у куба:\n", i, size, size);
        for (int j = 0; j < size; j++) {
            a[i][j] = (int *)malloc(sizeof(int) * size);
            for (int k = 0; k < size; k++) {
                a[i][j][k] = inputLLCompare(INT_MIN, INT_MAX, "");
            }
        }
    }

    long long sum[4]{};
    for (int i = 0; i < size; i++)
        sum[0] += a[i][i][i];

    for (int i = 0; i < size; i++)
        sum[1] += a[i][i][size - 1 - i];

    for (int i = 0; i < size; i++)
        sum[2] += a[size - i - 1][i][i];

    for (int i = 0; i < size; i++)
        sum[3] += a[size - i - 1][i][size - i - 1];

    int ans = 0;
    for (int i = 0; i < 4; i++)
        if (sum[i] > sum[ans]) ans = i;

    writeEmptyLine();
    size--;
    switch(ans)
    {
        case 0:
            printf("Нужная диагональ начинается в (0, 0, 0) и заканчивается в (%d, %d, %d)\n", size, size, size);
            break;
        case 1:
            printf("Нужная диагональ начинается в (0, 0, %d) и заканчивается в (%d, %d, 0)\n", size, size, size);
            break;
        case 2:
            printf("Нужная диагональ начинается в (%d, 0, 0) и заканчивается в (0, %d, %d)\n", size, size, size);
            break;
        case 3:
            printf("Нужная диагональ начинается в (%d, 0, %d) и заканчивается в (0, %d, 0)\n", size, size, size);
            break;
    }
    writeEmptyLine();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            free(a[i][j]);
        }
        free(a[i]);
    }
    free(a);
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
    return  inputLLCompare(0, 1, "Введите номер пункта: ");
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
                input = getchar();

            }
            isFail = true;

        }
    }

    *(--p) = '\0';
}

void checkLDValue(char s[400], bool &isFail)
{
    if (isFail)
        return;
    char *ptr1 = s, exp[5], *ptr2 = exp;
    int checkPrecision = 0, eLength = 0, beforeDot = -1, zeros = 0;
    bool isE = false, isNumbers = false, isDot = false;
    while (*ptr1 != '\0')
    {
        if (isE) {
            *ptr2 = *ptr1;
            eLength++;
            ptr2++;
        }
        if (*ptr1 == 'e') isE = true;
        if (*ptr1 == '.') isDot = true;
        if (*ptr1 <= '9' && *ptr1 >= '1') isNumbers = true;

        if (!isE){
            if (isNumbers)
                checkPrecision++;
            if (!isDot && isNumberF(*ptr1))
                beforeDot++;
            if (!isNumbers && *ptr1 == '0')
                zeros++;
        }
        if (checkPrecision > 16 || eLength > 4) {
            isFail = true;
            break;
        }
        ptr1++;
    }
    if (isE && !isFail) {
        *ptr2 = '\0';
        if (abs(beforeDot - zeros + std::stoi(exp)) > 307) isFail = true;
    }
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

long double inputLD(char* purpose = "значение: ")
{
    while (true) {
        char s[400];
        long double res;
        bool isFail = false;
        printf("%s", purpose);
        inputValue(s, isFail, FLOAT);
        checkLDValue(s, isFail);
        if (!isFail) {
            return std::stold(s); //STRING EXPLOIT
        }
        writeEmptyLine();
        printf("---Ошибка ввода. Попробуйте ещё раз.---\n");
    }
}

long long inputLL(char* purpose = "значение: ")
{
    while (true) {
        char s[400];
        long long res;
        bool isFail = false;
        printf("%s", purpose);
        inputValue(s, isFail, INTEGER);
        checkLLValue(s, isFail);
        if (!isFail) {
            return std::stoll(s); //STRING EXPLOIT
        }
        writeEmptyLine();
        printf("---Ошибка ввода. Попробуйте ещё раз.---\n");
    }
}

long double inputLDCompare(long double interval_begin, long double interval_end, char* purpose = "значение: ") {
    long double num;
    while(true) {
        num = inputLD(purpose);
        if (num <= interval_end && num >= interval_begin)
            return num;
        else {
            writeEmptyLine();
            printf("---Число не входит в необходимый интервал. Попробуйте ещё раз.---\n");
        }
    }
}

long long inputLLCompare(long long interval_begin, long long interval_end, char* purpose = "значение: ") {
    long long num;
    while(true) {
        num = inputLL(purpose);
        if (num <= interval_end && num >= interval_begin)
            return num;
        else {
            writeEmptyLine();
            printf("---Число не входит в необходимый интервал. Попробуйте ещё раз.---\n");
        }
    }
}


