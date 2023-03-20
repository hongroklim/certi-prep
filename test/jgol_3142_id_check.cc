#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>
#include <functional>
#include <map>

#define PARTITIONS 1000

using namespace std;

map<string, bool> id_logins[PARTITIONS];
int id_cnt = 0;
int login_cnt = 0;

int get_key(string id) {
  return (id.front()+id[4]+id.back()+id.size()) % PARTITIONS;
}

int validate(string id, int k) {
  return id_logins[k].find(id) != id_logins[k].end();
}

int activate(string id, int k) {
  map<string, bool>::iterator it = id_logins[k].find(id);
  return it != id_logins[k].end() && it->second;
}

int signup(string id, int k) {
  if (!validate(id, k)) {
    id_logins[k][id] = false;
    id_cnt++;
  }
  return id_cnt;
}

int close_id(string id, int k) {
  map<string, bool>::iterator it = id_logins[k].find(id);
  if (it != id_logins[k].end()) {
    if (it->second) login_cnt--;
    id_logins[k].erase(it);
    id_cnt--;
  }
  return id_cnt;
}

int login(string id, int k) {
  map<string, bool>::iterator it = id_logins[k].find(id);
  if (it != id_logins[k].end() && !it->second) {
    it->second = true;
    login_cnt++;
  }
  return login_cnt;
}

int logout(string id, int k) {
  map<string, bool>::iterator it = id_logins[k].find(id);
  if (it != id_logins[k].end() && it->second) {
    it->second = false;
    login_cnt--;
  }
  return login_cnt;
}

function<int (string, int)> exec[7] = {
  nullptr,
  &validate,
  &activate,
  &signup,
  &close_id,
  &login,
  &logout
};

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/jgol_3142.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif

  int N;
  cin >> N;

  for (int n=0; n<N; n++) {
    int cmd;
    char id[13];

    cin >> cmd >> id;
    cout << exec[cmd](string(id), get_key(id)) << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}
