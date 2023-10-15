#include <cstdio>
#include "../../include/myLibrary.h"

long long ** createDArray(int n, int k)
{
    long long **b = new long long *[n];
    for (int i = 0; i < n; i++) {
        b[i] = new long long [k]{};
    }
    return b;
}

void printDArray(int n, int k, long long **&a)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++)
            printf("%lld ", a[i][j]);
        printf("\n");
    }
}

void fillDArrays(int n, int k, long long **&a, long long **&b, long long **&c, long long **&d)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++) {
            if (i <= 3) a[i][j] = 2 * i * j * j - 2 * j;
            if (i > 3) a[i][j] = 2 * i * j - 2;
            if (j <= 9) a[i][j] = 2 * i * j - 2;
            if (j > 9) a[i][j] = 3 * i * j * j - 3 * j;
            b[i][j] = a[i][j] * a[i][j];

            if ((j + 1) % 2 == 0) {
                c[0][j / 2] += a[i][j];
                d[0][j / 2] += b[i][j];
            }
        }
}

long long ** deleteDArray(int n, long long **&a)
{
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    return NULL;
}