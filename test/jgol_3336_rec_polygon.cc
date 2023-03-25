#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct {
  int x;
  int y;
} pos_t;

typedef struct {
  int min;
  int max;
} line_t;

line_t *xs, *ys;
int xn = 0, yn = 0;
vector<int> v_max;

bool by_range(line_t a, line_t b) {
  return a.min < b.min || (a.min == b.min && a.max < b.max);
}

void add_line(pos_t prev_p, pos_t p) {
  if (prev_p.x == p.x) {
    if (prev_p.y < p.y) {
      xs[xn++] = {prev_p.y, p.y};
    } else {
      xs[xn++] = {p.y, prev_p.y};
    }
  } else {
    if (prev_p.x < p.x) {
      ys[yn++] = {prev_p.x, p.x};
    } else {
      ys[yn++] = {p.x, prev_p.x};
    }
  }
}

int max_meets(line_t *as, int an) {
  v_max.clear();
  int i = 0, max_v = as[an-1].max, max_cnt = 0;

  for(int v=as[0].min; v<max_v; v++) {
    while (i<an && as[i].min<=v)
      v_max.emplace_back(as[i++].max);

    for (auto it=v_max.begin(); it<v_max.end(); it++)
      if (*it <= v) v_max.erase(it--);

    if (max_cnt < v_max.size()) max_cnt = v_max.size();
  }

  return max_cnt;
}

#ifndef __LOCAL__
int main() {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;
  sfp = freopen("input/jgol_3336.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  xs = new line_t[N/2];
  ys = new line_t[N/2];

  pos_t first_p, prev_p, p;

  cin >> first_p.x >> first_p.y;
  prev_p = first_p;

  for (int i=1; i<N; i++) {
    cin >> p.x >> p.y;
    add_line(prev_p, p);
    prev_p = p;
  }
  
  p = first_p;
  add_line(prev_p, first_p);

  v_max.reserve(xn);

  sort(xs, &xs[xn], by_range);
  int max_x = max_meets(xs, xn);

  sort(ys, &ys[yn], by_range);
  int max_y = max_meets(ys, yn);

#ifdef __LOCAL__
  for (int i=0; i<xn; i++)
    cout << xs[i].min << ", " << xs[i].max << endl;
  cout << endl;
  for (int i=0; i<yn; i++)
    cout << ys[i].min << ", " << ys[i].max << endl;
#endif

  cout << ((max_x > max_y) ? max_x : max_y) << endl;

  delete[] xs;
  delete[] ys;

#ifndef __LOCAL__
  return 0;
#endif
}
