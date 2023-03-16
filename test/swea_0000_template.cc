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

  sfp = freopen("input/swea_0000.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  int tc, TC = 10;
  int i;
  int ans;
  
  for(tc=1; tc<=TC; tc++){
    cout << "#" << tc << " " << ans << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}

