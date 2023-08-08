#include <cstring>
#include <gtest/gtest.h>
#include "correct-parantheses.hpp"

TEST(CorrectParantheses, Correct)
{
  string parantheses = "{}";
  int loc;
  EXPECT_TRUE(correctParantheses(parantheses, loc));
  EXPECT_EQ(loc, -1);
  parantheses = "{{[]()}()}[]{}";
  EXPECT_TRUE(correctParantheses(parantheses, loc));
  EXPECT_EQ(loc, -1);
}

TEST(CorrectParantheses, Incorrect)
{
  string parantheses = "({)}";
  int loc;
  EXPECT_FALSE(correctParantheses(parantheses, loc));
  EXPECT_EQ(loc, 2);
}

TEST(CorrectParantheses, EdgeCases)
{
  string parantheses = "";
  int loc;
  EXPECT_TRUE(correctParantheses(parantheses, loc));
  EXPECT_EQ(loc, -1);
  parantheses = "{";
  EXPECT_FALSE(correctParantheses(parantheses, loc));
  EXPECT_EQ(loc, parantheses.size());
  parantheses = "{()";
  EXPECT_FALSE(correctParantheses(parantheses, loc));
  EXPECT_EQ(loc, parantheses.size());
}
