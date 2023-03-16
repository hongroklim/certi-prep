#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <stack>

using namespace std;

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/swea_1218.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  int tc, TC = 10;
  int len, i;
  char c;           // '()', '[]', '{}', '<>'
  stack<char> s;
  
  for(tc=1; tc<=TC; tc++){
    cin >> len;
    
    for (i=0; i<len; i++) {
      cin >> c;
      
      if (c == '('
          || c == '['
          || c == '{'
          || c == '<') {
        s.emplace(c);
      } else if ((c == ')' && s.top() == '(')
          || (c == ']' && s.top() == '[')
          || (c == '}' && s.top() == '{')
          || (c == '>' && s.top() == '<')) {
        s.pop();
      } else {
        break;
      }
    }
    
    // skip remaining chars
    while(++i<len) cin >> c;

    cout << "#" << tc << " " << s.empty() << endl;

    // clear stack
    while(!s.empty()) s.pop();
  }

#ifndef __LOCAL__
  return 0;
#endif
}

