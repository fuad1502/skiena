#include "external-sort.hpp"

int main (int argc, char *argv[]) {
  ExternalSort::sortText("sample-file/alice29.txt", "alice29_sorted.txt", 1024); 
  return 0;
}
