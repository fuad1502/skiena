#include "file-heap.hpp"
#include "gtest/gtest.h"

FileHeap::FileHeap(std::vector<std::string> fileNames) {
  // Fill fileNodes
  for (auto fileName : fileNames) {
    fileNodes.push_back(new FileNode(fileName));
  }
  // Heapify
  for (int i = fileNames.size() / 2; i >= 0; i--) {
    bubbleDown(i);
  }
}

std::string FileHeap::extractMinimum() {
  if (fileNodes.empty()) {
    return "";
  }

  std::string minimumString = fileNodes[0]->extractHead();
  if (fileNodes[0]->isEmpty()) {
    std::swap(fileNodes[0], fileNodes.back());
    fileNodes.pop_back();
  }

  if (!fileNodes.empty()) {
    bubbleDown(0);
  }

  return minimumString;
}

bool FileHeap::isEmpty() {
  return fileNodes.empty();
}

void FileHeap::bubbleDown(int idx) {
  int childIdx = heapChild(idx);
  int secondChildIdx = childIdx + 1;
  int minIdx = idx;
  auto minElement = fileNodes[minIdx]->peakHead();

  // Find the minimum element
  for (int i = childIdx; i <= secondChildIdx; i++) {
    if (i < fileNodes.size()) {
      if (fileNodes[i]->peakHead() < minElement) {
        minIdx = i;
        minElement = fileNodes[minIdx]->peakHead();
      }
    }
  }

  // Put the minimum on top of the others, continue bubbling down
  if (minIdx != idx) {
    std::swap(fileNodes[idx], fileNodes[minIdx]);
    bubbleDown(minIdx);
  }
}

int FileHeap::heapChild(int idx) { return (idx + 1) * 2 - 1; }
