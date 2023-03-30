#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>

#define MAX_N   300
#define KEY     1000000007

using namespace std;

#ifndef __LOCAL__
int main() {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;
  sfp = freopen("input/quiz_0303.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int TC, i, j;
  int dp[MAX_N+1][MAX_N+1] = {{0, }, };

  dp[2][2] = 1;

  for (i=3; i<=MAX_N; i++)
    for (j=2; j<=i; j++)
      dp[i][j] = (dp[i][j-1] + dp[i-1][i-j+1]) % KEY;

  cin >> TC;

  for (int tc=1; tc<=TC; tc++) {
    int ans = 0;
    cin >> i;

    for (j=2; j<=i; j++)
      ans += dp[i][j];

    cout << "#" << tc << " " << (2*ans) << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}
