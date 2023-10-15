#include <cstdio>
#include <string>

void makeTask1(char *c, int length, int k) {
    char c1[81], c2[81];
    while (c[k] != ' ' && k > 0) k--;
    for (int i = 0; i < k; i++)
        c1[i] = c[i];
    c1[k] = '\0';
    if (k == 0) k = -1;
    for (int i = 0, j = k + 1; j < length; i++, j++)
        c2[i] = c[j];
    c2[length - k - 2] = '\0';
    printf("\nЯ раздедлиль, начальник: %s|%s\n", c1, c2);
}