#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int *num;
int *seg_tree;
int find_a, find_b;

int tree_size(int n) {
  int x = (int)(ceil(log2(n)));
  return 2*(int)pow(2, x) - 1;
}

inline int max_i(int a, int b) {
  return a >= b ? a : b;
}

void build_max(int n, int a, int b) {
  if (a == b) {
    seg_tree[n] = num[a];
    return;
  }
  
  int left = 2*n, right = 2*n + 1, m = (a+b)/2;

  build_max(left, a, m);
  build_max(right, m+1, b);
  
  seg_tree[n] = max_i(seg_tree[left], seg_tree[right]);
}

int find_max(int n, int a, int b) {
  if (b < find_a || find_b < a) return 0;
  if (find_a <= a && b <= find_b) return seg_tree[n];
  
  int left = 2*n, right = 2*n + 1, m = (a+b)/2;
  
  return max_i(find_max(left, a, m), find_max(right, m+1, b));
}

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/jgol_1726.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  int N, Q, i;
  scanf("%d %d", &N, &Q);

  num = (int *) malloc(sizeof(int) * (N+1));
  seg_tree = (int *) malloc(sizeof(int) * tree_size(N+1));
  
  num[0] = 0;
  for (i=1; i<=N; i++)
    scanf("%d", &num[i]);
  
  build_max(1, 1, N);

  for (i=1; i<=Q; i++) {
    scanf("%d %d", &find_a, &find_b);
    printf("%d\n", find_max(1, 1, N));
  }

  free(num);
  free(seg_tree);
  
#ifndef __LOCAL__
  return 0;
#endif
}
