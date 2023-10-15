#include <gtest/gtest.h>
#include <string>

#define SIZE 200

void task7(std::string &, int);

TEST(FIRST, Subtest_1) {
    int n = 12;
    std::string s, ans = "10000";

    task7(s, n);
    EXPECT_EQ(ans, s);
}

TEST(FIRST, Subtest_2) {
    int n = 1;
    std::string s, ans = "1";

    task7(s, n);
    EXPECT_EQ(ans, s);
}


TEST(FIRST, Subtest_3) {
    int n = 10000;
    std::string s, ans = "11001000000011100110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

    task7(s, n);
    EXPECT_EQ(ans, s);
}

TEST(FIRST, Subtest_4) {
    int n = 5500;
    std::string s, ans = "11000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

    task7(s, n);
    EXPECT_EQ(ans, s);
}

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

void task7(std::string &s, int x) {
    int **a = new int*[11000], start = 1, end = 1, position = 2;
    bool flag = true;
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
        s += char(a[x][i] + '0');
    }

    for (int i = 0; i < 11000; i++) {
        delete[] a[i];
    }
    delete[] a;
}