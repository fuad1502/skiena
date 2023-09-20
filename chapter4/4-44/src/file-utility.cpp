#include "file-utility.hpp"
#include <fstream>
#include <iostream>

std::vector<std::string> FileUtility::readWords(std::string fileName) {
  std::ifstream ifStream(fileName);
  std::vector<std::string> words;

  if(ifStream.is_open()) {
    std::cout << "Opened" << std::endl;
    std::string word;
    while(ifStream >> word) {
      words.push_back(word);
    }
  }

  return words;
}
