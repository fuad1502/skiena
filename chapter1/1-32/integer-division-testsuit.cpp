#include <gtest/gtest.h>
#include "integer-division.hpp"

TEST(IntegerDivision, Method1)
{
        EXPECT_EQ(integerDivision1(9, 3), 9 / 3);
        EXPECT_EQ(integerDivision1(10, 3), 10 / 3);
        EXPECT_EQ(integerDivision1(2, 3), 2 / 3);
        EXPECT_EQ(integerDivision1(10, -3), 10 / -3);
        EXPECT_EQ(integerDivision1(-10, -3), -10 / -3);
}

TEST(IntegerDivision, Method2)
{
        EXPECT_EQ(integerDivision2(9, 3), 9 / 3);
        EXPECT_EQ(integerDivision2(10, 3), 10 / 3);
        EXPECT_EQ(integerDivision2(2, 3), 2 / 3);
        EXPECT_EQ(integerDivision2(10, -3), 10 / -3);
        EXPECT_EQ(integerDivision2(-10, -3), -10 / -3);
}