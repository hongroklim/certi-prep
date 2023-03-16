#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <map>

using namespace std;

map<int, long long> memo;

int to_key(int n, int k) {
  return n*1000 + k;
}

long long max_par(int n, int k) {
  int i;
  long long m, max=-1;

  if (n == k) return 1;
  else if (k == 1) return n;

  auto pos = memo.find(to_key(n, k));
  if (pos != memo.end()) return pos->second;
  
  for (i=1; i<=n/2; i++) {
    m = i * max_par(n-i, k-1);
    if (m > max) max = m;
  }
  
  memo[to_key(n, k)] = max;
  return max;
}

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/swea_1265.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  int tc, TC;
  int N, P;
  
  cin >> TC;

  for(tc=1; tc<=TC; tc++){
    cin >> N >> P;
    cout << "#" << tc << " " << max_par(N, P) << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}

