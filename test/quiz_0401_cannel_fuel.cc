#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>

#define MAX_N 300000
#define MAX_W 100000000

using namespace std;

typedef struct {
  long long w;
  long long par_w;
  bool visited;
  int children[3];
} node_t;

node_t nodes[MAX_N+1];

int calc_w(int n, int level) {
  int c;
  long long w = nodes[n].w * level;
  for (int i=0; (c=nodes[n].children[i]); i++)
    w += calc_w(c, level+1);
  return w;
}

void add_child(int src, int n) {
  int i = 0;
  while (nodes[src].children[i]) i++;
  nodes[src].children[i] = n;
}

void remove_child(int src, int n) {
  for (int i=0; nodes[src].children[i]; i++) {
    if (n == nodes[src].children[i]) {
      for (int j=i+1; j<3; j++)
        nodes[src].children[j-1] = nodes[src].children[j];
      nodes[src].children[2] = 0;
      break;
    }
  }
}

void remove_recursion(int parent) {
  int c;
  for (int i=0; (c=nodes[parent].children[i]); i++) {
    remove_child(c, parent);
    remove_recursion(c);
  }
}

long long get_par_w(int n) {
  if (nodes[n].par_w == 0) {
    nodes[n].par_w = nodes[n].w;
    int c;
    for (int i=0; (c=nodes[n].children[i]); i++)
      nodes[n].par_w += get_par_w(c);
  }
  return nodes[n].par_w;
}

#ifndef __LOCAL__
int main() {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/quiz_0401.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int TC, i, j, c;
  cin >> TC;

  for (int tc=1; tc<=TC; tc++) {
    int N;
    cin >> N;
    
    for (i=1; i<=N; i++) {
      nodes[i].par_w = 0LL;
      nodes[i].visited = false;
      for (j=0; j<3; j++)
        nodes[i].children[j] = 0;
    }

    for (i=1; i<N; i++) {
      int n1, n2;
      cin >> n1 >> n2;
      add_child(n1, n2);
      add_child(n2, n1);
    }

    for (i=1; i<=N; i++) {
      long long w;
      cin >> w;
      nodes[i].w = w;
    }
    
    int root_node = 1;

    remove_recursion(root_node);

    long long sum_w = get_par_w(root_node);
    
    nodes[root_node].visited = true;

    while (true) {
      int next_root = 0;
      long long max_par_w = 0;
      for (i=0; (c=nodes[root_node].children[i]); i++) {
        if (!nodes[c].visited && max_par_w < nodes[c].par_w) {
          next_root = c;
          max_par_w = nodes[c].par_w;
        }
      }
      
      // -(max_par_w) + (sum_w - max_par_w) > 0
      if (sum_w > 2*max_par_w) break;
      nodes[next_root].visited = true;
      
      // update par_w
      nodes[root_node].par_w -= nodes[next_root].par_w;
      nodes[next_root].par_w = sum_w;
      
      // update children
      remove_child(root_node, next_root);
      add_child(next_root, root_node);
      
      // update root_node
      root_node = next_root;
    }

    cout << "#" << tc << " " << calc_w(root_node, 0) << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}
