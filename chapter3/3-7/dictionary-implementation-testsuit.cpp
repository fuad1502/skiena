#include <gtest/gtest.h>
#include "dictionary-implementation.hpp"

TEST(DictionaryImplementation, All)
{
  Dictionary<int> dict;
  Node<int> *node;
  // Test insertion
  dict.insert(1);
  dict.insert(2);
  dict.insert(0);
  dict.insert(-1);
  dict.insert(4);
  // Test minimum
  node = dict.minimum();
  EXPECT_EQ(node->data, -1);
  // Test maximum
  node = dict.maximum();
  EXPECT_EQ(node->data, 4);
  // Test search
  node = dict.search(4);
  EXPECT_EQ(node->data, 4);
  // Test deletion
  dict.remove(node);
  node = dict.search(4);
  EXPECT_EQ(node, nullptr);
  node = dict.search(1);
  dict.remove(node);
  node = dict.search(1);
  EXPECT_EQ(node, nullptr);
  // Test successor
  int reference[3] = {-1, 0, 2};
  int refIdx = 0;
  for(node = dict.minimum(); node != nullptr; node = dict.successor(node)) {
    EXPECT_EQ(node->data, reference[refIdx++]);
  }
  // Test predecessor
  refIdx = 2;
  for(node = dict.maximum(); node != nullptr; node = dict.predecessor(node)) {
    EXPECT_EQ(node->data, reference[refIdx--]);
  }
  // Null tests
  dict.remove(nullptr);
  dict.successor(nullptr);
  dict.predecessor(nullptr);
  // Destructor call
}
