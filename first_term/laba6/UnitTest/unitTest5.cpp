#include <gtest/gtest.h>
#include <string>

long long func(long long, long long, std::string &, std::string &);

TEST(FIRST, Subtest_1) {
    std::string s1 = "cup",
    s2 = "russia";
    EXPECT_EQ(func(14, 1000, s1, s2), 752);
}

TEST(INTERSECTION, twice) {
    std::string s1 = "cuprus",
            s2 = "ruscup";
    EXPECT_EQ(func(9, 1000, s1, s2), 2);
}

TEST(INTERSECTION, full) {
    std::string s1 = "cup",
            s2 = "cup";
    EXPECT_EQ(func(3, 1000, s1, s2), 1);
}

TEST(INTERSECTION, once) {
    std::string s1 = "pup",
            s2 = "pup";
    EXPECT_EQ(func(5, 1000, s1, s2), 1);
}

TEST(INTERSECTION, zero) {
    std::string s1 = "qup",
            s2 = "qup";
    EXPECT_EQ(func(5, 1000, s1, s2), 0);
}

TEST(INTERSECTION, not_full) {
    std::string s1 = "abc",
            s2 = "ab";
    EXPECT_EQ(func(3, 1000, s1, s2), 1);
}

long long binpow(long long n, long long pow, long long m)
{
    long long res = 1;
    while (pow) {
        if (pow & 1) {
            res = (res * n) % m;
            pow--;
        }
        else {
            pow >>= 1;
            n = (n * n) % m;
        }
    }
    return res % m;
}

long long func(long long L, long long m, std::string &s1, std::string &s2)
{
    long long freeSym, ans = 0;
    freeSym = L - (long long)s1.length() - (long long)s2.length();
    if (freeSym >= 0) {
        ans = binpow(26, freeSym, m);
        if (s1 != s2) ans = (ans * 2) % m;
    }
    else {
        std::string s1_part, s2_part;

        if ((long long)s1.length() + freeSym >= 0 && (long long)s2.length() + freeSym >= 0) {
            s1_part = s1.substr(s1.length() + freeSym);
            s2_part = s2.substr(s2.length() + freeSym);
            if (s2.substr(0, -freeSym) == s1_part)
                ans += 1;
            if (s1.substr(0, -freeSym) == s2_part && s1 != s2)
                ans += 1;
        }
    }

    return ans % m;
    return 0;
}