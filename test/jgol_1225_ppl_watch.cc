#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <algorithm>
#include <bitset>

#define MAX_N   5000
#define PI      3.141

using namespace std;

typedef struct {
  double r2;
  int n;
} dist_t;

inline double pow2(double x) {
  return x*x;
}

inline double dist2_of(double a[2], double b[2]) {
  return pow2(a[0]-b[0]) + pow2(a[1]-b[1]);
}

bool compare_dist2(dist_t a, dist_t b) {
  return a.r2 < b.r2;
}

#ifndef __LOCAL__
int main() {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  // sfp = freopen("input/jgol_1225.txt", "r", stdin); // 2
  // sfp = freopen("input/jgol_1225_1.txt", "r", stdin); // 2
  // sfp = freopen("input/jgol_1225_2.txt", "r", stdin); // 0
  sfp = freopen("input/jgol_1225_3.txt", "r", stdin); // 4
  EXPECT_NE(sfp, nullptr);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  double K, r2;
  double src[2][2], tgt[MAX_N+1][2];
  dist_t dist2[2][MAX_N+1];

  cin >> N >> src[0][0] >> src[0][1] >> src[1][0] >> src[1][1] >> K;
  r2 = K / PI;

  for (int n=1; n<=N; n++) {
    cin >> tgt[n][0] >> tgt[n][1];
    dist2[0][n] = {dist2_of(src[0], tgt[n]), n};
    dist2[1][n] = {dist2_of(src[1], tgt[n]), n};
  }

  sort(&dist2[0][1], &dist2[0][N+1], compare_dist2);
  sort(&dist2[1][1], &dist2[1][N+1], compare_dist2);
  
  bitset<MAX_N> mark_a, mark_b, mark_ab;
  for (int n=1; n<=N; n++)
    mark_a[dist2[0][n].n] = 1;

  int n_a = N, n_b = 0, max_cnt;
  while (n_a>=0) {
    if (dist2[0][n_a].r2 <= r2) {
      while ((n_b+1) <= N && dist2[0][n_a].r2+dist2[1][n_b+1].r2 <= r2) {
        mark_b[dist2[1][++n_b].n] = 1;
      }
      mark_ab = mark_a | mark_b;
      if (max_cnt < mark_ab.count()) max_cnt = mark_ab.count();
    }
    mark_a[dist2[0][n_a--].n] = 0;
  }

  cout << (N - max_cnt) << endl;

#ifndef __LOCAL__
  return 0;
#endif
}
