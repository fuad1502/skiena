#include "benchmark/benchmark.h"
#include "parallel-sort.hpp"
#include "merge-sort.hpp"
#include "file-utility.hpp"

static void BM_ParallelSort8(benchmark::State &state) {
  auto words = FileUtility::readWords("sample-file/alice29.txt");
  for(auto _ : state) {
    ParallelSort::sort(words, 8);
  }
}
BENCHMARK(BM_ParallelSort8);

static void BM_ParallelSort4(benchmark::State &state) {
  auto words = FileUtility::readWords("sample-file/alice29.txt");
  for(auto _ : state) {
    ParallelSort::sort(words, 4);
  }
}
BENCHMARK(BM_ParallelSort4);

static void BM_ParallelSort2(benchmark::State &state) {
  auto words = FileUtility::readWords("sample-file/alice29.txt");
  for(auto _ : state) {
    ParallelSort::sort(words, 2);
  }
}
BENCHMARK(BM_ParallelSort2);

static void BM_ParallelSort1(benchmark::State &state) {
  auto words = FileUtility::readWords("sample-file/alice29.txt");
  for(auto _ : state) {
    ParallelSort::sort(words, 1);
  }
}
BENCHMARK(BM_ParallelSort1);

static void BM_MergeSort(benchmark::State &state) {
  auto words = FileUtility::readWords("sample-file/alice29.txt");
  for(auto _ : state) {
    MergeSort::sort(words);
  }
}
BENCHMARK(BM_MergeSort);

BENCHMARK_MAIN();
