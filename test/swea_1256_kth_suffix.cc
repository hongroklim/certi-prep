#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <string>
#include <list>
#include <cstring>

using namespace std;

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/swea_1256.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  int tc, TC;
  int k, i;
  string text, suffix;
  list<string> dict;
  list<string>::iterator it;
  
  cin >> TC;

  for(tc=1; tc<=TC; tc++){
    // init
    text.clear();
    dict.clear();

    // input
    cin >> k >> text;
    
    // early return
    if (k > text.size()) {
      cout << "#" << tc << " none" << endl;
      continue;
    }

    // fill dict with k elements and sort
    for (i=text.size()-1; i>=text.size()-k; i--)
      dict.push_back(text.substr(i));
    dict.sort();
    
    // scan remaining
    for (;i>=0; i--) {
      suffix = text.substr(i);

      // spilled suffix
      if (suffix.compare(dict.back()) > 0) continue;

      // search remainings
      for (it=dict.begin(); it!=dict.end(); it++) {
        if (suffix.compare(*it) < 0) {
          dict.insert(it, suffix);
          break;
        }
      }
      
      // remove spilled element
      dict.pop_back();
    }

    // output
    cout << "#" << tc << " " << dict.back() << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}
