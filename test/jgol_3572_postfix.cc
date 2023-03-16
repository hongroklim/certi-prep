#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <stack>

using namespace std;

bool is_gteq(char c1, char c2) {
  return (c1=='*'||c1=='/')
    || ((c1=='+'||c1=='-') && (c2=='+'||c2=='-'));
}

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/jgol_3572.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  char c;
  stack<char> s;

  while (true) {
    cin >> c;
    if(cin.eof()) break;

    if ('a' <= c && c <= 'z') {
      cout << c;
    } else {
      while (!s.empty() && is_gteq(s.top(), c)) {
        cout << s.top();
        s.pop();
      }
      s.push(c);
    }
  }

  while (!s.empty()) {
    cout << s.top();
    s.pop();
  }

  cout << endl;

#ifndef __LOCAL__
  return 0;
#endif
}

