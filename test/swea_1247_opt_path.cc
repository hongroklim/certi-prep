#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX_N 10

using namespace std;

int N, min_dist;
int pos_x[MAX_N+2];
int pos_y[MAX_N+2];
int a[MAX_N];
int memo[MAX_N+2][MAX_N+2];

int dist(int n, int m) {
  if (n > m) {int tmp = n; n = m; m = tmp;}
  if (memo[n][m] == 0) {
    memo[n][m] = abs(pos_x[n]-pos_x[m])+abs(pos_y[n]-pos_y[m]);
  }
  return memo[n][m];
}

int sum_dist() {
  int acc = dist(0, a[0]+1);

  for (int i=0; i<N-1; i++)
    acc += dist(a[i]+1, a[i+1]+1);

  return acc + dist(a[N-1]+1, MAX_N+1);
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
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int TC;
  cin >> TC;

  for (int tc=1; tc<=TC; tc++) {
    cin >> N;
    cin >> pos_x[0] >> pos_y[0] >> pos_x[11] >> pos_y[11];
  
    for (int n=1; n<=N; n++)
      cin >> pos_x[n] >> pos_y[n];
    
    for (int i=0; i<MAX_N+2; i++)
      for (int j=i; j<MAX_N+2; j++)
        memo[i][j] = 0;

    min_dist = 999999;
    
    for (int i=0; i<N; i++) a[i] = i;

    do {
      int dist = sum_dist();
      if (min_dist > dist) min_dist = dist;
    } while(next_permutation(a, a+N));

    cout << "#" << tc << " " << min_dist << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}
