#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
 
#define UNKNOWN 1000001
 
using namespace std;
 
typedef struct comp_s {
  int b;
  int w;
 
  bool operator < (const comp_s& comp) const {
    return b < comp.b;
  }
 
} comp_t;
 
#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/swea_1849.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
  int TC;
  int N, M, i, j;
 
  map<int, vector<comp_t>> comps;
  int *res;
 
  comp_t s[100000];
  int s_size;
 
  cin >> TC;
 
  for(int tc=1; tc<=TC; tc++){
    cin >> N >> M;
 
    comps.clear();
    res = new int[M];
    res[0] = 0;
 
    for (int m=0; m<M; m++) {
      int a, b, t, w;
      bool is_swapped = false;
      char c;
 
      // read a, b and swap if needed
      cin >> c >> a >> b;
      if (a > b) {
        t = a;
        a = b;
        b = t;
 
        is_swapped = true;
      }
 
      if (c == '!') {
        // add comps
        cin >> w;
 
        auto it = comps.find(a);
        if (it != comps.end()) {
          it->second.push_back({b, is_swapped ? -w : w});
          sort(it->second.begin(), it->second.end());
        } else {
          comps[a] = vector<comp_t>(1, {b, is_swapped ? -w : w});
        }
 
      } else {
        // calc with dfs
        s_size = 0;
        s[s_size++] = {a, 0};
 
        int weights = UNKNOWN;
 
        while (s_size > 0) {
          comp_t e = s[--s_size];
 
          if (e.b == b) {
            weights = e.w;
            break;
          }
 
          auto it = comps.find(e.b);
          if (it != comps.end()) {
            for (i=it->second.size()-1; i>=0; i--) {
              if (it->second[i].b > b) continue;
              s[s_size++] = {it->second[i].b, e.w + it->second[i].w};
            }
          }
        }
 
        res[++res[0]] = is_swapped ? -weights : weights;
      }
    }
 
#ifdef __LOCAL__
    for (auto kv=comps.begin(); kv!=comps.end(); kv++) {
      cout << kv->first << ": ";
      for (auto e : kv->second)
        cout << "(" << e.b << ", " << e.w  << ") ";
      cout << endl;
    }
#endif

    cout << "#" << tc;
    for (i=1; i<=res[0]; i++) {
      if (res[i] == UNKNOWN || res[i] == -UNKNOWN) cout << " UNKNOWN";
      else cout << " " << res[i];
    }
    cout << endl;
 
    delete[] res;
  }
 
#ifndef __LOCAL__
  return 0;
#endif
}
