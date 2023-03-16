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

  sfp = freopen("input/swea_1245.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  cout << fixed;
  cout.precision(10);

  int tc, TC;
  int N, i, j;
  double x[19], m[19];
  double begin, end, diff, X;
  
  cin >> TC;

  for(tc=1; tc<=TC; tc++){
    // input
    cin >> N;
    for (i=0; i<N; i++)
      cin >> x[i];
    for (i=0; i<N; i++)
      cin >> m[i];
    
    cout << "#" << tc;

    for (i=1; i<N; i++) {
      begin = x[i-1];
      end = x[i];

      while (true) {
        X = (begin+end) / 2.0;
        diff = 0.0;

        for (j=0; j<i; j++)
          diff += m[j]/((x[j]-X)*(x[j]-X));
        for (j=i; j<N; j++)
          diff -= m[j]/((x[j]-X)*(x[j]-X));

        if (diff > 0.0) begin = X;
        else if (diff < 0.0) end = X;
        else break;

        if (end-begin < 2e-12f) break;
      }
      cout << " " << X;
    }
    cout << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}
