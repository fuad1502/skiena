add_executable(reverse-linked-list-testsuit reverse-linked-list-testsuit.cpp)

target_sources(reverse-linked-list-testsuit PRIVATE reverse-linked-list.cpp)

target_link_libraries(reverse-linked-list-testsuit PRIVATE gtest_main)
