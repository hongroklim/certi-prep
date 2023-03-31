#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 200000

using namespace std;

typedef long long ll;

typedef struct {
  int n1, n2, flag;
  ll w;
} edge_t;

bool by_w(edge_t e1, edge_t e2) {
  return e1.w < e2.w;
}

vector<int> adj[MAX_N+1];
ll values[MAX_N+1];
edge_t edges[MAX_N-1];

#ifndef __LOCAL__
int main() {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/quiz_0402.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int TC;
  cin >> TC;

  for (int tc=1; tc<=TC; tc++) {
    int N;
    cin >> N;

    for (int i=1; i<=N; i++) {
      cin >> values[i];
      adj[i][0] = adj[i][1] = 0;
    }
    
    for (int i=1; i<N; i++) {
      int n1, n2;
      cin >> n1 >> n2;
      edges[i] = {n1, n2, 0, values[n1]+values[n2]};
    }

    sort(&edges[1], &edges[N-1], by_w);

    for (int i=1; i<N; i++) {
      adj[edges[i].n1].emplace_back(i);
      adj[edges[i].n2].emplace_back(i);
    }
    
    edges[1].flag = 1;
    int sum_w[3] = {0, edges[1].w, 0};

    for (int i=2; i<N; i++) {
      for (auto e_i : adj[edges[i].n1]) {
        if (e_i != i && edges[e_i].flag) {
          edges[i].flag = edges[e_i].flag;
          break;
        }
      }
      for (auto e_i : adj[edges[i].n2]) {
        if (e_i != i && edges[e_i].flag) {
          edges[i].flag = edges[e_i].flag;
          break;
        }
      }

      if (edges[i].flag) {
        sum_w[edges[i].flag] += edges[i].w;
        continue;
      }

      
    }

    cout << "#" << tc << " " << 1 << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}

