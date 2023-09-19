#include "merge-sort.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void sortPartition(std::vector<std::string> &words, int begin, int end);
void mergePartition(std::vector<std::string> &words, int begin, int middle,
                    int end);

void MergeSort::sort(std::vector<std::string> &words) {
  sortPartition(words, 0, words.size() - 1);
}

void sortPartition(std::vector<std::string> &words, int begin, int end) {
  int middle = (begin + end) / 2;
  if (begin < middle) {
    sortPartition(words, begin, middle);
  }
  if (middle + 1 < end) {
    sortPartition(words, middle + 1, end);
  }
  mergePartition(words, begin, middle, end);
}

void mergePartition(std::vector<std::string> &words, int begin, int middle,
                    int end) {
  int firstPartitionIdx = begin;
  int secondPartitionIdx = middle + 1;
  std::vector<std::string> merged;

  while (firstPartitionIdx <= middle && secondPartitionIdx <= end) {
    // insert the smallest first
    if (words[firstPartitionIdx] < words[secondPartitionIdx]) {
      merged.push_back(words[firstPartitionIdx]);
      firstPartitionIdx++;
    } else {
      merged.push_back(words[secondPartitionIdx]);
      secondPartitionIdx++;
    }
  }

  if (firstPartitionIdx != middle + 1) {
    // push remaining elements in first partition
    merged.insert(merged.end(), words.begin() + firstPartitionIdx,
                  words.begin() + middle + 1);
  } else {
    // push remaining elements in second partition
    merged.insert(merged.end(), words.begin() + secondPartitionIdx,
                  words.begin() + end + 1);
  }

  std::copy(merged.begin(), merged.end(), words.begin() + begin);
}
