#include <cstdio>
#include <string>
#include "../../include/inputChecker.h"

enum types
{
    INTEGER,
    FLOAT,
};

bool _isNumberF(char c)
{
    return c >= '0' && c <= '9';
}

void _inputValue(char s[400], bool &isFail, bool isFloat) {
    bool isNumber = false, isDot = false, isE = false, isMinus = false, isPlus = false;
    char *p;
    int length = 0;

    isFail = false;
    p = s;

    while (*(p - 1) != '\n' && *(p - 1) != ' ' && *(p - 1) != EOF && !isFail) {

        char input = getchar();

        if ((_isNumberF(input) || ((input == '\n' || input == ' ' || input == EOF ||
                                    ((input == '.' && !isDot) || (input == 'e' && !isE)) && isFloat) &&
                                   _isNumberF(*(p - 1))) ||
             ((input == '-'  || input == '+' ) && !isNumber && !isPlus && !isMinus)) && (!isFloat && length < 21 || isFloat && length < 310)) {

            *p = input;

            if (_isNumberF(input)) isNumber = true;
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

void _checkLDValue(char s[400], bool &isFail)
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
            if (!isDot && _isNumberF(*ptr1))
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

void _checkLLValue(char s[400], bool &isFail)
{
    char checker[21] = "9223372036854775807\0";
    char *ptr1 = s;
    int length = 0;
    while (*ptr1 != '\0') {
        if (_isNumberF(*ptr1)) length++;
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

long double _inputLD(char* purpose = "значение: ")
{
    while (true) {
        char s[400];
        bool isFail = false;
        printf("%s", purpose);
        _inputValue(s, isFail, FLOAT);
        _checkLDValue(s, isFail);
        if (!isFail) {
            return std::stold(s); //STRING EXPLOIT
        }
        printf("\n");
        printf("---Ошибка ввода. Попробуйте ещё раз.---\n");
    }
}

long long _inputLL(char* purpose = "значение: ")
{
    while (true) {
        char s[400];
        bool isFail = false;
        printf("%s", purpose);
        _inputValue(s, isFail, INTEGER);
        _checkLLValue(s, isFail);
        if (!isFail) {
            return std::stoll(s); //STRING EXPLOIT
        }
        printf("\n");
        printf("---Ошибка ввода. Попробуйте ещё раз.---\n");
    }
}

long double inputLDCompare(long double interval_begin, long double interval_end, char* purpose = "значение: ") {
    long double num;
    while(true) {
        num = _inputLD(purpose);
        if (num <= interval_end && num >= interval_begin)
            return num;
        else {
            printf("\n");
            printf("---Число не входит в необходимый интервал. Попробуйте ещё раз.---\n");
        }
    }
}

long long inputLLCompare(long long interval_begin, long long interval_end, char* purpose = "значение: ") {
    long long num;
    while(true) {
        num = _inputLL(purpose);
        if (num <= interval_end && num >= interval_begin)
            return num;
        else {
            printf("\n");
            printf("---Число не входит в необходимый интервал. Попробуйте ещё раз.---\n");
        }
    }
}