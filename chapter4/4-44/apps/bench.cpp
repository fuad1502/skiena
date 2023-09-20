#include "file-utility.hpp"
#include "heap-sort.hpp"
#include "merge-sort.hpp"
#include "quick-sort.hpp"
#include "selection-sort.hpp"
#include "unique-words.hpp"
#include "benchmark/benchmark.h"

static void BM_HeapSort1(benchmark::State& state) {
  std::vector<std::string> words = FileUtility::readWords("sample-file/alice29.txt");
  for(auto _ : state)
    UniqueWords::getUniqueWords(words, HeapSort::sort);
}
BENCHMARK(BM_HeapSort1);
static void BM_HeapSort2(benchmark::State& state) {
  std::vector<std::string> words = FileUtility::readWords("sample-file/asyoulik.txt");
  for(auto _ : state)
    UniqueWords::getUniqueWords(words, HeapSort::sort);
}
BENCHMARK(BM_HeapSort2);
static void BM_HeapSort3(benchmark::State& state) {
  std::vector<std::string> words = FileUtility::readWords("sample-file/lcet10.txt");
  for(auto _ : state)
    UniqueWords::getUniqueWords(words, HeapSort::sort);
}
BENCHMARK(BM_HeapSort3);
static void BM_HeapSort4(benchmark::State& state) {
  std::vector<std::string> words = FileUtility::readWords("sample-file/plrabn12.txt");
  for(auto _ : state)
    UniqueWords::getUniqueWords(words, HeapSort::sort);
}
BENCHMARK(BM_HeapSort4);

static void BM_MergeSort1(benchmark::State& state) {
  std::vector<std::string> words = FileUtility::readWords("sample-file/alice29.txt");
  for(auto _ : state)
    UniqueWords::getUniqueWords(words, MergeSort::sort);
}
BENCHMARK(BM_MergeSort1);
static void BM_MergeSort2(benchmark::State& state) {
  std::vector<std::string> words = FileUtility::readWords("sample-file/asyoulik.txt");
  for(auto _ : state)
    UniqueWords::getUniqueWords(words, MergeSort::sort);
}
BENCHMARK(BM_MergeSort2);
static void BM_MergeSort3(benchmark::State& state) {
  std::vector<std::string> words = FileUtility::readWords("sample-file/lcet10.txt");
  for(auto _ : state)
    UniqueWords::getUniqueWords(words, MergeSort::sort);
}
BENCHMARK(BM_MergeSort3);
static void BM_MergeSort4(benchmark::State& state) {
  std::vector<std::string> words = FileUtility::readWords("sample-file/plrabn12.txt");
  for(auto _ : state)
    UniqueWords::getUniqueWords(words, MergeSort::sort);
}
BENCHMARK(BM_MergeSort4);

static void BM_QuickSort1(benchmark::State& state) {
  std::vector<std::string> words = FileUtility::readWords("sample-file/alice29.txt");
  for(auto _ : state)
    UniqueWords::getUniqueWords(words, QuickSort::sort);
}
BENCHMARK(BM_QuickSort1);
static void BM_QuickSort2(benchmark::State& state) {
  std::vector<std::string> words = FileUtility::readWords("sample-file/asyoulik.txt");
  for(auto _ : state)
    UniqueWords::getUniqueWords(words, QuickSort::sort);
}
BENCHMARK(BM_QuickSort2);
static void BM_QuickSort3(benchmark::State& state) {
  std::vector<std::string> words = FileUtility::readWords("sample-file/lcet10.txt");
  for(auto _ : state)
    UniqueWords::getUniqueWords(words, QuickSort::sort);
}
BENCHMARK(BM_QuickSort3);
static void BM_QuickSort4(benchmark::State& state) {
  std::vector<std::string> words = FileUtility::readWords("sample-file/plrabn12.txt");
  for(auto _ : state)
    UniqueWords::getUniqueWords(words, QuickSort::sort);
}
BENCHMARK(BM_QuickSort4);

static void BM_SelectionSort1(benchmark::State& state) {
  std::vector<std::string> words = FileUtility::readWords("sample-file/alice29.txt");
  for(auto _ : state)
    UniqueWords::getUniqueWords(words, SelectionSort::sort);
}
BENCHMARK(BM_SelectionSort1);
static void BM_SelectionSort2(benchmark::State& state) {
  std::vector<std::string> words = FileUtility::readWords("sample-file/asyoulik.txt");
  for(auto _ : state)
    UniqueWords::getUniqueWords(words, SelectionSort::sort);
}
BENCHMARK(BM_SelectionSort2);
static void BM_SelectionSort3(benchmark::State& state) {
  std::vector<std::string> words = FileUtility::readWords("sample-file/lcet10.txt");
  for(auto _ : state)
    UniqueWords::getUniqueWords(words, SelectionSort::sort);
}
BENCHMARK(BM_SelectionSort3);
static void BM_SelectionSort4(benchmark::State& state) {
  std::vector<std::string> words = FileUtility::readWords("sample-file/plrabn12.txt");
  for(auto _ : state)
    UniqueWords::getUniqueWords(words, SelectionSort::sort);
}
BENCHMARK(BM_SelectionSort4);

BENCHMARK_MAIN();
