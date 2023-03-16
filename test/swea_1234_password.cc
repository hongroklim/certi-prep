#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <vector>

using namespace std;

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/swea_1234.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  int tc, TC = 10;
  int N, i;
  char c;
  vector<char> v;
  
  for(tc=1; tc<=TC; tc++){
    cin >> N;
    
    // 1st character
    cin >> c;
    v.push_back(c);
    
    // remaining
    for (i=1; i<N; i++) {
      cin >> c;
      if (c == v.back()) v.pop_back();
      else v.push_back(c);
    }
    
    // print
    cout << "#" << tc << " ";
    for (i=0; i<v.size(); i++) {
      cout << v[i];
    }
    cout << endl;

    v.clear();
  }

#ifndef __LOCAL__
  return 0;
#endif
}

