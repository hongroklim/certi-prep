#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <stdio.h>
#include <stdlib.h>

#define MAX_N     1000
#define MAX_DIST  9999

using namespace std;

inline int min(unsigned short x, unsigned short y) {
  return (x >= y) ? y : x;
}

#ifndef __LOCAL__
int main() {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/swea_1263.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  int TC, N;
  unsigned short d;
  scanf("%d", &TC);

  unsigned short **D = (unsigned short**)malloc(sizeof(unsigned short*)*MAX_N);
  for (int i=0; i<MAX_N; i++)
    D[i] = (unsigned short*)malloc(sizeof(unsigned short)*(MAX_N-i));

  for (int tc=1; tc<=TC; tc++) {
    scanf("%d", &N);
    
    for (int i=0; i<N; i++) {
      for (int j=0; j<i; j++) {
        scanf("%hd", &d);
      }

      scanf("%hd", &D[i][i]);

      for (int j=i+1; j<N; j++) {
        scanf("%hd", &d);
        D[i][j] = (d==0) ? MAX_DIST : d;
      }
    }

    // Floyd-Warshall
    for (int k=0; k<N; k++)
      for (int i=0; i<N; i++)
        for (int j=i; j<N; j++) {
          if (i <= k && k <= j)
            D[i][j] = min(D[i][k]+D[k][j], D[i][j]);
          else if (i > k)
            D[i][j] = min(D[k][i]+D[k][j], D[i][j]);
          else
            D[i][j] = min(D[i][k]+D[j][k], D[i][j]);
        }
          
    
    unsigned short dist, min_dist = MAX_DIST;
    for (int i=0; i<N; i++) {
      dist = 0;

      for (int j=0; j<i; j++)
        dist += D[j][i];

      for (int j=i+1; j<N; j++)
        dist += D[i][j];

      if (min_dist > dist) min_dist = dist;
    }

    printf("#%d %hd\n", tc, min_dist);
  }

#ifndef __LOCAL__
  return 0;
#endif
}

