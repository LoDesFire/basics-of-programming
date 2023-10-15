#include <gtest/gtest.h>
#include <string>

void f(int *, int &, int);

TEST(FIRST, Subtest_1) {
    std::string s = "11113";
    int n = 123;

    int *a = new int[100]{};
    int b = 99;

    f(a, b, n);

    bool isZero = true;
    int ptr = 0;
    for (int i = b; i < 100; i++) {
        if (a[i]) isZero = false;
        if (ptr > s.length() - 1) ASSERT_TRUE(0);
        if (!isZero) EXPECT_EQ(s[ptr++] - '0', a[i]);
    }
}

TEST(FIRST, Subtest_2) {
    std::string s = "11233323323111312232";
    int n = 2000000000;

    int *a = new int[100]{};
    int b = 99;

    f(a, b, n);

    bool isZero = true;
    int ptr = 0;
    for (int i = b; i < 100; i++) {
        if (a[i]) isZero = false;
        if (ptr > s.length() - 1) ASSERT_TRUE(0);
        if (!isZero) EXPECT_EQ(s[ptr++] - '0', a[i]);
    }
}

TEST(FIRST, Subtest_3) {
    std::string s = "3";
    int n = 3;

    int *a = new int[100]{};
    int b = 99;

    f(a, b, n);

    bool isZero = true;
    int ptr = 0;
    for (int i = b; i < 100; i++) {
        if (a[i]) isZero = false;
        if (ptr > s.length() - 1) ASSERT_TRUE(0);
        if (!isZero) EXPECT_EQ(s[ptr++] - '0', a[i]);
    }
}

TEST(FIRST, Subtest_4) {
    std::string s = "223";
    int n = 27;

    int *a = new int[100]{};
    int b = 99;

    f(a, b, n);

    bool isZero = true;
    int ptr = 0;
    for (int i = b; i < 100; i++) {
        if (a[i]) isZero = false;
        if (ptr > s.length() - 1) ASSERT_TRUE(0);
        if (!isZero) EXPECT_EQ(s[ptr++] - '0', a[i]);
    }
}

 void f(int *a, int &b, int n) {
    bool isZero;
    while (n) { // -- O(log n) --
        a[b--] = n % 3;
        n /= 3;
    }

    n = 1;
    while (n) { // -- O(n^2) --
        isZero = true;
        for (int i = b; i < 100; i++) { // -- O(n) --
            if (a[i]) isZero = false;
            if (!a[i] && !isZero) {
                a[i] = 3;
                a[i - 1] -= 1;
                if (!a[i - 1]) n++;
            }
        }
        n--;
    }
}