#include <gtest/gtest.h>
#include <string>

long long foo(std::string &);

TEST(FIRST, Subtest_1) {
    std::string s = "solo";
    EXPECT_EQ(foo(s), 12);
}

TEST(FIRST, Subtest_2) {
    std::string s = "asdsgfhajkhjdfkj";
    EXPECT_EQ(foo(s), 54486432000);
}


TEST(FIRST, Subtest_3) {
    std::string s = "Sooo";
    EXPECT_EQ(foo(s), 4);
}

TEST(FIRST, Subtest_4) {
    std::string s = "soso";
    EXPECT_EQ(foo(s), 6);
}

long long foo(std::string &s) {
    long long n = 0, a[513]{}, res = 1;
    for (int i = 0; i < s.length(); i++)
        res = (res * ++n) / ++a[s[i]];
    return res;
}
