#include "correct-parantheses.hpp"
#include <stack>

using namespace std;

bool correctParantheses(const string& parantheses, int& loc)
{
  stack<char> st;
  loc = 0;
  for(char c: parantheses) {
    if(c == '{' || c == '(' || c == '[') {
      st.push(c);
    } else if(c == '}' || c == ')' || c == ']') {
      char matchingPar;
      switch(c) {
      case '}':
        matchingPar = '{';
        break;
      case ')':
        matchingPar = '(';
        break;
      case ']':
        matchingPar = '[';
        break;
      }
      if(st.top() != matchingPar) {
        return false;
      } else {
        st.pop();
      }
    }
    loc++;
  }
  if(st.size() != 0) {
    return false;
  }
  loc = -1;
  return true;
}
