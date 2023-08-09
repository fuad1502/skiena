#include <gtest/gtest.h>
#include <limits>
#include "stack-implementation.hpp"

TEST(StackImplementation, Functionalities)
{
  Stack<int> st;
  int e;
  // Test initial condition
  EXPECT_EQ(st.size(), 0);
  EXPECT_EQ(st.findmin(), numeric_limits<int>::max());

  // Test push (and pushmin) and size
  st.push(3);
  EXPECT_EQ(st.size(), 1);
  EXPECT_EQ(st.findmin(), 3);
  st.push(2);
  EXPECT_EQ(st.size(), 2);
  EXPECT_EQ(st.findmin(), 2);
  st.push(3);
  EXPECT_EQ(st.size(), 3);
  EXPECT_EQ(st.findmin(), 2);
  st.push(1);
  EXPECT_EQ(st.size(), 4);
  EXPECT_EQ(st.findmin(), 1);
  st.push(0);
  EXPECT_EQ(st.size(), 5);
  EXPECT_EQ(st.findmin(), 0);

  // Test pop (and popmin), size, and findmin
  e = st.pop();
  EXPECT_EQ(st.size(), 4);
  EXPECT_EQ(e, 0);
  EXPECT_EQ(st.findmin(), 1);
  e = st.pop();
  EXPECT_EQ(st.size(), 3);
  EXPECT_EQ(e, 1);
  EXPECT_EQ(st.findmin(), 2);
  e = st.pop();
  EXPECT_EQ(st.size(), 2);
  EXPECT_EQ(e, 3);
  EXPECT_EQ(st.findmin(), 2);
  e = st.pop();
  EXPECT_EQ(st.size(), 1);
  EXPECT_EQ(e, 2);
  EXPECT_EQ(st.findmin(), 3);

  // Test findmin on emptied stack
  e = st.pop();
  EXPECT_EQ(st.size(), 0);
  EXPECT_EQ(e, 3);
  EXPECT_EQ(st.findmin(), numeric_limits<int>::max());

  // Test pop on empty stack
  EXPECT_EQ(st.pop(), numeric_limits<int>::max());
}

TEST(StackImplementation, GrowShrink)
{
  Stack<int> st;
  for(int i = 0; i < 1024; i++) {
    st.push(i);
  }
  EXPECT_EQ(st.size(), 1024);
  for(int i = 0; i < 1024; i++) {
    st.pop();
  }
  EXPECT_EQ(st.size(), 0);
  // should exit normally
  exit(0);
}
