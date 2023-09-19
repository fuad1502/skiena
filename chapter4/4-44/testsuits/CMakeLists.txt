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

include_directories(${CMAKE_SOURCE_DIR}/include)
