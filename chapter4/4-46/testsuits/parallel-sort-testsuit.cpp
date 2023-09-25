#include "file-utility.hpp"
#include "merge-sort.hpp"
#include "parallel-sort.hpp"
#include "test-vector.hpp"

int main(int argc, char *argv[]) {

  auto testVector = getTestVector();
  auto referenceVector = getReferenceVector();

  ParallelSort::sort(testVector, 4);

  for (int i = 0; i < testVector.size(); i++) {
    if (testVector[i] != referenceVector[i])
      return -1;
  }

  auto words = FileUtility::readWords("sample-file/alice29.txt");
  auto referenceWords = words;

  MergeSort::sort(referenceWords);
  ParallelSort::sort(words, 4);

  for (int i = 0; i < words.size(); i++) {
    if (words[i] != referenceWords[i])
      return -1;
  }

  return 0;
}
