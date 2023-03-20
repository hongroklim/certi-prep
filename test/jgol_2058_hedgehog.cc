#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <queue>

#define MAX_N 25

using namespace std;

typedef struct {
  int ai;
  int aj;
  int bi;
  int bj;
  int d;
} pos_t;

int board[MAX_N+2][MAX_N+2];
bool visited[MAX_N+2][MAX_N+2][MAX_N+2][MAX_N+2];

int DAI, DAJ, DBI, DBJ;

int di[9] = {-1, -1, -1,  0,  0,  0,  1,  1,  1};
int dj[9] = {-1,  0,  1, -1,  0,  1, -1,  0,  1};

pos_t next_pos(pos_t p, int ka, int kb) {
  int ai = p.ai+di[ka], aj = p.aj+dj[ka];
  int bi = p.bi+di[kb], bj = p.bj+dj[kb];

  if (board[ai][aj] == 0
      && board[bi][bj] == 0
      && (ai-bi < -1 || 1 < ai-bi
          || aj-bj < -1 || 1 < aj-bj)) {
    return {ai, aj, bi, bj, p.d+1};
  } else {
    return p; // not movable
  }
}

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  // sfp = freopen("input/jgol_2058.txt", "r", stdin);  // 8
  // sfp = freopen("input/jgol_2058_1.txt", "r", stdin);   // 13
  sfp = freopen("input/jgol_2058_2.txt", "r", stdin);   // 14
  EXPECT_NE(sfp, nullptr);
#endif
  
  int N, ai, aj, bi, bj;

  cin >> N;
  cin >> ai >> aj >> DAI >> DAJ;
  cin >> bi >> bj >> DBI >> DBJ;

  for (int m=0; m<N+2; m++)
    board[0][m] = board[N+1][m] = 1;

  for (int n=1; n<=N; n++) {
    board[n][0] = board[n][N+1] = 1;
    for (int m=1; m<=N; m++) {
      cin >> board[n][m];
    }
  }

  for (int a=0; a<N+2; a++)
    for (int b=0; b<N+2; b++)
      for (int c=0; c<N+2; c++)
        for (int d=0; d<N+2; d++)
          visited[a][b][c][d] = false;
  
  // bfs
  queue<pos_t> q;
  q.push({ai, aj, bi, bj, 0});

  while (!q.empty()) {
    pos_t p = q.front();
    q.pop();
    
    if (p.ai == DAI && p.aj == DAJ
        && p.bi == DBI && p.bj == DBJ) {
      cout << p.d << endl;  // both reached
      break;
    } else if(visited[p.ai][p.aj][p.bi][p.bj]) {
      continue;             // already visited
    } else {
      visited[p.ai][p.aj][p.bi][p.bj] = true;
    }

    cout << "(" << p.ai << " " << p.aj << ", " << p.bi << " " << p.bj << ") " << endl;

    for (int ka=0; ka<9; ka++) {
      for (int kb=0; kb<9; kb++) {
        pos_t p_next = next_pos(p, ka, kb);
        if (p.d < p_next.d) q.push(p_next);
      }
    }

  }

#ifndef __LOCAL__
  return 0;
#endif
}
