#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>

using namespace std;

char scan_winner(char board[19+2][19+2], int i, int j, int i_sign, int j_sign) {
  int k = 1;

  while(board[i][j] == board[i + i_sign*k][j + j_sign*k]){
    k++;
  }
  
  // exclude six pieces (in backward)
  if (k == 5 && board[i][j] != board[i - i_sign][j - j_sign]) {
    return board[i][j];
  } else {
    return '0';
  }
}


#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/jgol_1733.txt", "r", stdin); // 1 (3, 2)
  //sfp = freopen("input/jgol_1733_1.txt", "r", stdin); // 2 (8, 12)
  //sfp = freopen("input/jgol_1733_2.txt", "r", stdin); // 0
  EXPECT_NE(sfp, nullptr);
#endif
  
  int i, j, h;
  char win_flag = '0';
  
  // delta (i_sign, j_sign)
  int d[4][3] = { {-1, 1}, {0, 1}, {1, 1}, {1, 0} };
  
  // including buffer area
  char board[19+2][19+2];
  
  // input
  for (i=1; i<=19; i++) {
    for (j=1; j<=19; j++) {
      cin >> board[i][j];
    }
  }
  
  // traverse
  for (i=1; i<=19; i++) {
    for (j=1; j<=19; j++) {
      if (board[i][j] == '0') continue;
      
      for (h=0; h<4; h++) {
        // scan winner
        win_flag = scan_winner(board, i, j, d[h][0], d[h][1]);
        
        if (win_flag != '0') {
          // when winner is found
          cout << win_flag << "\n" << i << " " << j << endl;

#ifdef __LOCAL__
          GTEST_SKIP();
#else
          return 0;
#endif
        }
      }
    }
  }

  // no winner
  cout << '0' << endl;

#ifndef __LOCAL__
  return 0;
#endif

}
