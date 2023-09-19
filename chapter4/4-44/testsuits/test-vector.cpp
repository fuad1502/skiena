#include "test-vector.hpp"

std::vector<std::string> getTestVector() {
  std::vector<std::string> testVector;
  testVector.push_back("mangga");
  testVector.push_back("kursi");
  testVector.push_back("mouse");
  testVector.push_back("musik");
  testVector.push_back("laptop");
  testVector.push_back("piring");
  
  return testVector;
}

std::vector<std::string> getReferenceVector() {
  std::vector<std::string> referenceVector;
  referenceVector.push_back("kursi");
  referenceVector.push_back("laptop");
  referenceVector.push_back("mangga");
  referenceVector.push_back("mouse");
  referenceVector.push_back("musik");
  referenceVector.push_back("piring");
  
  return referenceVector;
}
