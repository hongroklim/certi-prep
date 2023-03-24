#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <algorithm>
#include <cmath>

#define MAX_N 100

using namespace std;

typedef struct {
  int x;
  int y;
  double a;
} pos_t;

pos_t points[MAX_N+1];

bool compare_dist(pos_t p1, pos_t p2) {
  return (pow(points[0].x-p1.x, 2) + pow(points[0].y-p1.y, 2))
          < (pow(points[0].x-p2.x, 2) + pow(points[0].y-p2.y, 2));
}

bool compare_pos(pos_t p1, pos_t p2) {
  return p1.a < p2.a || (p1.a == p2.a && compare_dist(p1, p2));
}

double ccw(pos_t p1, pos_t p2, pos_t p3) {
  return (p1.x*p2.y + p2.x*p3.y + p3.x*p1.y)
        -(p1.y*p2.x + p2.y*p3.x + p3.y*p1.x);
}

#ifndef __LOCAL__
int main() {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  // sfp = freopen("input/jgol_1151.txt", "r", stdin); // 925
  sfp = freopen("input/jgol_1151_1.txt", "r", stdin); // 10000
  EXPECT_NE(sfp, nullptr);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  cin >> points[1].x >> points[1].y;
  int begin = 1;

  for (int n=2; n<=N; n++) {
    cin >> points[n].x >> points[n].y;
    
    if (points[n].x > points[begin].x) continue;
    else if (points[n].x < points[begin].x) begin = n;
    else if (points[n].y < points[begin].y) begin = n;
  }
  
  if (begin != 1) {
    points[0] = points[1];
    points[1] = points[begin];
    points[begin] = points[0];
  }

  for (int n=2; n<=N; n++)
    points[n].a = (points[n].y-points[1].y)/(double)(points[n].x-points[1].x);
  sort(&points[2], &points[N+1], compare_pos);
 
#ifdef __LOCAL__
  for (int n=1; n<=N; n++)
    cout << "(" << points[n].x << ", " << points[n].y << ") ";
  cout << endl;
#endif
  
  pos_t s[MAX_N];
  int top = -1;

  s[++top] = points[1];
  s[++top] = points[2];
  s[++top] = points[3];

  for (int n=4; n<=N; n++) {
    while (ccw(s[top-1], s[top], points[n]) <= 0) --top;
    s[++top] = points[n];
  }

#ifdef __LOCAL__
  for (int n=0; n<=top; n++)
    cout << "(" << s[n].x << ", " << s[n].y << ") ";
  cout << endl;
#endif

  int ans = (s[top].x*s[0].y)-(s[top].y*s[0].x);
  for (int n=1; n<=top; n++)
    ans += (s[n-1].x*s[n].y)-(s[n-1].y*s[n].x);
  
  cout << abs(ans)/2;
  if (ans & 1) cout << ".5";
  cout << endl;

#ifndef __LOCAL__
  return 0;
#endif
}
