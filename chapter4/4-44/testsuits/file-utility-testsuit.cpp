#include "file-utility.hpp"
#include <iostream>

int main (int argc, char *argv[]) {
  std::vector<std::string> words = FileUtility::readWords("sample-file/alice29.txt");
 
  std::vector<std::string> title = {"ALICE'S", "ADVENTURES", "IN", "WONDERLAND"};

  for(int i = 0; i < title.size(); i++) {
    if(words[i] != title[i]) {
      return -1;
    }
  }

  return 0;
}
