#pragma once
#include <limits>
#include <cstdlib>

using namespace std;

template<typename T>
class Stack {
public:
  Stack() :data(nullptr), n(0), cap(0), min(std::numeric_limits<int>::max()), mins(nullptr), nmin(0), capmin(0) {};
  void push(const T& e);
  T pop();
  T findmin();
  int size();
  ~Stack();
private:
  // data stack
  T *data;
  int n;
  int cap;
  int min;
  // minimums stack
  T *mins;
  int nmin;
  int capmin;
  void pushmin(const T& e);
  T popmin();
};

template<typename T>
void Stack<T>::push(const T& e)
{
  // handle memory growing
  if(cap == 0) {
    cap = 1;
    data = (T*) malloc(sizeof(T));
  } else if(cap < n + 1) {
    cap *= 2;
    data = (T*) realloc(data, sizeof(T) * cap);
  }
  // handle pushing
  n += 1;
  data[n - 1] = e;
  // handle minimum value update
  if(e < min) {
    pushmin(e);
    min = e;
  }
}

template<typename T>
T Stack<T>::pop()
{
  // handle empty stack
  if(n == 0)
  {
    return numeric_limits<int>::max();
  }
  // handle memory shrinking
  if(n - 1 == cap / 4) {
    cap /= 2;
    data = (T*) realloc(data, sizeof(T) * cap);
  }
  // handle popping
  int e = data[n - 1];
  n -= 1;
  // handle minimum value update
  if(e == min) {
    min = popmin();
  }
  return e;
}

template<typename T>
T Stack<T>::findmin()
{
  return min;
}

template<typename T>
int Stack<T>::size()
{
  return n;
}

template<typename T>
Stack<T>::~Stack()
{
  delete data;
  delete mins;
}

template<typename T>
void Stack<T>::pushmin(const T& e)
{
  // handle memory growing
  if(capmin == 0) {
    capmin = 1;
    mins = (T*) malloc(sizeof(T));
  } else if(capmin < nmin + 1) {
    capmin *= 2;
    mins = (T*) realloc(mins, sizeof(T) * capmin);
  }
  // pushing
  nmin += 1;
  mins[nmin - 1] = e;
}

template<typename T>
T Stack<T>::popmin()
{
  // handle memory shrinking
  if(nmin - 1 == capmin) {
    capmin /= 2;
    mins = (T*) realloc(mins, sizeof(T) * capmin);
  }
  // handle emptied stack
  nmin -= 1;
  if(nmin == 0) {
    return numeric_limits<int>::max();
  }
  // popping
  return mins[nmin - 1];
}
