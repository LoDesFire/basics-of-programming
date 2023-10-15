#include <gtest/gtest.h>
#include <string>

long long foo(std::string &);

TEST(FIRST, Subtest_1) {
    std::string s = "solo";
    EXPECT_EQ(foo(s), 4);
}

TEST(FIRST, Subtest_2) {
    std::string s = "asdsgfhajkhjdfkj";
    EXPECT_EQ(foo(s), 16);
}


TEST(FIRST, Subtest_3) {
    std::string s = "oooo";
    EXPECT_EQ(foo(s), -1);
}

TEST(FIRST, Subtest_5) {
    std::string s = "osso";
    EXPECT_EQ(foo(s), 3);
}

TEST(FIRST, Subtest_4) {
    std::string s = "soso";
    EXPECT_EQ(foo(s), 4);
}

long long foo(std::string &s) {
        bool isEq = true, isPal = true;
        for(int i = 0; i < s.length(); i++) {
            if (s[i] != s[s.length() - 1 - i]) isPal = false;
            if (i > 0 && s[i - 1] != s[i]) isEq = false;
        }

        if (isEq) {
            return -1;
        }
        else {
            if (isPal) return s.length() - 1;
            else return s.length();
        }
}
