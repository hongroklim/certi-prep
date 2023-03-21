#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, bool> id_login;
int id_cnt = 0;
int login_cnt = 0;

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/jgol_3142.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  id_login.reserve(100000);

  int N;
  cin >> N;

  for (int n=0; n<N; n++) {
    int cmd;
    string id;

    cin >> cmd >> id;

    unordered_map<string, bool>::iterator it = id_login.find(id);
    
    switch(cmd) {
      case 1:
        cout << (it != id_login.end()) << endl;
        break;
      case 2:
        cout << (it != id_login.end() && it->second) << endl;
        break;
      case 3:
        if (it == id_login.end()) {
          id_login[id] = false;
          id_cnt++;
        }
        cout << id_cnt << endl;
        break;
      case 4:
        if (it != id_login.end()) {
          if (it->second) login_cnt--;
          id_login.erase(it);
          id_cnt--;
        }
        cout << id_cnt << endl;
        break;
      case 5:
        if (it != id_login.end() && !it->second) {
          it->second = true;
          login_cnt++;
        }
        cout << login_cnt << endl;
        break;
      case 6:
        if (it != id_login.end() && it->second) {
          it->second = false;
          login_cnt--;
        }
        cout << login_cnt << endl;
        break;
      default:
        break;
    }
  }

#ifndef __LOCAL__
  return 0;
#endif
}
