#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <vector>

using namespace std;

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/swea_1267.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  int tc, TC = 10;
  int V, E;
  int prev, next;
  int i, j, k;

  vector<int> graph[1001];
  int res[1001];
  int leaves[1001];

  for (tc=1; tc<=TC; tc++) {
    res[0] = 0;

    cin >> V >> E;
    
    for (i=1; i<=V; i++)
      graph[i].clear();

    for (i=0; i<E; i++) {
      cin >> prev >> next;
      graph[prev].push_back(next);
    }

    while (true) {
      leaves[0] = 0;
      
      for (i=1; i<=V; i++) {
        if (graph[i].size() == 0) {
          leaves[++leaves[0]] = i;
          graph[i].push_back(0);
        }
      }

      if (leaves[0] == 0) break;
      
      for (i=1; i<=V; i++) {
        for (j=0; j<graph[i].size(); j++) {
          for (k=1; k<=leaves[0]; k++) {
            if (graph[i][j] == leaves[k]) {
              graph[i].erase(graph[i].begin()+(j--));
              break;
            }
          }
        }
      }

      for (i=1; i<=leaves[0]; i++)
        res[++res[0]] = leaves[i];
    }

    cout << "#" << tc;
    for (i=res[0]; i>=1; i--)
      cout << " " << res[i];
    cout << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}
