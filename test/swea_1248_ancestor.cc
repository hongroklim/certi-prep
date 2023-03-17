#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <set>

#define MAX_V 100000

using namespace std;

int v_parent[MAX_V+1];
int v_left[MAX_V+1];
int v_right[MAX_V+1];

int count_nodes(int n) {
  int cnt = 1;
  if (v_left[n]) cnt += count_nodes(v_left[n]);
  if (v_right[n]) cnt += count_nodes(v_right[n]);
  return cnt;
}

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/swea_1248.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  int TC;
  cin >> TC;

  for (int tc=1; tc<=TC; tc++) {
    int V, E, v1, v2;
    cin >> V >> E >> v1 >> v2;
    
    for (int v=1; v<=V; v++)
      v_parent[v] = 0, v_left[v] = 0, v_right[v] = 0;

    for (int e=1; e<=E; e++) {
      int parent, child;
      cin >> parent >> child;

      v_parent[child] = parent;
      if (v_left[parent] == 0) v_left[parent] = child;
      else v_right[parent] = child;
    }

    int p1 = v1, p2 = v2, p12;
    set<int> parents;
    while (true) {
      if (p1 != 0) {
        if (!parents.insert(p1).second) {
          p12 = p1; break;
        }
        p1 = v_parent[p1];
      }
      if (p2 != 0) {
        if (!parents.insert(p2).second) {
          p12 = p2; break;
        }
        p2 = v_parent[p2];
      }
    }

    int cnt = count_nodes(p12);

    cout << "#" << tc << " " << p12 << " " << cnt << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}

