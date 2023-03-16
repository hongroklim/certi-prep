#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>

using namespace std;

int bin_search(int *N, int i, int j, int key) {
  int mid;

  while (i <= j) {
    mid = (j + i) / 2;

    if (N[mid] < key) i = mid + 1;
    else if (key < N[mid]) j = mid - 1;
    else return mid+1;
  }

  return 0;
}

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/jgol_1295.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  int N, *ns, T, t;
  int i;
  
  // input N and ns
  cin >> N;
  ns = new int[N];
  for (i=0; i<N; i++) {
    cin >> ns[i];
  }
  
  // input T and ts
  // then search
  cin >> T;
  for (i=0; i<T; i++) {
    cin >> t;
    cout << bin_search(ns, 0, N-1, t) << "\n";
  }

#ifndef __LOCAL__
  return 0;
#endif
}
