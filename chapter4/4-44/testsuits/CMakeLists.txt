add_executable(selection-sort-testsuit selection-sort-testsuit.cpp)
target_sources(selection-sort-testsuit PRIVATE ${CMAKE_SOURCE_DIR}/src/selection-sort.cpp)
target_sources(selection-sort-testsuit PRIVATE test-vector.cpp)
add_test(NAME selection-sort-testsuit COMMAND selection-sort-testsuit)

add_executable(heap-sort-testsuit heap-sort-testsuit.cpp)
target_sources(heap-sort-testsuit PRIVATE ${CMAKE_SOURCE_DIR}/src/heap-sort.cpp)
target_sources(heap-sort-testsuit PRIVATE test-vector.cpp)
add_test(NAME heap-sort-testsuit COMMAND heap-sort-testsuit)

add_executable(merge-sort-testsuit merge-sort-testsuit.cpp)
target_sources(merge-sort-testsuit PRIVATE ${CMAKE_SOURCE_DIR}/src/merge-sort.cpp)
target_sources(merge-sort-testsuit PRIVATE test-vector.cpp)
add_test(NAME merge-sort-testsuit COMMAND merge-sort-testsuit)

add_executable(quick-sort-testsuit quick-sort-testsuit.cpp)
target_sources(quick-sort-testsuit PRIVATE ${CMAKE_SOURCE_DIR}/src/quick-sort.cpp)
target_sources(quick-sort-testsuit PRIVATE test-vector.cpp)
add_test(NAME quick-sort-testsuit COMMAND quick-sort-testsuit)

add_executable(unique-words-testsuit unique-words-testsuit.cpp)
target_sources(unique-words-testsuit PRIVATE ${CMAKE_SOURCE_DIR}/src/unique-words.cpp)
target_sources(unique-words-testsuit PRIVATE ${CMAKE_SOURCE_DIR}/src/heap-sort.cpp)
target_sources(unique-words-testsuit PRIVATE test-vector.cpp)
add_test(NAME unique-words-testsuit COMMAND unique-words-testsuit)

add_executable(file-utility-testsuit file-utility-testsuit.cpp)
target_sources(file-utility-testsuit PRIVATE ${CMAKE_SOURCE_DIR}/src/file-utility.cpp)
add_test(NAME file-utility-testsuit COMMAND file-utility-testsuit)
configure_file(${CMAKE_SOURCE_DIR}/sample-file/alice29.txt ${CMAKE_BINARY_DIR}/testsuits/sample-file/alice29.txt COPYONLY)

include_directories(${CMAKE_SOURCE_DIR}/include)
