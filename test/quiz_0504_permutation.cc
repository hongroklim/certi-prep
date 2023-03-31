#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>

#define MAX_N 100000

using namespace std;

typedef struct {
  int i, n;
} num_t;

bool by_n(num_t n1, num_t n2) {
  return n1.n < n2.n;
}

#ifndef __LOCAL__
int main() {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/quiz_0504.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int TC, i, j, k;
  int num[MAX_N];
  num_t sorted[MAX_N];

  cin >> TC;

  for (int tc=1; tc<=TC; tc++) {
    int N, K;
    cin >> N >> K;

    for (i=0; i<N; i++) {
      cin >> num[i];
      sorted[i].i = i;
      sorted[i].n = num[i];
    }
    
    sort(sorted, &sorted[N-1], by_n);
    
    int min_len = N+1, cases = 0;
    i = 0, j = 1;

    for (i=0; i<N-1; i++) {
      for (j=i+1; j<N; j++) {
        int diff = sorted[j].n - sorted[i].n;
        
        if (diff > K) break;
        else if (diff < K) continue;
        
        // if diff == K
        int len = abs(sorted[i].i-sorted[j].i)+1;
        if (min_len < len) continue;

        // check range
        int begin = min(sorted[i].i, sorted[j].i)+1;
        int end = max(sorted[i].i, sorted[j].i);

        for (k=begin; k<end; k++)
          if (num[k] < sorted[i].n || sorted[j].n < num[k])
            break;
        
        if (k<end) continue;

        cout << sorted[i].n << " " << sorted[j].n << endl;

        if (min_len > len) {
          min_len = len;
          cases = 0;
        }

        cases++;
      }
    }
    
    if (min_len == N+1) {
      cout << "#" << tc << " -1" << endl;
    } else {
      cout << "#" << tc << " " << min_len << " " << cases << endl;
    }
  }

#ifndef __LOCAL__
  return 0;
#endif
}
