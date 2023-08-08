add_executable(correct-parantheses-testsuit correct-parantheses-testsuit.cpp)

target_sources(correct-parantheses-testsuit PRIVATE correct-parantheses.cpp)

target_link_libraries(correct-parantheses-testsuit PRIVATE gtest_main)

