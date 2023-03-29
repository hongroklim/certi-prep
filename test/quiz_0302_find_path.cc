#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <queue>

#define MAX_N 1000
#define MAX_M 1000

using namespace std;

typedef struct {
  int i, j;
} pos_t;

int maze[MAX_N+2][MAX_N+2];
pos_t d[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// bfs
void flood_fill(pos_t begin, int flag) {
  queue<pos_t> q;
  q.emplace(begin);

  while (!q.empty()) {
    pos_t p = q.front(); q.pop();
    maze[p.i][p.j] = flag;

    for (int k=0; k<4; k++) {
      pos_t n = {p.i+d[k].i, p.j+d[k].j};
      if (maze[n.i][n.j] == 1)
        q.emplace(n);
    }
  }
}

#ifndef __LOCAL__
int main() {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/quiz_0302.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  ios_base::sync_with_stdio(false);

  int TC;
  cin >> TC;

  for (int tc=1; tc<=TC; tc++) {
    int N, M;
    cin >> N >> M;
    
    for (int i=1; i<=N; i++) {
      maze[i][0] = maze[i][N+1] = maze[N+1][i] = 0;

      for (int j=1; j<=N; j++) {
        bool cell;
        cin >> cell;
        maze[i][j] = !cell;
      }
    }
    
    int flag = 2;
    for (int i=1; i<=N; i++)
      for (int j=1; j<=N; j++)
        if (maze[i][j] == 1)
          flood_fill({i, j}, flag++);


    cout << '#' << tc;
    for (int m=1; m<=M; m++) {
      int A, B, C, D;
      cin >> A >> B >> C >> D;
      cout << " " << (maze[A][B] == maze[C][D]);
    }
    cout << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}
