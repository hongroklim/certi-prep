#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <cmath>

using namespace std;

int memo[19][18] = {}; // with zero

int nCr(int n, int r) {
  if (n == r || r == 0) return 1;
  else if (memo[n][r] != 0) return memo[n][r];

  memo[n][r] = nCr(n-1, r) + nCr(n-1, r-1);
  return memo[n][r];
}

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/swea_1266.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif

  int tc, TC;
  double a_prob, b_prob;
  double a_acc, b_acc;
  int i, ncr;
  
  int n = 18;
  int r[7] = {2, 3, 5, 7, 11, 13, 17};
  
  // print format
  cout << fixed;
  cout.precision(6);

  cin >> TC;
  
  for(tc=1; tc<=TC; tc++){
    cin >> a_prob >> b_prob;
    
    a_prob /= 100.0;
    b_prob /= 100.0;

    a_acc = 0.0;
    b_acc = 0.0;
    
    for (i=0; i<7; i++) {
      ncr = nCr(n, r[i]);

      a_acc += ncr * pow(a_prob, r[i]) * pow(1-a_prob, n-r[i]);
      b_acc += ncr * pow(b_prob, r[i]) * pow(1-b_prob, n-r[i]);
    }
    
    cout << "#" << tc << " " << 1.0 - (1-a_acc)*(1-b_acc) << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}
