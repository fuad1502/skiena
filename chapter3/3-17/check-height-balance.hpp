#include "cli-tree.hpp"

template<typename T>
bool isHeightBalanced(pTree<T> tree, int& height)
{
  if(tree == nullptr) {
    height = 0;
    return true;
  } else {
    int heightLeft, heightRight;
    bool res = isHeightBalanced(tree->left, heightLeft) && isHeightBalanced(tree->right, heightRight);
    res = res && (std::abs(heightLeft - heightRight) <= 1);
    height = 1 + std::max(heightLeft, heightRight);
    return res;
  }
}
