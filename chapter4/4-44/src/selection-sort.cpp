#include "selection-sort.hpp"
#include <algorithm>
#include <iostream>

void SelectionSort::sort(std::vector<std::string> &words) {
  for (int i = 0; i < words.size(); i++) {
    auto search_start_it = words.begin() + i;
    auto min_it = std::min_element(search_start_it, words.end());
    swap(*min_it, *search_start_it);
  }
}
