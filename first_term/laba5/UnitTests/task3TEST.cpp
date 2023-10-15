#include <gtest/gtest.h>

using namespace std;

void task1(int, int, long long **&, long long **&, long long &, int &);

long long ** createDArray(int, int);

long long ** deleteDArray(int, long long **&);


TEST(task3, Subtest_1) {
    const int sizeI = 3, sizeJ = 3, length_cmp = 0;
    const long long ans_cmp = 1;
    long long ans,
            a_t[sizeI][sizeJ] =
            {{1, 2, 3},
             {4, 5, 6},
             {7, 8, 9}},
            b_t[length_cmp] = {};


    int length = 0;
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
            ASSERT_EQ(b[0][i], b_t[i]);
        }
        b = deleteDArray(1, b);
    }
    a = deleteDArray(sizeI, a);
}


TEST(TestGroupName, Subtest_2) {
    const int sizeI = 3, sizeJ = 3, length_cmp = 3;
    const long long ans_cmp = 120;
    long long ans,
            a_t[sizeI][sizeJ] =
            {{2, 3, 4},
             {5, 6, 7},
             {8, 9, 10}},
            b_t[length_cmp] = {2, 6, 10};


    int length = 0;
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
            ASSERT_EQ(b[0][i], b_t[i]);
        }
        b = deleteDArray(1, b);
    }
    a = deleteDArray(sizeI, a);
}

TEST(TestGroupName, Subtest_3) {
    const int sizeI = 3, sizeJ = 3, length_cmp = 3;
    const long long ans_cmp = -120;
    long long ans,
            a_t[sizeI][sizeJ] =
            {{-2, -3, -4},
             {-5, -6, -7},
             {-8, -9, -10}},
            b_t[length_cmp] = {-2, -6, -10};


    int length = 0;
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
            ASSERT_EQ(b[0][i], b_t[i]);
        }
        b = deleteDArray(1, b);
    }
    a = deleteDArray(sizeI, a);
}

void task1(int _n, int _k, long long **&a, long long **&b, long long &ans, int &lengthB)
{
    int n = _n, k = _k;
    lengthB = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (i == j && a[i][j] % 2 == 0) lengthB++;
        }
    }
    ans = 1;
    if (lengthB) {
        b = createDArray(1, lengthB);

        for (int i = 0, c = 0; i < (n < k ? n : k); i++)
            if (a[i][i] % 2 == 0) {
                b[0][c] = a[i][i];
                ans *= b[0][c];
                c++;
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