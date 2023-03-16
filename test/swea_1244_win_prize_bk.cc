#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <cmath>

using namespace std;

int LENGTH;
int DEPTH;

bool is_desc(int num) {
  int small = -2;
  int big = -1;

  while (num > 0) {
    small = big;
    big = num % 10;
    if (small > big) return false;
    num /= 10;
  }

  return true;
}

int digit_at(int num, int i) {
  return int(num/pow(10,i)) % 10;
}

int swap(int num, int i, int j) {
  int n_i = digit_at(num, i);
  int n_j = digit_at(num, j);
  
  return num + (pow(10,i)*(-n_i+n_j))
          + (pow(10,j)*(-n_j+n_i));
}


int get_max(int num, int depth) {
  int i, j;
  int m, max = -1;
  
  if (depth >= DEPTH) {
    cout << num << " ";
    return num;
  }
  
  for (i=0; i<LENGTH-1; i++) {
    for (j=i+1; j<LENGTH; j++) {
      if (digit_at(num, i) < digit_at(num, j)) {
        continue;
      } else if (digit_at(num, i) == digit_at(num, j)) {
        m = get_max(num, depth+2);
      } else {
        m = get_max(swap(num, i, j), depth+1);
      }

      if (m > max) {
        max = m;
        if (is_desc(max)) return max;
      }
    }
  }

  return max;
}


#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(FuncTest, swap) {
  GTEST_SKIP();
  EXPECT_EQ(swap(123, 0, 2), 321);
  EXPECT_EQ(swap(12345, 0, 2), 12543);
}

TEST(MainTest, main) {
  FILE *sfp;

  sfp = freopen("input/swea_1244.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  int tc, TC;
  int i, n, t;
  int ans;

  cin >> TC;
  
  for(tc=1; tc<=TC; tc++){
    // input numbers
    cin >> n;
    cin >> DEPTH;
    
    // calc length
    t = n;
    for (i=0; i<6 && t>0; i++) {
      t /= 10;
    }
    LENGTH = i;
    
    ans = get_max(n, 0);

    cout << "#" << tc << " " << ans << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}


