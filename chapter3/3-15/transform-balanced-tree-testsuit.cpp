#include <gtest/gtest.h>
#include "transform-balanced-tree.hpp"

TEST(TransformBalancedTree, All)
{
  DictTree<int> dict;
  dict.insert(1);
  dict.insert(2);
  dict.insert(3);
  dict.insert(4);
  dict.insert(5);
  std::cout << "Before balanced: " << std::endl;
  std::cout << dict;
  pTree<int> balancedTree = toBalancedTree(dict.data());
  int unused1, unused2;
  std::cout << "After balanced: " << std::endl;
  std::cout << treeString(balancedTree, unused1, unused2);
}
