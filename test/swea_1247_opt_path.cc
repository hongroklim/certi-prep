#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <stdio.h>

#define MAX_N 10

using namespace std;

inline int abs(int x) {
  return (x < 0) ? -x : x;
}

int N, min_dist;
int pos_x[MAX_N+2];
int pos_y[MAX_N+2];
int a[MAX_N];
int memo[MAX_N+2][MAX_N+2];

int dist(int n, int m) {
  if (n > m) { int tmp=n; n=m; m=tmp; }
  if (memo[n][m] == 0) {
    memo[n][m] = abs(pos_x[n]-pos_x[m])+abs(pos_y[n]-pos_y[m]);
  }
  return memo[n][m];
}

int make_candidates(int k, int c[MAX_N]) {
  int perm[MAX_N+1] = {0, };
  for (int i=0; i<k; i++)
    perm[a[i]] = 1;
 
  int n_cands = 0;
  for (int i=1; i<=N; i++)
    if (!perm[i]) c[n_cands++] = i;
 
  return n_cands;
}
 
void backtrack(int k, int acc) {
  if (k == N) {
    acc += dist(a[N-1], MAX_N+1);
    if (min_dist > acc) min_dist = acc;

  } else if (acc < min_dist) {
    int c[MAX_N] = {0, };
    int n_cands = make_candidates(k, c);
 
    for (int i=0; i<n_cands; i++) {
      a[k] = c[i];
      backtrack(k+1, acc+dist(a[k-1], a[k]));
    }
  }
}

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/swea_1247.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  int TC;
  scanf("%d", &TC);

  for (int tc=1; tc<=TC; tc++) {
    scanf("%d", &N);
    scanf("%d %d %d %d", &pos_x[0], &pos_y[0], &pos_x[11], &pos_y[11]);
  
    for (int n=1; n<=N; n++)
      scanf("%d %d", &pos_x[n], &pos_y[n]);
    
    for (int i=0; i<MAX_N+2; i++)
      for (int j=i; j<MAX_N+2; j++)
        memo[i][j] = 0;

    min_dist = 999999;
    for (int i=0; i<N; i++) {
      a[0] = i+1;
      backtrack(1, dist(0, a[0]));
    }
    printf("#%d %d\n", tc, min_dist);
  }

#ifndef __LOCAL__
  return 0;
#endif
}
