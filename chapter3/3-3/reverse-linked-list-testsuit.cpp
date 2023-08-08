#include <gtest/gtest.h>
#include "reverse-linked-list.hpp"

TEST(ReverseLinkedList, All)
{
  List<int> *head = new List<int> {-1, nullptr};
  List<int> *p = head;
  for(int i = 0; i < 10; i++) {
    p->next = new List<int> {i, nullptr};
    p = p->next;
  }
  reverse_linked_list(head);
  p = head;
  for(int i = 0; i <= 10; i++) {
    EXPECT_EQ(p->data, 9-i);
    p = p->next;
  }
}
