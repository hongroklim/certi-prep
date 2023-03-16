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

  sfp = freopen("input/swea_1225.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  int tc, TC = 10;
  int i, j, c;
  int num[8];
  bool is_running;
  
  while (true) {
    cin >> tc;
    if(cin.eof()) break;

    for (i=0; i<8; i++) {
      cin >> num[i];
    }

    i = 0;
    is_running = true;

    while (is_running) {
      for (c=1; c<=5&&is_running; c++) {
        num[i] -= c;
        
        if (num[i] <= 0) {
          num[i] = 0;
          is_running = false;
        }

        // shift head index 
        if (i < 7) i++;
        else i = 0;
      }
    }

    // print
    cout << "#" << tc;
    for (j=i; j<8; j++) {
      cout << " " << num[j];
    }
    for (j=0; j<i; j++) {
      cout << " " << num[j];
    }
    cout << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}

