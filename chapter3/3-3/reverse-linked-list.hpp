#pragma once

template<typename T>
struct List {
  T data;
  List* next;
};

void reverse_linked_list(List<int>*& head);
