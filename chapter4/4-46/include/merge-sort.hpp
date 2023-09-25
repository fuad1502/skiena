#pragma once

#include <string>
#include <vector>

namespace MergeSort {
void sort(std::vector<std::string> &words);
void sortPartition(std::vector<std::string> &words, int begin, int end);
void mergePartition(std::vector<std::string> &words, int begin, int middle,
                    int end);
} // namespace MergeSort
