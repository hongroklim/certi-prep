#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <vector>

#define MAX_N 100000
#define MAX_C 1000000000

using namespace std;

typedef struct {
  int n, c;
} edge_t;

#ifndef __LOCAL__
int main() {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/quiz_0301.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int TC;
  vector<edge_t> G[MAX_N+1];
  int key[MAX_N+1];
  bool visited[MAX_N+1];

  cin >> TC;

  for (int tc=1; tc<=TC; tc++) {
    int N, M;
    cin >> N >> M;
    
    for (int i=1; i<=N; i++) {
      G[i].clear();
      key[i] = MAX_C;
      visited[i] = false;
    }
    
    for (int i=1; i<=M; i++) {
      int n1, n2, c;
      cin >> n1 >> n2 >> c;
      G[n1].push_back({n2, c});
      G[n2].push_back({n1, c});
    }
    
    long long sum = 0;
    key[1] = 0;

    for (int i=1; i<=N; i++) {
      int min_n = 0, min_key = MAX_C;
      for (int n=1; n<=N; n++) {
        if (!visited[n] && min_key > key[n]) {
          min_n = n; min_key = key[n];
        }
      }
      
      if (min_n == 0) {
        sum = -1; break;
      }

      visited[min_n] = true;
      sum += key[min_n];

      for (edge_t e : G[min_n])
        if (!visited[e.n] && min_key <= e.c && key[e.n] > e.c)
          key[e.n] = e.c;
    }

    cout << "#" << tc << " " << sum << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}
