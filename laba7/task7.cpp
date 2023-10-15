#include <iostream>

#define SIZE 200

bool check(int *b) {
    int *a = new int[SIZE - b[0]], ans;
    for (int i = 0; i < SIZE - b[0]; i++)
        a[i] = b[b[0] + i];

    int k = SIZE - b[0], length = SIZE - b[0];
    while (k--) {
        for (int i = 0; i < length; i++) {
            if (i + 1 < length) a[i + 1] += (a[i] % 2) * 10;
            a[i] /= 2;
        }

    }
    ans = a[length - 1] % 2;
    delete[] a;
    return !ans;
}

int main() {
    int **a = new int*[11000], start = 1, end = 1, position = 2, x;
    bool flag = true;
    std::cin >> x;
    for (int i = 0; i < 11000; i++)
        a[i] = new int[SIZE]{};
    a[1][0] = SIZE - 1;
    a[1][SIZE - 1] = 1;

    do {
        for (int i = start; i < end + 1; i++) {

            a[position][0] = a[i][0];
            for (int j = a[i][0]; j < SIZE; j++)
                a[position][j] = a[i][j];

            if (flag) a[position][a[position][0]] = 0;
            a[position][a[position][0]-- - 1] = 1;

            if (check(a[i])) {
                position++;
            }
        }
        flag = !flag;

        if (flag) {
            start = end + 1;
            end = position - 1;
        }
    } while (position <= x);

    for (int i = a[x][0]; i < SIZE; i++) {
        std::cout << a[x][i];
    }

    for (int i = 0; i < 11000; i++) {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}