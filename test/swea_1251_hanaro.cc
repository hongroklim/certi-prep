#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>

#define MAX_N 1000
#define INF 99999999999999

using namespace std;

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/swea_1251.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  cout << fixed;
  cout.precision(0);

  int TC, N, i, j, k;
  
  int xs[MAX_N];
  int ys[MAX_N];
  int q[MAX_N];

  unsigned long *key;
  int q_size;

  unsigned long acc;
  double E;

  cin >> TC;
  
  for (int tc=1; tc<=TC; tc++) {
    cin >> N;
    
    key = new unsigned long[N];

    for (i=0; i<N; i++)
      cin >> xs[i];

    for (i=0; i<N; i++) {
      cin >> ys[i];
      q[i] = i;
      key[i] = INF;
    }
    
    cin >> E;
    
    acc = 0;
    key[0] = 0;
    q_size = N;

    while (q_size > 0) {
      int min_i;
      unsigned long min_key = INF;
      
      // find min
      for (i=0; i<q_size; i++) {
        if (min_key > key[q[i]]) {
          min_i = i;
          min_key = key[q[i]];
        }
      }
      
      // pop
      int min_v = q[min_i];
      q[min_i] = q[--q_size];
      acc += min_key;

      // visit others in queue 
      for (i=0; i<q_size; i++) {
        // calc L^2
        unsigned long x, y, dist;
        x = (xs[min_v]>=xs[q[i]]) ? xs[min_v]-xs[q[i]] : xs[q[i]]-xs[min_v];
        y = (ys[min_v]>=ys[q[i]]) ? ys[min_v]-ys[q[i]] : ys[q[i]]-ys[min_v];
        dist = (x*x) + (y*y);
        
        if (key[q[i]] > dist) key[q[i]] = dist;
      }
    }

    cout << "#" << tc << " " << (E * acc) << endl;
    
    delete []key;
  }

#ifndef __LOCAL__
  return 0;
#endif
}
