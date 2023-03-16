#include "gtest/gtest.h"
#include <iostream>
#include <cstring>

#define MAX_N 50
#define MAX_M 100+1

using namespace std;

void set_last_1(char code[MAX_N][MAX_M], int n, int m,
                int *last_i, int *last_j){
  int i, j;
  int last_idx = -1;
  
  // find rightmost 1
  for(i=0; i<n; i++){
    for(j=m-1; j>=55; j--){
      if(code[i][j] == '1'){
        last_idx = j;
        break;
      }
    }

    if(last_idx != -1){
      break;
    }
  }

  *last_i = i;
  *last_j = j;
}

int decode_num(char code[MAX_M], int j){
  if(strncmp(&code[j], "0001101", 7) == 0) return 0;
  if(strncmp(&code[j], "0011001", 7) == 0) return 1;
  if(strncmp(&code[j], "0010011", 7) == 0) return 2;
  if(strncmp(&code[j], "0111101", 7) == 0) return 3;
  if(strncmp(&code[j], "0100011", 7) == 0) return 4;
  if(strncmp(&code[j], "0110001", 7) == 0) return 5;
  if(strncmp(&code[j], "0101111", 7) == 0) return 6;
  if(strncmp(&code[j], "0111011", 7) == 0) return 7;
  if(strncmp(&code[j], "0110111", 7) == 0) return 8;
  if(strncmp(&code[j], "0001011", 7) == 0) return 9;

  return -1;
}

int checksum(int pass[8]){
  int i;
  int sum = 0;
  
  for(i=0; i<8; i++){
    sum += (i & 1) == 0 ? pass[i] : 3*pass[i];
  }

  return sum;
}

int calc_sum(int pass[8]){
  int i;
  int sum = 0;
  
  for(i=0; i<8; i++){
    sum += pass[i];
  }

  return sum;
}

TEST(MainTestSuite, decodeNum){
  GTEST_SKIP();

  char one[8] = "0011001";
  char nine[8] = "0001011";
  EXPECT_EQ(decode_num(one, 0), 1);
  EXPECT_EQ(decode_num(nine, 0), 9);
}

TEST(MainTestSuite, mainTest){
  FILE *sfp;
  int test_case;
	int T;

  sfp = freopen("input/swea_1240.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
  
  // Starts from here
  cin >> T;
  
  int i, j, k;
  int N, M;
  char code[MAX_N][MAX_M];
  int sum;
  int last_i, last_j;
  int pass[8];
  
  for(test_case=1; test_case<=T; ++test_case){
    cin >> N >> M;

    for(i=0; i<N; i++){
      cin >> code[i];
    }

    sum = 0;
    
    // get last index of 1
    set_last_1(code, N, M, &last_i, &last_j);
    // cout << last_i << ", " << last_j << endl; 

    // decode passwords
    for(i=0; i<8; i++){
      pass[i] = decode_num(code[last_i], last_j-(7*(i+1))+1);
      // cout << pass[i] << ", ";
    }
    // cout << endl;

    // validity confirmation
    if(checksum(pass) % 10 == 0){
      sum = calc_sum(pass);
    }else{
      sum = 0;
    }

    cout << "#" << test_case << " " << sum << endl;
  }

}
