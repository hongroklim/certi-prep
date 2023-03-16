#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char board[27][27];
int cnt;

int di[4] = {1, 0, -1,  0};
int dj[4] = {0, 1,  0, -1};

void scan_area(int i, int j) {
  if (board[i][j] != '1') return;

  board[i][j] = '0';
  cnt++;

  for (int k=0; k<4; k++)
    scan_area(i+di[k], j+dj[k]);
}

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/jgol_1695.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  int N, i, j;
  vector<int> cnts;
  char c, line[26];
  
  cin >> N;

  for (i=1; i<=N; i++) {
    for (j=1; j<=N; j++) {
      cin >> c;
      board[i][j] = c;
    }
  }

  for (i=1; i<=N; i++) {
    for (j=1; j<=N; j++) {
      if (board[i][j] != '1') continue;
      cnt = 0;
      scan_area(i, j);
      cnts.push_back(cnt);
    }
  }

  // print
  cout << cnts.size() << "\n";

  sort(cnts.begin(), cnts.end());
  for (int i=0; i<cnts.size(); i++)
    cout << cnts[i] << "\n";

#ifndef __LOCAL__
  return 0;
#endif
}
