#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <queue>

using namespace std;

typedef struct {
  int i;
  int j;
  int t;
} cell;

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/jgol_1078.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  int di[4] = {1, 0, -1,  0};
  int dj[4] = {0, 1,  0, -1};

  char board[102][102];

  int seconds = 0;
  int livings = 0;

  int n, m, x, y;
  queue<cell> cells;

  cin >> m >> n;
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=m; j++) {
      cin >> board[i][j];
      if (board[i][j] == '1') livings++;
    }
  }
  
  cin >> y >> x;
  cells.push(cell{x, y, 3});
  
  while (!cells.empty()) {
    cell c = cells.front();
    cells.pop();
    
    if (board[c.i][c.j] == '0') continue;

    board[c.i][c.j] = '0';
    livings--;

    for (int k=0; k<4; k++)
      if (board[c.i+di[k]][c.j+dj[k]] == '1')
        cells.push(cell{c.i+di[k], c.j+dj[k], c.t+1});
    
    if (c.t > seconds) seconds = c.t;
  }

  cout << seconds << "\n" << livings << endl;

#ifndef __LOCAL__
  return 0;
#endif
}

