#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <map>

using namespace std;

typedef struct {
  int n;
  int d;
} ant_t;

#ifndef __LOCAL__
int main() {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;
  sfp = freopen("input/quiz_0101.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int M, N, K;
  int x, y, d, k;
  int tgt_x, tgt_y, tgt_d, dist;

  map<pair<int, int>, ant_t> board;
  int delta[5][2] = {{0,0}, {0,1}, {0,-1}, {-1,0}, {1,0}};

  while (true) {
    int tc;
    cin >> tc;
    if (cin.eof()) break;

    cin >> M >> N >> K;

    for (int i=0; i<N; i++) {
      cin >> x >> y >> d;
      board[make_pair(x, y)] = {i+1, d};
    }

    // find k-th ant
    tgt_x = tgt_y = k = 0;

    for (x=M; x>=1; x--) {
      for (y=1; y<=M; y++) {
        if (board[make_pair(x, y)].d == 4 && ++k == K) {
          tgt_x = x;
          tgt_y = y;

          x = 0;
          break;
        }
      }
    }
    
    if (tgt_x == 0 || tgt_y == 0) {
      // not found
      cout << "#" << tc << " 0 0" << endl;
      continue;
    } else {
      // otherwise print time first
      cout << "#" << tc << " " << (M - tgt_x) << " ";
    }
    
    // find n recursively
    x = M - 1;
    y = tgt_y;
    tgt_d = board[make_pair(tgt_x, tgt_y)].d;

    while (x != tgt_x || y != tgt_y) {
      dist = (tgt_x - x) + (tgt_y - y);

      for (int td=1; td<=4; td++) {
        if (td == tgt_d) continue;

        int tx = x + delta[td][0]*dist;
        int ty = y + delta[td][1]*dist;
        
        if (board[make_pair(tx, ty)].n > 0) {
          // collison found -> change tgt_xy
          tgt_x = tx;
          tgt_y = ty;
          tgt_d = board[make_pair(tgt_x, tgt_y)].d;
          break;
        }
      }
      
      x -= delta[tgt_d][0];
      y -= delta[tgt_d][1];
    }

    cout << board[make_pair(tgt_x, tgt_y)].n << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}
