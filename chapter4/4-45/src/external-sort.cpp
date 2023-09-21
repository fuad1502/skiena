#include "external-sort.hpp"
#include "file-heap.hpp"
#include "file-utility.hpp"
#include "merge-sort.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

namespace ExternalSort {
std::vector<std::string> createSortedTempFiles(std::string inputFileName,
                                               size_t workingMemoryInBytes);
void sortText(std::string inputFileName);
std::string stripFileNameExtension(std::string inputFileName);
} // namespace ExternalSort

void ExternalSort::sortText(std::string inputFileName,
                            std::string outputFileName,
                            size_t workingMemoryInBytes) {
  std::vector<std::string> tempFileNames =
      createSortedTempFiles(inputFileName, workingMemoryInBytes);

  FileHeap fileHeap(tempFileNames);

  std::ofstream outputFileStream(outputFileName);
  while (!fileHeap.isEmpty()) {
    outputFileStream << fileHeap.extractMinimum() << " ";
  }

  outputFileStream.close();
}

std::vector<std::string>
ExternalSort::createSortedTempFiles(std::string inputFileName,
                                    size_t workingMemoryInBytes) {
  // Define variables
  std::vector<std::string> tempFileNames;
  int currentTempFileIdx = 0;
  int currentTempFileSize = 0;

  // Create first temporary file
  std::string tempFileName = stripFileNameExtension(inputFileName) + "." +
                             std::to_string(currentTempFileIdx) + ".txt";
  tempFileNames.push_back(tempFileName);
  std::ofstream tempFileStream(tempFileName);

  // Put words from the input file to temporary files
  std::ifstream inputFileStream(inputFileName);
  std::string word;
  while (inputFileStream >> word) {
    if ((currentTempFileSize + word.length()) > workingMemoryInBytes) {
      // Sort temporary file
      tempFileStream.close();
      sortText(tempFileName);
      // Create next temporary file
      currentTempFileIdx++;
      currentTempFileSize = 0;
      tempFileName = stripFileNameExtension(inputFileName) + "." +
                     std::to_string(currentTempFileIdx) + ".txt";
      tempFileNames.push_back(tempFileName);
      tempFileStream.open(tempFileName);
    }
    tempFileStream << word << " ";
    currentTempFileSize += word.length();
  }

  tempFileStream.close();
  return tempFileNames;
}

void ExternalSort::sortText(std::string inputFileName) {
  std::vector<std::string> words = FileUtility::readWords(inputFileName);
  MergeSort::sort(words);
  std::ofstream ofStream(inputFileName);
  for (auto word : words) {
    ofStream << word << " ";
  }
  ofStream.close();
}

std::string ExternalSort::stripFileNameExtension(std::string inputFileName) {
  int dotIdx = inputFileName.find_last_of(".");
  int slashIdx = inputFileName.find_last_of("/");
  if (slashIdx == inputFileName.npos || dotIdx > slashIdx) {
    return inputFileName.substr(0, dotIdx);
  } else {
    return inputFileName;
  }
}
