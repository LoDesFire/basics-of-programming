#include <cstdio>
#include <string>

void makeTask3(char *input) {
    bool isNumber = false, isDot = false;
    char c = getchar();
    int ptr = 0, maxLength = 0, tmpLength = 0, arrSize = 0;

    while (c != '~' && ptr < 1000) {
        if (c <= '9' && c >= '1' && !isDot) {
            if (!isNumber) arrSize++;
            isNumber = true;
        }
        if (c > '9' || c < '0') {
            if (c == '.' && isNumber) isDot = true;
            else isDot = false;
            if (isNumber) {
                tmpLength = 0;
                input[ptr++] = ' ';
                isNumber = false;
            }
        }
        if (isNumber) {
            tmpLength++;
            input[ptr++] = c;
        }
        if (maxLength < tmpLength) maxLength = tmpLength;
        c = getchar();
    }
    c = getchar();
    input[ptr] = ' ';
    input[ptr + 1] = '\0';

    char **cs = new char*[arrSize];
    arrSize = 0;
    ptr = 0, tmpLength = 0;
    while (input[ptr] != '\0') {
        if (input[ptr] <= '9' && input[ptr] >= '0') {
            tmpLength++;
        }
        else {
            if (tmpLength == maxLength) {
                int i = 0;
                cs[arrSize++] = new char[maxLength];
                while (i != maxLength) {
                    cs[arrSize - 1][i] = input[ptr - maxLength + i];
                    i++;
                }
            }
            tmpLength = 0;
        }
        ptr++;
    }

    int maxArr = 0;
    for (int i = 1; i < arrSize; i++) {
        int j = 0;
        while (j < maxLength && maxArr != i) {
            if (cs[maxArr] < cs[j]) maxArr = i;
            j++;
        }
    }

    printf("Наибольшее целое число: %s\n", cs[maxArr]);

    for (int i = 0; i < arrSize; i++) {
        delete[] cs[i];
    }
    delete[] cs;
}