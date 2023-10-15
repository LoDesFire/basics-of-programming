#include <cstdio>
#include "../../include/myLibrary.h"
#include "../../include/inputChecker.h"

long long * _createDArray(int n)
{
    long long *b = new long long [n];
    return b;
}

void _fillDArray(int n, long long *&a)
{
    printf("Введите %d элементов массива:\n", n);
    for (int i = 0; i < n; i++) {
        a[i] = inputLLCompare(-2147483648, 2147483647, "");
        a[i] *= a[i];
    }
}

long long _foo(long long *& a, int low, int high) {
    if (low < high) {
        //printf("%d - %d\n", low, high);
        long long res = _foo(a, low, low + (high - low)/3) + _foo(a, low + (high - low)/3 + 1, high);
        return res;
    }
    return a[low];
}

void _printDArray(int n, long long *&a)
{
    for (int i = 0; i < n; i++) {
        printf("%lld ", a[i]);
    }
    printf("\n");
}


long long * _deleteDArray(long long *&a)
{
    delete[] a;
    return NULL;
}

void doTheTask(int n)
{
    long long *a = _createDArray(n);
    _fillDArray(n, a);
    _printDArray(n, a);
    printf("\nСумма элементов: %lld\n", _foo(a, 0, n - 1));
    _deleteDArray(a);
}