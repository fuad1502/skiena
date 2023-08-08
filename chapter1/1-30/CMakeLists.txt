set(CMAKE_BUILD_TYPE Release)

add_executable(tsp-heuristics-testsuits tsp-heuristics-testsuits.cpp)
add_executable(tsp-heuristics-bench tsp-heuristics-bench.cpp)

target_sources(tsp-heuristics-testsuits PRIVATE tsp-heuristics.cpp)
target_sources(tsp-heuristics-bench PRIVATE tsp-heuristics.cpp)

target_link_libraries(tsp-heuristics-testsuits gtest_main)