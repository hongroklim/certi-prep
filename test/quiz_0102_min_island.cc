#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>

#define MAX_N  100
#define MAX_W  9999999

using namespace std;

#ifndef __LOCAL__
int main() {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;
  sfp = freopen("input/quiz_0102.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int TC, N, M, K;
  int src, dest, weight;
  
  // Dijkstra
  int adj[MAX_N+1][MAX_N+1];
  bool U[MAX_N+1];
  int D[MAX_N+1][2];

  cin >> TC;

  for (int tc=1; tc<=TC; tc++) {
    cin >> N >> M >> K;
    
    for (int i=1; i<=N; i++) 
      for (int j=1; j<=N; j++)
        adj[i][j] = MAX_W;

    for (int m=1; m<=M; m++) {
      cin >> src >> dest >> weight;
      adj[src][dest] = weight;
    }

    for (int k=1; k<=K; k++) {
      cin >> src >> weight;
      for (int n=1; n<=N; n++)
        adj[src][n] -= weight;
    }
    
    for (int n=1; n<=N; n++) {
      adj[n][n] = 0;
      U[n] = false;
      D[n][0] = MAX_W;
      D[n][1] = MAX_W;
    }
    
    D[1][0] = 0;
    D[1][1] = 0;

    while (true) {
      int min_n = 0, min_d = MAX_W;

      for (int n=1; n<=N; n++) {
        if (!U[n] && min_d > (D[n][0]+D[n][1])) {
          min_n = n;
          min_d = (D[n][0]+D[n][1]);
        }
      }

      if (min_n == 0) break;
      else U[min_n] = true;

      for (int n=1; n<=N; n++) {
        if ((D[n][0]+D[n][1]) > (D[min_n][0]+D[min_n][1]) + adj[min_n][n]){
          D[n][0] = D[min_n][0] + adj[min_n][n];
        }
      }
    }

    cout << "#" << tc << " " << D[N][0] << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}
