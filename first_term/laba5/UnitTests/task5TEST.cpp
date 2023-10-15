#include <gtest/gtest.h>

using namespace std;

void task1(int, int, long long **&, long long **&, long double &, int &);

long long ** createDArray(int, int);

long long ** deleteDArray(int, long long **&);



TEST(task5, Subtest_1) {
    const int sizeI = 4, sizeJ = 6, length_cmp = 6;
    const long double ans_cmp = 3;
    long long
            a_t[sizeI][sizeJ] =
            {{0, 1, 0, 4, 0, 5},
             {0, 3, 0, 6, 0, 2},
             {0, 2, 0, 2, 0, 2},
             {0, 3, 0, 3, 0, 3}},
             b_t[1][length_cmp] = {1, 5, 3, 3, 3, 3};

    int length = 0;
    long double ans = 0;
    long long **a = createDArray(sizeI, sizeJ), **b;
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            a[i][j] = a_t[i][j];
        }
    }
    task1(sizeI, sizeJ, a, b, ans, length);
    ASSERT_EQ(length, length_cmp);
    if (length_cmp != 0) {
        ASSERT_EQ(ans, ans_cmp);
        for (int i = 0; i < length; i++) {
            ASSERT_EQ(b_t[0][i], b[0][i]);
        }
    }

    a = deleteDArray(sizeI, a);
}

TEST(task5, Subtest_2) {
    const int sizeI = 4, sizeJ = 6, length_cmp = 0;
    const long double ans_cmp = 3;
    long long
            a_t[sizeI][sizeJ] =
            {{0, 0, 0, 4, 0, 0},
             {0, 0, 0, 6, 0, 2},
             {0, 2, 0, 2, 0, 2},
             {0, 6, 0, 4, 0, 2}},
            b_t[1][length_cmp] = {};

    int length = 0;
    long double ans = 0;
    long long **a = createDArray(sizeI, sizeJ), **b;
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            a[i][j] = a_t[i][j];
        }
    }
    task1(sizeI, sizeJ, a, b, ans, length);
    ASSERT_EQ(length, length_cmp);
    if (length_cmp != 0) {
        ASSERT_EQ(ans, ans_cmp);
        for (int i = 0; i < length; i++) {
            ASSERT_EQ(b_t[0][i], b[0][i]);
        }
    }

    a = deleteDArray(sizeI, a);
}

TEST(task5, Subtest_3) {
    const int sizeI = 3, sizeJ = 3, length_cmp = 2;
    const long double ans_cmp = 2;
    long long
            a_t[sizeI][sizeJ] =
            {{1, 1, 3},
             {2, 2, 6},
             {7, 3, 9}},
            b_t[1][length_cmp] = {1, 3};

    int length = 0;
    long double ans = 0;
    long long **a = createDArray(sizeI, sizeJ), **b;
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            a[i][j] = a_t[i][j];
        }
    }
    task1(sizeI, sizeJ, a, b, ans, length);
    ASSERT_EQ(length, length_cmp);
    if (length_cmp != 0) {
        ASSERT_EQ(ans, ans_cmp);
        for (int i = 0; i < length; i++) {
            ASSERT_EQ(b_t[0][i], b[0][i]);
        }
    }

    a = deleteDArray(sizeI, a);
}


void task1(int _n, int _k, long long **&a, long long **&b, long double &sum, int &lengthB)
{
    int n = _n, k = _k;
    lengthB = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if ((j + 1) % 2 == 0 && a[i][j] % 2) {
                lengthB++;
            }
        }
    }

    if (lengthB) {
        int ptr = 0;
        sum = 0;
        b = createDArray(1, lengthB);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < k; j += 2) {
                if (a[i][j] % 2) {
                    b[0][ptr] = a[i][j];
                    sum += b[0][ptr];
                    ptr++;
                }
            }
        }
        sum /= lengthB;
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