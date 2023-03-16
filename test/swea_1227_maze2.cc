#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>

using namespace std;

char board[100][100];
int delta[4][3] = { {-1, 0, 2}, {0, 1, 3}, {1, 0, 0}, {0, -1, 1} };

bool solve(int i, int j, int d) {
  if (board[i][j] == '3') return true;
  else if (board[i][j] == '1') return false;
  
  bool ans = false;

  for (int k=0; k<4; k++)
    if (k != delta[d][2]) // skip previous path
      ans = ans || solve(i+delta[k][0], j+delta[k][1], k);

  return ans;
}

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/swea_1227.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  int tc;
  int i;
  int ans;
  
  while (true) {
    cin >> tc;
    if (cin.eof()) break;

    for (i=0; i<100; i++)
      cin >> board[i];
    
    cout << "#" << tc << " " << solve(1, 1, 2) << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}
