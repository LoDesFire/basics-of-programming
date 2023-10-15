#include <gtest/gtest.h>
#include <string>

void ArToRim(std::string &, int);

TEST(FIRST, Subtest_1) {
    int n = 1213;
    std::string checker = "MCCXIII";
    std::string s;
    ArToRim(s, n);
    EXPECT_EQ(s, checker);
}

TEST(FIRST, Subtest_2) {
    int n = 3999;
    std::string checker = "MMMCMXCIX";
    std::string s;
    ArToRim(s, n);
    EXPECT_EQ(s, checker);
}

TEST(FIRST, Subtest_3) {
    int n = 99;
    std::string checker = "XCIX";
    std::string s;
    ArToRim(s, n);
    EXPECT_EQ(s, checker);
}

TEST(FIRST, Subtest_4) {
    int n = 1486;
    std::string checker = "MCDLXXXVI";
    std::string s;
    ArToRim(s, n);
    EXPECT_EQ(s, checker);
}

TEST(FIRST, Subtest_5) {
    int n = 16;
    std::string checker = "XVI";
    std::string s;
    ArToRim(s, n);
    EXPECT_EQ(s, checker);
}

void ArToRim(std::string &ans, int n) {
    int ptr;

    ptr = n/1000;
    ans.insert(0, ptr, 'M');
    n -= n / 1000 * 1000;

    if (n < 1000 && n > 899) {
        ans.insert(ptr, "M");
        ans.insert(ptr, "C");
        n -= 900;
    }
    else {
        if (n < 900 && n > 499) {
            ans.insert(ptr++, "D");
            n -= 500;
            ans.insert(ptr, n / 100, 'C');
            n -= n / 100 * 100;
        }
        else {
            if (n < 500 && n > 399) {
                ans.insert(ptr, "D");
                ans.insert(ptr, "C");
                n -= 400;
            }
            else {
                ans.insert(ptr, n / 100, 'C');
                n -= n / 100 * 100;
            }
        }
    }
    ptr = (int)ans.length();

    if (n < 100 && n > 89) {
        ans.insert(ptr, "C");
        ans.insert(ptr, "X");
        n -= 90;
    }
    else {
        if (n < 90 && n > 49) {
            ans.insert(ptr++, "L");
            n -= 50;
            ans.insert(ptr, n / 10, 'X');
            n -= n / 10 * 10;
        }
        else {
            if (n < 50 && n > 39) {
                ans.insert(ptr, "L");
                ans.insert(ptr, "X");
                n -= 40;
            }
            else {
                ans.insert(ptr, n / 10, 'X');
                n -= n / 10 * 10;
            }
        }
    }
    ptr = (int)ans.length();

    if (n == 9) {
        ans.insert(ptr, "X");
        ans.insert(ptr, "I");
    }
    else {
        if (n < 9 && n > 4) {
            ans.insert(ptr++, "V");
            n -= 5;
            ans.insert(ptr, n, 'I');
        }
        else {
            if (n == 4) {
                ans.insert(ptr, "V");
                ans.insert(ptr, "I");
            }
            else {
                ans.insert(ptr, n, 'I');
            }
        }
    }
}