#include "heap-sort.hpp"
#include <algorithm>

void createHeap(std::vector<std::string> &words);
void bubbleDown(std::vector<std::string> &words, int vectorSize, int idx);
void bubbleDown(std::vector<std::string> &words, int idx);
int heapChild(int idx);
void sortHeap(std::vector<std::string> &words);

void HeapSort::sort(std::vector<std::string> &words) {
  createHeap(words);
  sortHeap(words);
}

void createHeap(std::vector<std::string> &words) {
  for (int i = words.size() - 1; i >= 0; i--) {
    bubbleDown(words, i);
  }
}

void sortHeap(std::vector<std::string> &words) {
  for (int i = words.size() - 1; i > 0; i--) {
    swap(words[0], words[i]);
    bubbleDown(words, i, 0);
  }
}

void bubbleDown(std::vector<std::string> &words, int idx) {
  bubbleDown(words, words.size(), idx);
}

void bubbleDown(std::vector<std::string> &words, int vectorSize, int idx) {
  int childIdx = heapChild(idx);
  int secondChildIdx = childIdx + 1;
  int maxIdx = idx;
  auto maxElement = words[maxIdx];

  // find the minimum element
  for (int i = childIdx; i <= secondChildIdx; i++) {
    if (i < vectorSize) {
      if (words[i] > maxElement) {
        maxIdx = i;
        maxElement = words[maxIdx];
      }
    }
  }

  if (maxIdx != idx) {
    swap(words[idx], words[maxIdx]);
    bubbleDown(words, vectorSize, maxIdx);
  }
}

int heapChild(int idx) { return (idx + 1) * 2 - 1; }
