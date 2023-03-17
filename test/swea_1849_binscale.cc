#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>

#define MAX_N 1000002

using namespace std;

int parent[MAX_N];
int ranks[MAX_N];
int W[MAX_N];

int find_set(int n) {
  // for root node
  if (parent[n] == n) return n;

  // compress path recursively 
  W[n] += W[parent[n]];
  return (parent[n] = find_set(parent[n]));
}

void union_set(int a, int b, int w) {
  int pa = find_set(a);
  int pb = find_set(b);

  // already in same set
  if (pa == pb) return;
  
  if (ranks[pa] < ranks[pb]) {
    parent[pa] = pb;
    W[pa] = W[b] - W[a] + w;
  } else {
    parent[pb] = pa;
    W[pb] = W[a] - W[b] - w;
    if (ranks[sa] == ranks[sb]) ranks[sa]++;
  }

  //   W[a] - W[b] = w
  // = W[a] - (W[sb] + W[b]) = w
  // = W[sb] = W[a] - W[b] - w
}

#ifndef __LOCAL__
int main(int argc, char **argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main) {
  FILE *sfp;

  sfp = freopen("input/swea_1849.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  ios_base::sync_with_stdio(false);

  int TC, N, M;
  int a, b, w;
  char c;
  cin >> TC;

  for (int tc=1; tc<=TC; tc++) {
    cin >> N >> M;

    for (int i=1; i<=N; i++) {
      parent[i] = i;
      W[i] = 0;
      ranks[i] = 0;
    }
    
    cout << "#" << tc << " ";
    for (int m=1; m<=M; m++) {
      cin >> c >> a >> b;

      if (c == '!') {
        cin >> w;
        union_set(a, b, w);
      } else {
        if (find_set(a) == find_set(b)) {
          cout << (W[a] - W[b]) << " ";
        } else {
          cout << "UNKNOWN ";
        }
      }
    }
    cout << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}
