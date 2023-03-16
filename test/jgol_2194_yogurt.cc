#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>

using namespace std;

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  // sfp = freopen("input/jgol_2194.txt", "r", stdin); // 126900
  sfp = freopen("input/jgol_2194_1.txt", "r", stdin); // 234500000000
  EXPECT_NE(sfp, nullptr);
#endif
  
  unsigned long int ans = 0;
  int i;
  int N, S;
  int *costs, *reqs;
  int min_cost = 5001;
  
  // input
  cin >> N >> S;

  costs = new int[N];
  reqs = new int[N];

  for (i=0; i<N; i++) {
    cin >> costs[i] >> reqs[i];
  }
  
  for (i=0; i<N; i++) {
    // calc current min cost
    min_cost += S;
    if(costs[i] < min_cost) min_cost = costs[i];
    
    // acc
    ans += min_cost * reqs[i];
  }

  cout << ans << endl;

#ifndef __LOCAL__
  return 0;
#endif
}

