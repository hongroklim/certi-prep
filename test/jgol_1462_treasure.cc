#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef struct {
  int i;
  int j;
  int d;
} pos_t;

char board[52][52];

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  // sfp = freopen("input/jgol_1462.txt", "r", stdin);  // 8
  sfp = freopen("input/jgol_1462_1.txt", "r", stdin); // 1
  EXPECT_NE(sfp, nullptr);
#endif
  
  int N, M;
  int i, j, k;

  int di[4] = {1, 0, -1, 0};
  int dj[4] = {0, 1, 0, -1};

  cin >> N >> M;

  memset(board[0], 'W', N+2);
  memset(board[N+1], 'W', N+2);

  for (i=1; i<=N; i++) {
    board[i][0] = 'W';
    board[i][N+1] = 'W';

    for (j=1; j<=M; j++) {
      cin >> board[i][j];
    }
  }

  queue<pos_t> q;
  bool visited[52][52];
  int max_dist = -1;
  
  for (i=1; i<=N; i++) {
    for (j=1; j<=M; j++) {
      if (board[i][j] == 'W') continue;
      
      // bfs
      q.push({i, j, 0});
      memset(visited, false, sizeof(visited));
      visited[i][j] = true;

      while (!q.empty()) {
        pos_t p = q.front();
        q.pop();
      
        for (k=0; k<4; k++) {
          int ti = p.i + di[k];
          int tj = p.j + dj[k];

          if (board[ti][tj] == 'L' && !visited[ti][tj]) {
            q.push({ti, tj, p.d+1});
            visited[ti][tj] = true;
          }
        }

        if (max_dist < p.d) max_dist = p.d;
      }
    }
  }

  cout << max_dist << endl;

#ifndef __LOCAL__
  return 0;
#endif
}

