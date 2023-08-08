cmake_minimum_required(VERSION 3.14)
project(skiena)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()
add_subdirectory(lib/googletest)
# Chapter 1 / Problem 30
add_subdirectory(chapter1/1-30)
add_test(NAME tsp-heuristics-testsuits COMMAND tsp-heuristics-testsuits)
# Chapter 1 / Problem 32
add_subdirectory(chapter1/1-32)
add_test(NAME integer-division-testsuit COMMAND integer-division-testsuit)
