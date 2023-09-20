#include "heap-sort.hpp"
#include "test-vector.hpp"
#include "unique-words.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  std::vector<std::string> testVector = getTestVector();
  std::vector<std::string> referenceVector = getUniqueReferenceVector();

  std::vector<std::string> uniqueWords =
      UniqueWords::getUniqueWords(testVector, &HeapSort::sort);

  for (int i = 0; i < uniqueWords.size(); i++) {
    if (uniqueWords[i] != referenceVector[i]) {
      return -1;
    }
  }

  return 0;
}
