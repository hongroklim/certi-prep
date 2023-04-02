#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>

#define MAX_N 500000

using namespace std;

#ifndef __LOCAL__
int main() {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/quiz_0601.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int TC;
  int parent[MAX_N+1];

  cin >> TC;

  for (int tc=1; tc<=TC; tc++) {
    int N, ROOT;
    cin >> N >> ROOT;
    
    // init
    for (int i=1; i<=N; i++)
      parent[i] = 0;
    
    parent[ROOT] = ROOT;

    for (int i=1; i<N; i++) {
      int p, c;
      cin >> p >> c;
      parent[c] = p;
    }

    int cnt = 0;
    
    for (int i=1; i<=N; i++) {
      for (int p=parent[i]; p!=ROOT; p=parent[p])
        if (i < p) cnt++;
      if (i < ROOT) cnt++;
    }

    cout << "#" << tc << " " << cnt << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}
