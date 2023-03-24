#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>

#define MAX_N 20

using namespace std;

typedef struct {
  int x;
  int y;
} pos_t;

int ccw(pos_t a, pos_t b, pos_t c) {
  return a.x*b.y + b.x*c.y + c.x*a.y
      - (a.y*b.x + b.y*c.x + c.y*a.x);
}

int cross(pos_t ab[2], pos_t cd[2]) {
  int ccw_ab = ccw(ab[0], ab[1], cd[0]) * ccw(ab[0], ab[1], cd[1]);
  int ccw_cd = ccw(cd[0], cd[1], ab[0]) * ccw(cd[0], cd[1], ab[1]);
  return ccw_ab < 0 && ccw_cd < 0;
}

#ifndef __LOCAL__
int main() {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;
  sfp = freopen("input/jgol_1129.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, cnt = 0;
  pos_t pos[MAX_N][2];

  cin >> N;

  for (int i=0; i<N; i++) {
    cin >> pos[i][0].x >> pos[i][0].y >> pos[i][1].x >> pos[i][1].y;
    for (int j=0; j<i; j++) {
      cnt += cross(pos[j], pos[i]);
    }
  }

  cout << cnt << endl;

#ifndef __LOCAL__
  return 0;
#endif
}

