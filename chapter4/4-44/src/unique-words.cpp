#include "unique-words.hpp"
#include <algorithm>

std::vector<std::string> UniqueWords::getUniqueWords(
    std::vector<std::string> &words,
    std::function<void(std::vector<std::string> &)> sort) {
  sort(words);
  std::vector<std::string> uniqueWords;
  std::string uniqueWord;
  for (int i = 1; i < words.size(); i++) {
    if (words[i] != uniqueWord) {
      uniqueWords.push_back(words[i]);
      uniqueWord = words[i];
    }
  }
  return uniqueWords;
}
