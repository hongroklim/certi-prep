#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <queue>

#define MAX_N  100000
#define MAX_W  9999999

using namespace std;

typedef struct node_s {
  int n;
  int supply;
  int weight;

  bool operator<(const node_s n) const {
      return this->weight > n.weight;
  }
} node_t;

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
  int src, dest, weight, min_weight;
  int adj[MAX_N+1][MAX_N+1];

  cin >> TC;

  for (int tc=1; tc<=TC; tc++) {
    cin >> N >> M >> K;
    
    for (int i=1; i<=N; i++) {
      adj[i][0] = 0;
      for (int j=1; j<=N; j++) {
        adj[i][j] = MAX_W;
      }
    }

    for (int m=1; m<=M; m++) {
      cin >> src >> dest >> weight;
      adj[src][dest] = weight;
    }

    for (int k=1; k<=K; k++) {
      cin >> src >> weight;
      adj[src][0] = weight;
    }
     
    min_weight = MAX_W;
    priority_queue<node_t> q;
    q.push({1, 0, 0});
    
    // bfs
    while (!q.empty()) {
      node_t e = q.top();
      q.pop();
      
      if (e.n == N) {
        min_weight = min(min_weight, e.weight);
        break;
      }

      for (int i=1; i<=N; i++) {
        if (i != e.n && adj[e.n][i] != MAX_W) {
          node_t ei = {i, e.supply+adj[e.n][0]-adj[e.n][i], e.weight};

          if (ei.supply < 0) {
            ei.weight -= ei.supply;
            ei.supply = 0;
          }

          if (ei.weight < min_weight) {
            q.push(ei);
          }
        }
      }
    }

    cout << "#" << tc << " " << min_weight << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}
