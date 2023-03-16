#include "gtest/gtest.h"
/* ************************************* */
/*                                       */
#include <iostream>
#include <cstring>

using namespace std;

int to_int(char text[3]) {
  if (text[0] == 'Z') return 0;
  if (text[0] == 'O') return 1;
  if (text[0] == 'T') {
    if (text[1] == 'W') return 2;
    if (text[1] == 'H') return 3;
  }
  if (text[0] == 'F') {
    if (text[1] == 'O') return 4;
    if (text[1] == 'I') return 5;
  }
  if (text[0] == 'S') {
    if (text[1] == 'I') return 6;
    if (text[1] == 'V') return 7;
  }
  if (text[0] == 'E') return 8;
  if (text[0] == 'N') return 9;

  return -1;
}

// int main(int argc, char** argv) {
/*                                       */
/* ************************************* */

TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/swea_1221.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);

  /* ************************************* */
  /*                                       */
  ios::sync_with_stdio(false);

  int tc, TC;
  int len;
  int i, j;

  char tc_nm[4];
  char text[3];
  int counts[10];

  char nums[10][4] = {"ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"};
  
  cin >> TC;

  for (tc = 1; tc <= TC; tc++) {
    // init
    memset(counts, 0, 10*sizeof(int));    

    cin >> tc_nm >> len;
    cout << tc_nm << endl;

    for (i=0; i<len; i++) {
      cin >> text;
      counts[to_int(text)]++;
    }
    
    // print
    for (i=0; i<10; i++) {
      for (j=0; j<counts[i]; j++) {
        cout << nums[i] << " ";
      }
    }

    cout << endl;
  }
  
  // return 0;
// }
  /*                                       */
  /* ************************************* */
}
