#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <stdio.h>

using namespace std;

#ifndef __LOCAL__
int main() {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;
  // sfp = freopen("input/jgol_1825.txt", "r", stdin); // 10 <br> 0 4
  // sfp = freopen("input/jgol_1825_1.txt", "r", stdin); // 10 <br> 3 1
  sfp = freopen("input/jgol_1825_2.txt", "r", stdin); // 216 <br> 1 0 1 20 4 2 2
  EXPECT_NE(sfp, nullptr);
#endif
  int M, N, i, j, k, p;
  int table[21][301] = { {0, }, };
  int d[21][301] = { {0, }, };
  int ks[21][301] = { {0, }, };

  scanf("%d %d", &M, &N);

  for (j=1; j<=M; j++) {
    scanf("%d", &table[0][j]);
    for (i=1; i<=N; i++)
      scanf("%d", &table[i][j]);
  }
  
  for (j=1; j<=M; j++) {
    for (i=1; i<=N; i++) {
      d[i][j] = d[i-1][j];
      ks[i][j] = 0;
      for (k=1; k<=j; k++) {
        p = d[i-1][j-k] + table[i][k];
        if (d[i][j] <= p) {
          d[i][j] = p;
          ks[i][j] = k;
        }
      }
    }
  }
  
#ifdef __LOCAL__
  for (i=0; i<=N; i++) {
    for (j=0; j<=M; j++) {
      cout << d[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  for (i=0; i<=N; i++) {
    for (j=0; j<=M; j++) {
      cout << ks[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
#endif
    
  j = M;
  for (i=N; i!=0; i--) {
    ks[i][0] = ks[i][j];
    j -= ks[i][j];
  }

  printf("%d\n", d[N][M]);
  for (i=1; i<=N; i++)
    printf("%d ", ks[i][0]);

#ifndef __LOCAL__
  return 0;
#endif
}
