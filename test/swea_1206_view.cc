#define __LOCAL__

#ifdef __LOCAL__
#include <gtest/gtest.h>
#endif

#include <iostream>

using namespace std;

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/swea_1206.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  int tc, TC = 10;
  int i;
  int buildings;
  int *heights;
  int i_height;
  int max_height;
  int ans;
  
  heights = new int[1000];

  for(tc = 1; tc <= TC; tc++){
    // input
    cin >> buildings;

    for(i=0; i<buildings; i++){
      cin >> heights[i];
    }
    
    // calculation
    for(i=2; i<heights[i]-2; i++){
      i_height = heights[i];

      // get max height
      max_height = heights[i-2];
      max_height = max_height >= heights[i-1] ? max_height : heights[i-1];
      max_height = max_height >= heights[i+1] ? max_height : heights[i+1];
      max_height = max_height >= heights[i+2] ? max_height : heights[i+2];
      
      if(i_height >= max_height){
        // add nums
        ans += (i_height - max_height);

        // skip neighbor buildings
        i += 2;
      }
    }

    cout << "#" << tc << " " << ans << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}
