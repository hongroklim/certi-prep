#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <cstring>
#include <queue>

#define MAX_N 1000

using namespace std;

typedef struct {
  int i;
  int j;
  int d;
} node_t;

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/jgol_2613.txt", "r", stdin); // 8
  EXPECT_NE(sfp, nullptr);
#endif
  
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> M >> N;

  int **box = new int*[N+2];

  box[0] = new int[M+2];
  box[N+1] = new int[M+2];

  memset(box[0], -1, sizeof(int)*(M+2));
  memset(box[N+1], -1, sizeof(int)*(M+2));

  queue<node_t> q;
  int unripes = 0;
  
  for (int n=1; n<=N; n++) {
    box[n] = new int[M+2];

    box[n][0] = box[n][M+1] = -1;

    for (int m=1; m<=M; m++) {
      cin >> box[n][m];
      if (box[n][m] == 1) {
        q.push({n, m, 0});
      } else if (box[n][m] == 0) {
        unripes++;
      }
    }
  }
  
  int di[4] = {1, 0, -1, 0};
  int dj[4] = {0, 1, 0, -1};
  
  // bfs
  int max_d = 0;
  while (!q.empty()) {
    node_t e = q.front();
    q.pop();
    
    if (max_d < e.d) max_d = e.d;

    for (int k=0; k<4; k++) {
      int ni = e.i+di[k], nj = e.j+dj[k];
      if (box[ni][nj] == 0) {
        q.push({ni, nj, e.d+1});
        box[ni][nj] = 1;
        unripes--;
      }
    }
  }
  
  if (unripes != 0) max_d = -1;

  cout << max_d << endl;

#ifndef __LOCAL__
  return 0;
#endif
}
