#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>

using namespace std;

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/swea_10804.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  int tc, TC;
  int i;
  char input[1000+1];
  char output[1000+1];
  
  char mirror[256];
  mirror['b'] = 'd';
  mirror['d'] = 'b';
  mirror['p'] = 'q';
  mirror['q'] = 'p';

  cin >> TC;

  for (tc=1; tc<=TC; tc++) {
    cin >> input;
    
    for (i=0; input[i]!='\0'; i++)
      output[999-i] = mirror[input[i]];

    cout << "#" << tc << " " << &output[1000-i] << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}
