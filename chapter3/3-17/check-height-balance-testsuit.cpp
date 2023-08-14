#include <gtest/gtest.h>
#include "check-height-balance.hpp"
#include "transform-balanced-tree.hpp"

TEST(CheckHeightBalance, All)
{
  DictTree<int> dict;
  dict.insert(1);
  dict.insert(2);
  dict.insert(3);
  dict.insert(4);
  dict.insert(5);
  pTree<int> tree = toBalancedTree(dict.data());
  int height;
  EXPECT_FALSE(isHeightBalanced(dict.data(), height));
  EXPECT_EQ(height, 5);
  EXPECT_TRUE(isHeightBalanced(tree, height));
  EXPECT_EQ(height, 3);
}
