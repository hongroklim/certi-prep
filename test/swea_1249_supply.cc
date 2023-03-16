#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>

#define MAX_INT 99999

using namespace std;

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/swea_1249.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  int TC;
  int n, i, j, t;
  char line[100];
  
  int G[100][100];
  bool U[100][100];
  int D[100][100];

  int di[4] = {1, 0, -1, 0};
  int dj[4] = {0, 1, 0, -1};

  cin >> TC;

  for (int tc=1; tc<=TC; tc++) {
    cin >> n;
    
    for (i=0; i<n; i++) {
      cin >> line;
      for (j=0; j<n; j++) {
        G[i][j] = line[j] - '0';
        U[i][j] = false;
        D[i][j] = MAX_INT;
      }
    }
    
    U[0][0] = true;
    
    D[0][0] = 0;
    D[0][1] = D[0][0] + G[0][1];
    D[1][0] = D[0][0] + G[1][0];

    while (D[n-1][n-1] == MAX_INT) {
      // find min
      int min_i, min_j, min_d = MAX_INT;
      
      for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
          if (!U[i][j] && D[i][j] < min_d) {
            min_i = i;
            min_j = j;
            min_d = D[i][j];
          }
        }
      }

      U[min_i][min_j] = true;

      for (int k=0; k<4; k++) {
        i = min_i + di[k];
        j = min_j + dj[k];
        
        if (i <= n && j <= n && i >= 0 && j >= 0
            && D[i][j] > (D[min_i][min_j] + G[i][j])) {
          D[i][j] = D[min_i][min_j] + G[i][j];
        }
      }
    }

    cout << "#" << tc << " " << D[n-1][n-1] << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}
