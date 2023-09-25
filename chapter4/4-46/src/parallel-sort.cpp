#include "parallel-sort.hpp"
#include "merge-sort.hpp"
#include <algorithm>
#include <cmath>
#include <thread>

namespace ParallelSort {
struct Partition {
  int begin;
  int end;
};
void sortPartitions(std::vector<std::string> &words,
                    std::vector<Partition> &partitions);
void mergePartitions(std::vector<std::string> &words,
                     std::vector<Partition> &partitions);
} // namespace ParallelSort

void ParallelSort::sort(std::vector<std::string> &words, int numberOfThreads) {
  std::vector<Partition> partitions;

  // Fill in partition boundaries
  for (int i = 0; i < numberOfThreads; i++) {
    int begin = i * (words.size() / numberOfThreads);
    int end = words.size() - 1;
    if (i < numberOfThreads - 1) {
      end = begin + words.size() / numberOfThreads - 1;
    }
    Partition p = {begin, end};
    partitions.push_back(p);
  }

  // Sort partitions
  sortPartitions(words, partitions);

  // Merge partitions
  mergePartitions(words, partitions);
}

void ParallelSort::sortPartitions(std::vector<std::string> &words,
                                  std::vector<Partition> &partitions) {
  std::vector<std::thread> threads;
  for (auto &p : partitions) {
    std::thread t{MergeSort::sortPartition, std::ref(words), p.begin, p.end};
    threads.push_back(std::move(t));
  }
  for (auto &t : threads) {
    t.join();
  }
}

void ParallelSort::mergePartitions(std::vector<std::string> &words,
                                   std::vector<Partition> &partitions) {
  if (partitions.size() == 1)
    return;

  std::vector<Partition> newPartitions;
  for (int i = 0; i < partitions.size(); i += 2) {
    if (i + 1 == partitions.size()) {
      newPartitions.push_back(partitions[i]);
    } else {
      MergeSort::mergePartition(words, partitions[i].begin, partitions[i].end,
                                partitions[i + 1].end);
      newPartitions.push_back({partitions[i].begin, partitions[i + 1].end});
    }
  }

  mergePartitions(words, newPartitions);
}
