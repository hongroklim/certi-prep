#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <vector>

#define MAX_N 100

using namespace std;

typedef struct {
  int j;
  int width;
  int height;
} pos_t;

// char board[MAX_N+1][MAX_N+1];
char line[MAX_N+1];

vector<pos_t> scanned;

void do_scan(int begin, int end) {
  for (int j=begin; j<end; j++) {
    if (line[j] == '0') continue;

    pos_t p = {j, 1, 1};
    while (line[j+p.width] != '0') p.width++;
    scanned.push_back(p);
    j += p.width;
  }
}

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/swea_1260.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int TC, N, i, j, end_j, r, k;

  // flow: scanned => cur => pos;
  vector<pos_t> cur;
  vector<pos_t> pos;
  
  cin >> TC;

  for (int tc=1; tc<=TC; tc++) {
    cin >> N;
    
    for (i=0; i<N; i++) {
      for (j=0; j<N; j++) {
        cin >> line[j];
      }
      line[N] = '0';
      
      // scan line by line
      j = 0;
      end_j = cur.empty() ? N : cur[0].j;
      do_scan(j, end_j);

      for (auto it=cur.begin(); it<cur.end(); it++) {
        j = it->j + it->width;
        end_j = (it+1) == cur.end() ? N : (it+1)->j;

        if (line[it->j] != '0') {
          // detected block continues
          it->height++;
        } else {
          // detected block doesn't appear anymore
          // from cur to pos
          pos.push_back(*it);
          cur.erase(it--);
        }
        
        // scan between detected blocks
        do_scan(j, end_j);
      }
      
      if (!scanned.empty()) {
        // from scanned to cur
        // (like merge phase in mergesort)
        vector<pos_t>::iterator s = scanned.begin(), c = cur.begin();
        while (s < scanned.end()) {
          while (c < cur.end() && c->j < s->j) c++;
          cur.insert(c++, *s);
          s++;
        }
        scanned.clear();
      }
    }

    if (!cur.empty()) {
      // from cur to pos
      pos.insert(pos.end(), cur.begin(), cur.end());
      cur.clear();
    }
    
    // find sequences 
    int w_h[MAX_N+1] = {0, };   // width - height pair
    int h_w[MAX_N+1] = {0, };   // height - width pair

    for (int i=0; i<MAX_N+1; i++)
      w_h[i] = h_w[i] = 0;

    for (auto it=pos.begin(); it<pos.end(); it++) {
      w_h[it->width] = it->height;
      h_w[it->height] = it->width;
    }
    
    // flow: (d_prev & d_next) => d
    vector<int> d_next, d_prev, d;

    // apppend chain (from width to height)
    for (i=pos[0].width; i>0; i=w_h[i])
      d_next.push_back(i);

    // apppend chain (from height to width)
    i = d_next.empty() ? pos[0].height : h_w[d_next[0]];
    for (; i>0; i=h_w[i])
      d_prev.push_back(i);
    
    // concat d_prev(in reverse) and d_next
    if(!d_prev.empty()) d.insert(d.begin(), d_prev.rbegin(), d_prev.rend());
    if(!d_next.empty()) d.insert(d.end(), d_next.begin(), d_next.end());

    // MCM
    int matrix[MAX_N+1][MAX_N+1] = { {0, }, };
    int n = d.size();

    for (r=1; r<n-1; r++) {
      for (i=1; i<=n-r; i++) {
        j = i + r;
        matrix[i][j] = 999999;
        for (k=i; k<j; k++) {
          int cost = matrix[i][k] + matrix[k+1][j] + d[i-1]*d[k]*d[j];
          if (cost < matrix[i][j]) matrix[i][j] = cost;
        }
      }
    }

    cout << "#" << tc << " " << matrix[1][n-1] << endl;
    
    d.clear();
    d_prev.clear();
    d_next.clear();
    pos.clear();
  }

#ifndef __LOCAL__
  return 0;
#endif
}
