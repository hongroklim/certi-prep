#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <cmath>
#include <algorithm>

#define MAX_N 1000
#define MAX_Q 100

using namespace std;

typedef struct {
  int x;
  int y;
  float a;
} pos_t;

pos_t p0;

bool by_dist(pos_t p1, pos_t p2) {
  return (pow(p0.x-p1.x, 2) + pow(p0.y-p1.y, 2))
        < (pow(p0.x-p2.x, 2) + pow(p0.y-p2.y, 2));
}

bool by_angle(pos_t p1, pos_t p2) {
  return p1.a < p2.a || (p1.a == p2.a && by_dist(p1, p2));
}

bool by_xy(pos_t p1, pos_t p2) {
  return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

float ccw(pos_t p1, pos_t p2, pos_t p3) {
  return (p1.x*p2.y + p2.x*p3.y + p3.x*p1.y)
        -(p1.y*p2.x + p2.y*p3.x + p3.y*p1.x);
}

#ifndef __LOCAL__
int main() {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/quiz_0202.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int TC, N, Q, i, j;
  pos_t points[MAX_N], adds[MAX_Q];
  vector<pos_t> border;

  cin >> TC;

  for (int tc=1; tc<=TC; tc++) {
    cin >> N;
    
    int begin = 0;

    for (i=0; i<N; i++) {
      cin >> points[i].x >> points[i].y;
      if (by_xy(points[i], points[begin])) {
        begin = i;
      }
    }

    if (begin > 0) {
      pos_t temp = points[0];
      points[0] = points[begin];
      points[begin] = temp;
    }
    p0 = points[0];
    
    cin >> Q;

    for (i=0; i<Q; i++)
      cin >> adds[i].x >> adds[i].y;

    // calculate angle
    for (i=1; i<N; i++)
      points[i].a = (points[i].y-p0.y)/(float)(points[i].x-p0.x);
    sort(&points[1], &points[N-1], by_angle);
    
    for (i=0; i<Q; i++)
      adds[i].a = (adds[i].y-p0.y)/(float)(adds[i].x-p0.x);
    sort(&adds[0], &adds[Q-1], by_angle);

    // graham
    pos_t s[MAX_N];
    int top = -1;
    s[++top] = points[0];
    s[++top] = points[1];
    s[++top] = points[2];

    for (i=3; i<N; i++) {
      while (ccw(s[top-1], s[top], points[i]) <= 0) --top;
      s[++top] = points[i];
    }
    
    s[++top] = s[0];
    int cnt = 0;
    j = 1;
    
    for (i=0; i<Q; i++) {
      while (j<top && by_angle(s[j], adds[i])) j++;
      if (ccw(s[j-1], adds[i], s[j]) > 0) {
        cnt++;
      }
    }

    cout << "#" << tc << " " << cnt << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}
