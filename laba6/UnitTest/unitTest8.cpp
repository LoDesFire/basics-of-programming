#include <gtest/gtest.h>
#include <string>

bool foo(std::string &, std::string &);

TEST(FIRST, Subtest_1) {
    std::string s1 = "solo",
    s2 = "sololos";
    EXPECT_EQ(foo(s1, s2), true);
}

TEST(FIRST, Subtest_2) {
    std::string s1 = "solo",
            s2 = "soloolos";
    EXPECT_EQ(foo(s1, s2), false);
}

TEST(SECOND, Subtest_1) {
    std::string s1 = "afsdghgd",
            s2 = "hgdsf";
    EXPECT_EQ(foo(s1, s2), true);
}

TEST(SECOND, Subtest_2) {
    std::string s1 = "aaab",
            s2 = "baaaa";
    EXPECT_EQ(foo(s1, s2), false);
}

TEST(SECOND, Subtest_3) {
    std::string s1 = "ab",
            s2 = "b";
    EXPECT_EQ(foo(s1, s2), true);
}

TEST(SECOND, Subtest_4) {
    std::string s1 = "asfgdhfjgkhjl",
            s2 = "asfgfsa";
    EXPECT_EQ(foo(s1, s2), true);
}

TEST(SECOND, Subtest_5) {
    std::string s1 = "asafgdhfjgkhjl",
            s2 = "asafgdhfjgkhjl";
    EXPECT_EQ(foo(s1, s2), true);
}

bool foo(std::string &s1, std::string &s2)
{
    std::string s3 = s1;
    s3.erase(s3.length() - 1);
    std::reverse(s3.begin(), s3.end());
    s1 += s3;
    while (s1.length() > 1) {
        if (s1.find(s2) != std::string::npos) {
            return true;
        }
        s1.erase(s1.length() / 2 - 1, 2);
    }
    if (s1 != s2)
        return false;
    else
        return true;
}