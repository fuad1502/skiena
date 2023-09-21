#include "file-utility.hpp"
#include <fstream>

std::vector<std::string> FileUtility::readWords(std::string fileName) {
  std::ifstream ifStream(fileName);
  std::vector<std::string> words;

  if(ifStream.is_open()) {
    std::string word;
    while(ifStream >> word) {
      words.push_back(word);
    }
  }
  ifStream.close();

  return words;
}
