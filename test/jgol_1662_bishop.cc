#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <stdio.h>
#define MAX_N 10

int f;
int a_max[2];
int a_size[2];
int a[2][MAX_N*MAX_N/2];
int a_pos[2][MAX_N*MAX_N/2][2];

inline int abs(int x) {
  return (x > 0) ? x : -x;
}

int is_candidate(int k) {
  for (int i=0; i<k; i++)
    if (a[f][i] && (a_pos[f][k][0]-a_pos[f][i][0]
                    == abs(a_pos[f][k][1]-a_pos[f][i][1])))
      return 0;

  return 1;
}

void backtrack(int k) {
  if (k == a_size[f]) {
    int cnt = 0;

    for (int i=0; i<a_size[f]; i++)
      cnt += a[f][i];

    if (a_max[f] < cnt) a_max[f] = cnt;
    
    return;

    printf("[%3d/%3d] ", cnt, a_max[f]);
    for (int i=0; i<a_size[f]; i++)
      printf("%d", a[f][i]);
    printf("\n");

    return;
  }

  if (is_candidate(k)) {
    a[f][k] = 1;
    backtrack(k+1);
  }

  a[f][k] = 0;
  backtrack(k+1);
}

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  // sfp = freopen("input/jgol_1662.txt", "r", stdin);  // 7
  // sfp = freopen("input/jgol_1662_1.txt", "r", stdin);  // 6
  sfp = freopen("input/jgol_1662_2.txt", "r", stdin);  // 18
  EXPECT_NE(sfp, nullptr);
#endif

  int N;
  scanf("%d", &N);

  a_size[0] = a_size[1] = 0;

  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      int cell;
      scanf("%d", &cell);
      if (cell) {
        f = (i&1)^(j&1);
        a_pos[f][a_size[f]][0] = i;
        a_pos[f][a_size[f]][1] = j;
        a_size[f]++;
      }
    }
  }

  a_max[0] = a_max[1] = 0;
  f = 0; backtrack(0);
  f = 1; backtrack(0);

  printf("%d\n", a_max[0] + a_max[1]);

#ifndef __LOCAL__
  return 0;
#endif
}
