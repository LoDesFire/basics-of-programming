#include <gtest/gtest.h>
#include <string>

int CountInterestingInInterval(int);

TEST(FIRST, Subtest_1) {
    EXPECT_EQ(CountInterestingInInterval(12), 1);
}

TEST(FIRST, Subtest_2) {
    EXPECT_EQ(CountInterestingInInterval(99), 10);
}

TEST(FIRST, Subtest_3) {
    EXPECT_EQ(CountInterestingInInterval(999999993), 99999999);
}

int CountInterestingInInterval(int interval_end)
{
    return (interval_end + 1) / 10;
}