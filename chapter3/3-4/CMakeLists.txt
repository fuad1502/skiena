add_executable(stack-implementation-testsuit stack-implementation-testsuit.cpp)

target_sources(stack-implementation-testsuit PRIVATE stack-implementation.cpp)

target_link_libraries(stack-implementation-testsuit PRIVATE gtest_main)
