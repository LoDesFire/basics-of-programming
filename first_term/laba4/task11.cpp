#include <cstdio>
#include <string>
#include <clocale>
#include <ctime>


long long inputLLCompare(long long interval_begin, long long interval_end, char* purpose);
long double inputLDCompare(long double interval_begin, long double interval_end, char* purpose);
char inputC(char c1, char c2, char* purpose);

void writeEmptyLine();
void writeLine();
void writeInformationAboutTask(int taskNum, char* standingOfTask);

int mainMenuInterfaceInput();
void action(int n);

int main() {
    int menuOption = 1;
    setlocale(LC_ALL, "Russian");
    writeInformationAboutTask(11, "\t| \tНа вход подаётся поле для игры в \"сапёр\" размером\n\t| n*m символов, где символ '.' означает пустое место, а\n\t| символ '*' - бомбу. Требуется дополнить это поле\n\t| числами, как в оригинальной игре.\n\t| \tВыделение памяти через функции языка С.");

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
    int n = inputLLCompare(1, 2000, "Введите высоту поля: "), m = inputLLCompare(1, 2000, "Введите ширину поля: ");
    int **a = (int **)malloc(sizeof(int *) * n);
    int key[8][2] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};
    printf("Введите минное поле(мина - '*', поле - '.'): \n");
    for (int i = 0; i < n; i++) {
        a[i] = (int *) malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++) {
            char tmp = inputC('.', '*', "");
            if (tmp == '.') a[i][j] = 0;
            else a[i][j] = -1;
        }
    }
    getchar();


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == -1) {
                for (int k = 0; k < 8; k++) {
                    if (i + key[k][0] < n && i + key[k][0] >= 0 && j + key[k][1] < m && j + key[k][1] >= 0 && a[i + key[k][0]][j + key[k][1]] != -1) a[i + key[k][0]][j + key[k][1]]++;
                }
            }
        }
    }

    writeEmptyLine();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == -1) printf("* ");
            else printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    writeEmptyLine();
    for (int i = 0; i < n; i++) {
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

void inputVChar(char& c1, char c2, bool &isFail, bool &isGap) {
    bool isChar = false;

    isFail = false;
    isGap = false;
    char input = '0';

    while (input != '\n' && input != ' ' && input != EOF && !isFail && !isChar) {

        input = getchar();

        if (input == c1 || input == c2) {
            c1 = input;
            isChar = true;
        }
        else {
            isFail = true;
            if (input == '\n' || input == ' ' || input == EOF) {
                isFail = false;
                isGap = true;
            }
        }
    }
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

char inputC(char c1, char c2, char* purpose = "значение: ")
{
    while (true) {
        bool isFail = false, isGap = false;
        printf("%s", purpose);
        inputVChar(c1, c2, isFail, isGap);
        if (!isFail && !isGap) {
            return c1; //STRING EXPLOIT
        }
        if (!isGap) {
            writeEmptyLine();
            printf("---Ошибка ввода. Попробуйте ещё раз.---\n");
        }
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


