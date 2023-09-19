#include "quick-sort.hpp"
#include "test-vector.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  std::vector<std::string> testVector = getTestVector();
  std::vector<std::string> referenceVector = getReferenceVector();

  QuickSort::sort(testVector);

  for(int i = 0; i < testVector.size(); i++) {
    if(testVector[i] != referenceVector[i]) {
      return -1;
    }
  }

  return 0;
}
