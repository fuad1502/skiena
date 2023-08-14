#pragma once
#include "cli-tree.hpp"

template<typename T>
pTree<T> toBalancedTree(pTree<T> tree)
{
  // manually create balanced tree of length n
  int n = getNumberOfNodes(tree);
  pTree<T> balancedTree = std::shared_ptr<Tree<T>>(new Tree<T>);
  createBalancedChildTrees(balancedTree, n - 1);
  // create tree list of the balanced tree
  pList<pTree<T>> balancedListHead, balancedListTail;
  createListFromTree(balancedTree, balancedListHead, balancedListTail);
  // create tree list of the original tree
  pList<pTree<T>> listHead, listTail;
  createListFromTree(tree, listHead, listTail);
  // copy data from original to balanced tree
  pList<pTree<T>> node = listHead;
  pList<pTree<T>> balancedList = balancedListHead;
  while(node != nullptr) {
    balancedList->data->data = node->data->data;
    node = node->next;
    balancedList = balancedList->next;
  }
  // return balanced tree
  return balancedTree;
}

template<typename T>
void createBalancedChildTrees(pTree<T> tree, int n)
{
  if(n == 0) {
    ;
  } else if(n == 1) {
    tree->left = std::shared_ptr<Tree<T>>(new Tree<T>);
  } else {
    tree->left = std::shared_ptr<Tree<T>>(new Tree<T>);
    tree->right = std::shared_ptr<Tree<T>>(new Tree<T>);
    // create half (round up) of the remaining balanced trees to the left
    createBalancedChildTrees(tree->left, (n - 2 + 1) / 2);
    // create half (round down) of the remaining balanced trees to the right
    createBalancedChildTrees(tree->right, (n - 2) / 2);
  }
}

template<typename T>
void createListFromTree(pTree<T> tree, pList<pTree<T>>& head, pList<pTree<T>>& tail)
{
  if(tree == nullptr) {
    head = nullptr;
    tail = nullptr;
  } else {
    // recurse left
    pList<pTree<T>> leftHead, leftTail;
    createListFromTree(tree->left, leftHead, leftTail);
    // create node
    pList<pTree<T>> node = std::shared_ptr<List<pTree<T>>>(new List<pTree<T>>);
    node->data = tree;
    // recurse right
    pList<pTree<T>> rightHead, rightTail;
    createListFromTree(tree->right, rightHead, rightTail);
    // Connect node with left recursion
    if(leftTail != nullptr) {
      leftTail->next = node;
      node->previous = leftTail;
      head = leftHead;
    } else {
      head = node;
    }
    // Connect node with right recursion
    if(rightHead != nullptr) {
      node->next = rightHead;
      rightHead->previous = node;
      tail = rightTail;
    } else {
      tail = node;
    }
  }
}
