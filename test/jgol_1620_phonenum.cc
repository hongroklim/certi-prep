#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/jgol_1620.txt", "r", stdin); // 7654
  // sfp = freopen("input/jgol_1620_1.txt", "r", stdin); // INPUT ERROR!
  // sfp = freopen("input/jgol_1620_2.txt", "r", stdin); // 3333
  EXPECT_NE(sfp, nullptr);
#endif
  
  string phonenum, block;
  vector<string> blocks;
  int i, j, add_k, nth_block;
  
  // input
  cin >> phonenum >> add_k >> nth_block;

  // parse phonenum
  i = 0;
  while (i <= phonenum.size()) {
    j = phonenum.find('-', i);
    if (j == string::npos) j = phonenum.size();
    
    block = phonenum.substr(i, j-i);
    if (block.size() > 4) {
      cout << "INPUT ERROR!" << endl;
#ifndef __LOCAL__
      return 0;
#endif
    }
    
    blocks.push_back(block);

    i = j+1;
  }
  
  if (nth_block > blocks.size()) {
    cout << "INPUT ERROR!" << endl;
#ifndef __LOCAL__
    return 0;
#endif
  }
  
  block = blocks[nth_block-1];
  while (block.size() < 4) block.insert(0, "0");
  for (i=0; i<4; i++) {
    cout << (block.at(i) - '0' + add_k) % 10;
  }
  cout << endl;

#ifndef __LOCAL__
  return 0;
#endif
}

