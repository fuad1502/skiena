#include "quick-sort.hpp"

void sortPartition(std::vector<std::string> &words, int begin, int end);

void QuickSort::sort(std::vector<std::string> &words) {
  sortPartition(words, 0, words.size() - 1);
}

void sortPartition(std::vector<std::string> &words, int begin, int end) {
  if (begin >= end) {
    return;
  }
  int pivotIdx = (begin + end) / 2;
  auto pivot = words[pivotIdx];
  int placeIdx = begin;
  // put all values smaller then the pivot to the left side
  for (int i = begin; i <= end; i++) {
    if (words[i] < pivot) {
      swap(words[i], words[placeIdx]);
      if (placeIdx == pivotIdx) {
        // Store the location where the pivot was moved to
        pivotIdx = i;
      }
      placeIdx++;
    }
  }
  // put pivot at the boundary
  swap(words[pivotIdx], words[placeIdx]);
  pivotIdx = placeIdx;
  // sort left and right partition
  sortPartition(words, begin, pivotIdx - 1);
  sortPartition(words, pivotIdx + 1, end);
}
