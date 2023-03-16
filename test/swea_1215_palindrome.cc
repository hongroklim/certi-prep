#include "gtest/gtest.h"
#include <iostream>

using namespace std;

TEST(MainTestSuite, mainTest){
  FILE *sfp;
  int test_case;
	int T;

  sfp = freopen("input/swea_1215.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
  
  // Starts from here.
  T = 10;

  int BOARD_SIZE = 8;
  int length;
  char board[BOARD_SIZE][BOARD_SIZE+1];
  int i, j, k;
  int count;

  char c_stack[BOARD_SIZE];
  int c_stack_len = 0;

  for(test_case = 1; test_case <= T; ++test_case)
	{
    cin >> length;

    for(i=0; i<BOARD_SIZE; i++){
      cin >> board[i];
    }

    count = 0;

    for(i=0; i<BOARD_SIZE; i++){
      for(j=0; j<BOARD_SIZE; j++){
        // to right
        if(i <= (BOARD_SIZE-length+1)){
          for(k=0; k<=(length/2-1); k++){
            c_stack[k] = board[i+k][j];
          }
          
          // if length is odd, skip the center
          for(k=(length/2-1); k>=0; k--){
            if(c_stack[k] != board[i+length-1-k][j]){
              break;
            }
          }

          if(k < 0){
            count++;
          }
        }

        // to down
        if(j <= (BOARD_SIZE-length+1)){
          for(k=0; k<=(length/2-1); k++){
            c_stack[k] = board[i][j+k];
          }
          
          // if length is odd, skip the center
          for(k=(length/2-1); k>=0; k--){
            if(c_stack[k] != board[i][j+length-1-k]){
              break;
            }
          }

          if(k < 0){
            count++;
          }
        }
      }
    }

    cout << "#" << test_case << " " << count << endl;
  }
};
