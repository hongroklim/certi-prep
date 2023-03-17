#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <iostream>

#define MAX_N 100

using namespace std;

char cs[MAX_N];
int n_left[MAX_N];
int n_right[MAX_N];
  
void print_inorder(int n) {
  if (n_left[n] != 0) print_inorder(n_left[n]);
  cout << cs[n];
  if (n_right[n] != 0) print_inorder(n_right[n]);
}

int parse_int(char *text, int *begin) {
  int i, res = 0;

  for (i=*begin; text[i]!=' '&&text[i]!='\0'; i++) {
    res *= 10;
    res += text[i] - '0';
  }

  *begin = i+1;

  return res;
}

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/swea_1231.txt", "r", stdin);
  EXPECT_NE(sfp, nullptr);
#endif
  
  int TC = 10;

  for (int tc=1; tc<=TC; tc++) {
    int N;
    cin >> N;
    cin.ignore();

    for (int i=1; i<=N; i++) {
      cs[i] = '\0';
      n_left[i] = 0;
      n_right[i] = 0;

      char line[11];
      cin.getline(line, 11);
      
      int begin = 0;
      int n = parse_int(line, &begin);
      cs[n] = line[begin];
      begin += 2;

      if (line[begin-1] == ' ') {
        n_left[n] = parse_int(line, &begin);
        if (line[begin-1] == ' ') {
          n_right[n] = parse_int(line, &begin);
        }
      }
    }

    cout << "#" << tc << " ";
    print_inorder(1);
    cout << endl;
  }

#ifndef __LOCAL__
  return 0;
#endif
}

