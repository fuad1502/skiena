add_executable(external-sort-testsuit external-sort-testsuit.cpp)
target_sources(external-sort-testsuit PRIVATE ${CMAKE_SOURCE_DIR}/src/external-sort.cpp)
target_include_directories(external-sort-testsuit PRIVATE ${CMAKE_SOURCE_DIR}/include)
add_test(NAME external-sort-testsuit COMMAND external-sort-testsuit)
