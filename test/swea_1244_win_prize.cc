#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> visited;

bool is_visited(int num) {
  return visited.end() !=
    find(visited.begin(), visited.end(), num);
}

vector<int> to_vec(int n) {
  int i;
  vector<int> vec;

  for (i=0; i<6 && n>0; i++) {
    vec.push_back(n%10);
    n /= 10;
  }

  return vec;
}

int to_int(vector<int> vec) {
  int i, res = 0;

  for (i=0; i<vec.size(); i++) {
    res += vec[i]*pow(10, i);
  }

  return res;
}

vector<int> swap(vector<int> vec, int i, int j) {
  int temp = vec[i];
  vec[i] = vec[j];
  vec[j] = temp;
  
  return vec;
}

int get_max(vector<int> vec, int max_depth, int depth) {
  int i, j;
  int m, max = -1;
  int num = to_int(vec);
  
  if (depth == max_depth) return num;
  else if (is_visited(num)) return -1;
  else visited.push_back(num);
  
  for (i=0; i<vec.size()-1; i++) {
    for (j=i+1; j<vec.size(); j++) {
      m = get_max(swap(vec, i, j), max_depth, depth+1);
      if (m > max) max = m;
    }
  }

  return max;
}

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(VectorTest, cast) {
  GTEST_SKIP();
  int num = 1234;
  vector<int> vec = to_vec(num);
  EXPECT_EQ(vec[0], 4);
  EXPECT_EQ(to_int(vec), num);
}

TEST(MainTest, main) {
  FILE *sfp;

  sfp = freopen("input/swea_1244.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  int tc, TC;
  int n, max_depth;
  int ans;

  cin >> TC;
  
  for (tc=1; tc<=TC; tc++) {
    cin >> n >> max_depth;
    
    visited.clear();
    ans = get_max(to_vec(n), max_depth, 0);

    cout << "#" << tc << " " << ans << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}
