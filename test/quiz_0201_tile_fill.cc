#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>

using namespace std;

#ifndef __LOCAL__
int main() {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/quiz_0201.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int TC;
  cin >> TC;

  for (int tc=1; tc<=TC; tc++) {
    int N, X, Y;
    cin >> N >> X >> Y;

    cout << "#" << tc << " " << 1 << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}

