#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#define MAX_N 13

using namespace std;

int N, cnt;
int a[MAX_N];

int candidates(int k, int c[MAX_N]) {
  int n = 0, valid;

  for (int col=0; col<N; col++) {
    valid = 1;
    for (int i=0; i<k; i++) {
      if (col == a[i] || k-i == abs(col-a[i])) {
        valid = 0;
        break;
      }
    }
    if (valid) c[n++] = col;
  }

  return n;
}

void backtrack(int k) {
  if (k == N) {
    cnt++;
    return;
  }

  int c[MAX_N] = {0, };
  int n = candidates(k, c);

  for (int i=0; i<n; i++) {
    a[k] = c[i];
    backtrack(k+1);
  }
}

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/jgol_1889.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> N;

  cnt = 0;
  backtrack(0);
  cout << cnt << endl;

#ifndef __LOCAL__
  return 0;
#endif
}
