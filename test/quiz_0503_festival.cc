#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>

#define MAX_N 500       // S
#define MAX_M 500       // C
#define MAX_C 5001      // M
#define INF_C 99999999

using namespace std;

int N, M;
int cost[MAX_N+2][MAX_M+2];
int D[3][MAX_N+2][MAX_M+2];
bool U[MAX_N+2][MAX_M+2];

inline int min(int a, int b) {
  return a < b ? a : b;
}

void dijkstra(int flag, int begin_i, int begin_j) {
  // init
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=M; j++) {
      D[flag][i][j] = INF_C;
      U[i][j] = false;
    }
  }
  
  D[flag][begin_i][begin_j] = 0;

  for (int remains = N*M; remains; remains--) {
    // extract min
    int min_i, min_j, min_c = INF_C;
    for (int i=1; i<=N; i++) {
      for (int j=1; j<=M; j++) {
        if (!U[i][j] && min_c > D[flag][i][j]) {
          min_i = i; min_j = j; min_c = D[flag][i][j];
        }
      }
    }

    U[min_i][min_j] = true;
    
    const int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (int k=0; k<4; k++) {
      int n_i = min_i+d[k][0], n_j = min_j+d[k][1];
      if (cost[n_i][n_j])
        D[flag][n_i][n_j] = min(D[flag][n_i][n_j], min_c + cost[n_i][n_j]);
    }
  }
}

#ifndef __LOCAL__
int main() {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;
  sfp = freopen("input/quiz_0503.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int TC;
  cin >> TC;

  for (int tc=1; tc<=TC; tc++) {
    int s1_i, s1_j, s2_i, s2_j, d_i, d_j;
    cin >> N >> M >> s1_i >> s1_j >> s2_i >> s2_j >> d_i >> d_j;

    for (int i=1; i<=N; i++)
      for (int j=1; j<=M; j++)
        cin >> cost[i][j];
    
    dijkstra(0, s1_i, s1_j);
    dijkstra(1, s2_i, s2_j);
    dijkstra(2, d_i, d_j);

    // find separation point
    int min_c = INF_C;
    for (int i=1; i<=N; i++)
      for(int j=1; j<=M; j++)
        min_c = min(min_c, D[0][i][j]+D[1][i][j]+D[2][i][j]-(2*cost[i][j]));
    
    // add beginning cost
    min_c += cost[s1_i][s1_j] + cost[s2_i][s2_j];

    cout << "#" << tc << " " << min_c << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}

