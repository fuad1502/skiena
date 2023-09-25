#include "test-vector.hpp"

std::vector<std::string> getTestVector() {
  std::vector<std::string> testVector;
  testVector.push_back("9");
  testVector.push_back("8");
  testVector.push_back("7");
  testVector.push_back("6");
  testVector.push_back("5");
  testVector.push_back("4");
  testVector.push_back("3");
  testVector.push_back("2");
  testVector.push_back("1");
  testVector.push_back("0");

  return testVector;
}

std::vector<std::string> getReferenceVector() {
  std::vector<std::string> referenceVector;
  referenceVector.push_back("0");
  referenceVector.push_back("1");
  referenceVector.push_back("2");
  referenceVector.push_back("3");
  referenceVector.push_back("4");
  referenceVector.push_back("5");
  referenceVector.push_back("6");
  referenceVector.push_back("7");
  referenceVector.push_back("8");
  referenceVector.push_back("9");

  return referenceVector;
}
