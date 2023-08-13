cmake_minimum_required(VERSION 3.14)
project(skiena)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()
add_subdirectory(lib/googletest)
add_subdirectory(lib/cli-adt)
# Chapter 1 / Problem 30
add_subdirectory(chapter1/1-30)
add_test(NAME tsp-heuristics-testsuits COMMAND tsp-heuristics-testsuits)
# Chapter 1 / Problem 32
add_subdirectory(chapter1/1-32)
add_test(NAME integer-division-testsuit COMMAND integer-division-testsuit)
# Chapter 3 / Problem 1
add_subdirectory(chapter3/3-1)
add_test(NAME correct-parantheses-testsuit COMMAND correct-parantheses-testsuit)
# Chapter 3 / Problem 2
add_subdirectory(chapter3/3-3)
add_test(NAME reverse-linked-list-testsuit COMMAND reverse-linked-list-testsuit)
# Chapter 3 / Problem 4
add_subdirectory(chapter3/3-4)
add_test(NAME stack-implementation-testsuit COMMAND stack-implementation-testsuit)
# Chapter 3 / Problem 7
add_subdirectory(chapter3/3-7)
add_test(NAME dictionary-implementation-testsuit COMMAND dictionary-implementation-testsuit)
