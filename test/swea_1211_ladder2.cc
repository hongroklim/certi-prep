#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>

using namespace std;

char board[100][102];

int get_path(int i, int j, int d, int acc) {
  if (d != 0) {
    // when moving horizontally
    if (board[i][j+d] == '1') return get_path(i, j+d, d, ++acc);
    else return get_path(i+1, j, 0, ++acc);
  } else {
    if (board[i][j+1] == '1') return get_path(i, j+1, 1, ++acc);
    else if (board[i][j-1] == '1') return get_path(i, j-1, -1, ++acc);
    else if (board[i+1][j] == '1') return get_path(i+1, j, 0, ++acc);
    else return ++acc;
  }
}

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/swea_1211.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  int tc;
  int cnt;
  int least_cnt;
  int least_idx;

  while (true) {
    cin >> tc;
    if (cin.eof()) break;

    for (int i=0; i<100; i++)
      for (int j=1; j<=100; j++)
        cin >> board[i][j];
    
    least_cnt = 999999;

    for (int i=1; i<=100; i++) {
      if (board[0][i] == '0') continue;

      cnt = get_path(0, i, 0, 0);

      if (cnt <= least_cnt) {
        least_cnt = cnt;
        least_idx = i;
      }
    }

    cout << "#" << tc << " " << least_idx-1 << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}
