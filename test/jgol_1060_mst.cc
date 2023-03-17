#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>

#define INF 100001

using namespace std;

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/jgol_1060.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  int N, ans, i, j;

  int table[100][100];
  int key[100];

  int queue[100];
  int q_size = 0;

  cin >> N;

  for (i=0; i<N; i++) {
    queue[q_size++] = i;
    key[i] = INF;

    for (j=0; j<N; j++) {
      cin >> table[i][j];
    }
  }
  
  key[0] = 0;
  ans = 0;

  while (q_size > 0) {
    int min_i = -1;
    int min_key = INF;
    
    // find min
    for (i=0; i<q_size; i++) {
      if (min_key > key[queue[i]]) {
        min_i = i;
        min_key = key[queue[i]];
      }
    }
    
    int min_v = queue[min_i];
    queue[min_i] = queue[--q_size];
    ans += min_key;

    for (i=0; i<q_size; i++) {
      if (key[queue[i]] > table[min_v][queue[i]]) {
        key[queue[i]] = table[min_v][queue[i]];
      }
    }
  }

  cout << ans << endl;

#ifndef __LOCAL__
  return 0;
#endif
}
