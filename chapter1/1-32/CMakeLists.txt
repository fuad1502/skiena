add_executable(integer-division-testsuit integer-division-testsuit.cpp)

target_sources(integer-division-testsuit PRIVATE integer-division.cpp)

target_link_libraries(integer-division-testsuit gtest_main)