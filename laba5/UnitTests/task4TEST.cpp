#include <gtest/gtest.h>

using namespace std;

void task1(int, int, long long **&, int &);

long long ** createDArray(int, int);

long long ** deleteDArray(int, long long **&);


TEST(task4, Subtest_1) {
    const int sizeI = 3, sizeJ = 3, zeros_cmp = 0;
    long long
            a_t[sizeI][sizeJ] =
            {{1, 2, 3},
             {4, 5, 6},
             {7, 8, 9}};

    int zeros = 0;
    long long **a = createDArray(sizeI, sizeJ);
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            a[i][j] = a_t[i][j];
        }
    }

    task1(sizeI, sizeJ, a, zeros);
    ASSERT_EQ(zeros, zeros_cmp);
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            ASSERT_EQ(a[i][j], a_t[sizeI - i - 1][sizeJ - j - 1]);
        }
    }
    a = deleteDArray(sizeI, a);
}

TEST(task4, Subtest_2) {
    const int sizeI = 3, sizeJ = 3, zeros_cmp = 9;
    long long
            a_t[sizeI][sizeJ] =
            {{0, 0, 0},
             {0, 0, 0},
             {0, 0, 0}};

    int zeros = 0;
    long long **a = createDArray(sizeI, sizeJ);
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            a[i][j] = a_t[i][j];
        }
    }

    task1(sizeI, sizeJ, a, zeros);
    ASSERT_EQ(zeros, zeros_cmp);
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            ASSERT_EQ(a[i][j], a_t[sizeI - i - 1][sizeJ - j - 1]);
        }
    }
    a = deleteDArray(sizeI, a);
}

TEST(task4, Subtest_3) {
    const int sizeI = 4, sizeJ = 3, zeros_cmp = 5;
    long long
            a_t[sizeI][sizeJ] =
            {{2, 0, 2},
             {2, 0, 2},
             {0, 0, 0},
             {1, 1, -12}};

    int zeros = 0;
    long long **a = createDArray(sizeI, sizeJ);
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            a[i][j] = a_t[i][j];
        }
    }

    task1(sizeI, sizeJ, a, zeros);
    ASSERT_EQ(zeros, zeros_cmp);
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            ASSERT_EQ(a[i][j], a_t[sizeI - i - 1][sizeJ - j - 1]);
        }
    }
    a = deleteDArray(sizeI, a);
}


void task1(int _n, int _k, long long **&a, int &zeros)
{
    int n = _n, k = _k;
    zeros = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (a[i][j] == 0) zeros++;
        }
    }

    for (int i = 0; i < (n % 2 == 0 ? n / 2 : n / 2 + 1); i++) {
        for (int j = 0; j < k; j++) {
            if (i == n / 2 && j == k/2) break;
            long long tmp = a[n - i - 1][k - j - 1];
            a[n - i - 1][k - j - 1] = a[i][j];
            a[i][j] = tmp;
        }
    }
}

long long ** createDArray(int n, int k)
{
    long long **b = new long long *[n];
    for (int i = 0; i < n; i++) {
        b[i] = new long long [k]{};
    }
    return b;
}


long long ** deleteDArray(int n, long long **&a)
{
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    return NULL;
}