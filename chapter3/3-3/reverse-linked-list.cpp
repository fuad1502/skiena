#include "reverse-linked-list.hpp"

void reverse_linked_list(List<int>*& head)
{
  if(head == nullptr)
  {
    return;
  }

  // set for first iteration
  List<int> *previous = nullptr;
  List<int> *current = head;
  while(current != nullptr) {
    List<int> *temp = current->next;
    current->next = previous;
    // set for next iteration
    previous = current;
    current = temp;
  }
  // set head
  head = previous;
}
