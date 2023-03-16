#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <string>
#include <cstring>
#include <set>

using namespace std;

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/swea_1257.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  int tc, TC;
  int k, i, len, end;
  string text, substr;
  set<string, greater<string>> dict;
  
  cin >> TC;

  for(tc=1; tc<=TC; tc++){
    cin >> k >> text;
    for (i=0; i<text.size(); i++) {
      for(len=1; len<=text.size()-i; len++) {
        substr = text.substr(i, len);
        if (substr.compare(*dict.begin()) > 0
            && dict.size() == k)
          continue;

        dict.insert(substr);

        if (dict.size() > k)
          dict.erase(dict.begin());
      }
    }

    cout << "#" << tc << " " << *dict.begin() << endl;

    dict.clear();
  }

#ifndef __LOCAL__
  return 0;
#endif
}
