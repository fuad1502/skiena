#pragma once

#include <fstream>
#include <string>
#include <vector>

class FileHeap {
public:
  FileHeap(std::vector<std::string> fileNames);
  std::string extractMinimum();
  bool isEmpty();

private:
  class FileNode {
  private:
    std::ifstream fileStream;
    std::string head;

  public:
    FileNode(std::string fileName) {
      fileStream.open(fileName);
      fileStream >> head;
    }
    ~FileNode() { fileStream.close(); }
    bool isEmpty() { return fileStream.eof(); }
    std::string peakHead() { return head; }
    std::string extractHead() {
      std::string previousHead = head;
      fileStream >> head;
      return previousHead;
    }
  };
  std::vector<FileNode *> fileNodes;
  void bubbleDown(int idx);
  int heapChild(int idx);
};
