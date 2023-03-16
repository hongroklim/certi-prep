#include "gtest/gtest.h"
/* ************************************* */
/*                                       */
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// int main(int argc, char** argv) {
/*                                       */
/* ************************************* */

TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/swea_1219.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);

  /* ************************************* */
  /*                                       */
  
  int tc;
  int len;
  int i, j, k;
  int ans;

  int adj[100][2];
  vector<int> nodes;
  
  while (true) {
    // for each test case
    cin >> tc;
    if(cin.eof()) break;
    cin >> len;
    
    // initialize
    ans = 0;
    nodes.clear();
    memset(adj, 0, 200 * sizeof(int));
    
    // input
    for (i=0; i<len; i++) {
      cin >> j;

      if (adj[j][0] == 0) {
        cin >> adj[j][0];
      } else {
        cin >> adj[j][1];
      }
    }
    
    // search
    if (adj[0][0] != 0) nodes.push_back(adj[0][0]);
    if (adj[0][1] != 0) nodes.push_back(adj[0][1]);

    while(nodes.size() != 0) {
      i = nodes.back();
      nodes.pop_back();

      // cout << i << ", ";
      // if (nodes.size() > len) break;

      if (adj[i][0] == 99 || adj[i][1] == 99) {
        ans = 1;
        break;

      } else {
        if (adj[i][0] != 0) nodes.push_back(adj[i][0]);
        if (adj[i][1] != 0) nodes.push_back(adj[i][1]);
      }
    }

    cout << "#" << tc << " " << ans << endl;
  }
  
  // return 0;
// }
  /*                                       */
  /* ************************************* */
}
