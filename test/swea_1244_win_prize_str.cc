#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string STR;
int MAX_DEPTH;
int MAX_VALUE;
vector<int> visited;

bool is_visited(int n) {
  return visited.end() !=
    find(visited.begin(), visited.end(), n);
}

void get_max(int depth) {
  int i, j;
  int n = stoi(STR);
  
  if (depth == MAX_DEPTH) {
    if (n > MAX_VALUE) MAX_VALUE = n;
    return;
  } else if (is_visited(n)) return;
  else visited.push_back(n);
  
  for (i=0; i<STR.length(); i++) {
    for (j=i+1; j<STR.length(); j++) {
      swap(STR[i], STR[j]);
      get_max(depth+1);
      swap(STR[j], STR[i]);
    }
  }
}

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main) {
  FILE *sfp;

  sfp = freopen("input/swea_1244.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  int tc, TC;
  cin >> TC;
  
  for (tc=1; tc<=TC; tc++) {
    cin >> STR >> MAX_DEPTH;
    
    MAX_VALUE = -1;
    visited.clear();

    get_max(0);

    cout << "#" << tc << " " << MAX_VALUE << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}
