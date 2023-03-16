#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <stdio.h>
#include <cstring>
#include <cmath>

#define TEN_8 100000000

using namespace std;

bool is_zero(char *x) {
  return x[0] == '0' && x[1] == '\0';
}

int get_end(char *x) {
  int i;

  for (i=0; i<201; i++) {
    if (x[i] == '\0') return i;
  }

  return -1;
}


char compare(char *x, int x_end, char *y, int y_end) {
  int i;
  
  // compare by digits
  if (x_end > y_end) return '1';
  else if (x_end < y_end) return '2';

  // both have same length
  for (i=0; i<x_end; i++) {
    if (x[i] > y[i]) return '1';
    else if (x[i] < y[i]) return '2';
  }

  return '0';
}


void to_int_arr(char *x, int x_end, int *n) {
  int i;
  int j = -1;
  int k;

  for (i=0; i<x_end; i++) {
    if (i % 8 == 0) {
      j++;
      k = 0;
    }
    // cout << i << ", " << j << ", " << x_end-i-1 << ", " << k << endl;
    n[j] += (x[x_end-i-1] - '0') * pow(10, k++);
    // cout << n[j] << endl;
  }
}


void print_int_arr(int *n, int size) {
  int i;
  bool is_printed = false;

  for (i=size-1; i>=0; i--) {
    if (n[i] != 0) {
      if (!is_printed) {
        printf("%d", n[i]);
        is_printed = true;
      } else {
        printf("%08d", n[i]);
      }
    }
  }

  if (!is_printed) {
    printf("0");
  }

  printf("\n");
}


void add_int_arr(int *b, int *s, int *res) {
  int i = 0;
  int i_max;
  int q;

  while(i < 25) {
    if (s[i] == 0) break;
    res[i] = b[i] + s[i];
    i++;
  }

  while(i < 25) {
    if (b[i] == 0) break;
    res[i] = b[i];
    i++;
  }
  
  // set mark
  i_max = i;
  
  for (i=0; i<i_max; i++) {
    q = res[i] / TEN_8;
    res[i] -= q * TEN_8;
    res[i+1] += q;
  }

  // print
  if (res[i_max-1] != 0) {
    printf("%d", res[i_max-1]);
  }
  for (i=i_max-2; i>=0; i--) {
    printf("%08d", res[i]);
  }
  printf("\n");
}


void sub_int_arr(int *b, int *s, int *res) {
  int i = 0;
  int i_max;
  int q;
  
  for (i=0; i<25 && b[i]!=0; i++) {
    res[i] = b[i] - s[i];
  }
  
  // set mark
  i_max = i;
  
  // apply carrying
  for (i=0; i<i_max; i++) {
    if (res[i] < 0) {
      res[i] += TEN_8;
      res[i+1]--;
    }
  }

  // print
  if (res[i_max-1] != 0) {
    printf("%d", res[i_max-1]);
  }
  for (i=i_max-2; i>=0; i--) {
    printf("%08d", res[i]);
  }
  printf("\n");
}


#ifdef __LOCAL__
TEST(FuncTest, sub_8){
  GTEST_SKIP();
  char x[201] = "99999999";
  char y[201] = "12345678";

  int b[25] = {0, };
  int s[25] = {0, };
  int r[26] = {0, };

  to_int_arr(x, 8, b);
  to_int_arr(y, 8, s);
  
  sub_int_arr(b, s, r);

  EXPECT_EQ(r[0], (99999999-12345678)%TEN_8);
  EXPECT_EQ(r[1], (99999999-12345678)/TEN_8);
}

TEST(FuncTest, sub_4){
  GTEST_SKIP();
  char x[201] = "4321";
  char y[201] = "1111";

  int b[25] = {0, };
  int s[25] = {0, };
  int r[26] = {0, };

  to_int_arr(x, 4, b);
  to_int_arr(y, 4, s);
  
  sub_int_arr(b, s, r);

  EXPECT_EQ(r[0], 4321-1111);
}

TEST(FuncTest, add_8){
  GTEST_SKIP();
  char x[201] = "99999999";
  char y[201] = "12345678";

  int b[25] = {0, };
  int s[25] = {0, };
  int r[26] = {0, };

  to_int_arr(x, 8, b);
  to_int_arr(y, 8, s);
  
  add_int_arr(b, s, r);

  EXPECT_EQ(r[0], (99999999+12345678)%TEN_8);
  EXPECT_EQ(r[1], (99999999+12345678)/TEN_8);
}

TEST(FuncTest, add_4){
  GTEST_SKIP();
  char x[201] = "5678";
  char y[201] = "1234";

  int b[25] = {0, };
  int s[25] = {0, };
  int r[26] = {0, };

  to_int_arr(x, 4, b);
  to_int_arr(y, 4, s);
  
  add_int_arr(b, s, r);

  EXPECT_EQ(r[0], 5678+1234);
}

TEST(FuncTest, digit_12){
  GTEST_SKIP();
  char x[201] = "111122223333";
  int n[25] = {0, };

  to_int_arr(x, 12, n);
  EXPECT_EQ(n[0], 22223333);
  EXPECT_EQ(n[1], 1111);
}

TEST(FuncTest, digit_4){
  GTEST_SKIP();
  char x[201] = "1234";
  int n[25] = {0, };

  to_int_arr(x, 4, n);
  EXPECT_EQ(n[0], 1234);
}
#endif

#ifndef __LOCAL__
int main(int argc, char** argv) {
#endif

#ifdef __LOCAL__
TEST(MainTest, main){
  FILE *sfp;

  sfp = freopen("input/jgol_1374.txt", "r", stdin);
  /* 2335766636436335435435435434 
     2288942008190089189189189188 */

  // sfp = freopen("input/jgol_1374_1.txt", "r", stdin);
  /* 10
      8
      987
      987
      3217781114440687
      3215318638651559 */
  // sfp = freopen("input/jgol_1374_2.txt", "r", stdin);
  /* 11607478669166567626129502820202299568800771697431791489177105465462587806336596057565827067393103954371504426252192063134761301023094
     11607478669166567626129502820202299568800771697431791489177090773899324381134541777599810818333630912358403613810248666842490671345000 */

  // sfp = freopen("input/jgol_1374_3.txt", "r", stdin);
  /* 19999999999999999999999999999999999999999999999999999999999999999999
     1                                                                    */

  EXPECT_NE(sfp, nullptr);
#endif
 
  char *s1, *s2, *t;
  int end_1, end_2, t_end;
  int n1[25] = {0, }, n2[25] = {0, }, r[26] = {0, };
  int i, q;

  s1 = new char[201];
  s2 = new char[201];
  
  while (true) {
    // input
    // cin >> s1 >> s2;
    scanf("%s", s1);
    scanf("%s", s2);
    
    // terminate condition
    if (is_zero(s1) && is_zero(s2)) break;

    // get the end of index
    end_1 = get_end(s1);
    end_2 = get_end(s2);
    
    // compare length
    if (compare(s1, end_1, s2, end_2) == '2') {
      // swap
      t = s1;
      s1 = s2;
      s2 = t;

      t_end = end_1;
      end_1 = end_2;
      end_2 = t_end;
    }
    
    // init
    memset(n1, 0, 25*sizeof(int));
    memset(n2, 0, 25*sizeof(int));
    memset(r, 0, 26*sizeof(int));
    
    // string to int array
    to_int_arr(s1, end_1, n1);
    to_int_arr(s2, end_2, n2);
    
    end_1 /= 8;
    end_2 /= 8;

    // add operation
    for (i=0; i<=end_1; i++) {
      r[i] = n1[i] + n2[i];
    }
    
    // apply carrying
    for (i=0; i<end_1; i++) {
      q = r[i] / TEN_8;
      r[i] -= q * TEN_8;
      r[i+1] += q;
    }

    print_int_arr(r, 26);
    memset(r, 0, 26*sizeof(int));

    // sub operation
    for (i=0; i<=end_1; i++) {
      r[i] = n1[i] - n2[i];
    }
    
    // apply carrying
    for (i=0; i<=end_1; i++) {
      if (r[i] < 0) {
        r[i] += TEN_8;
        r[i+1]--;
      }
    }
    
    print_int_arr(r, 26);
  }

#ifndef __LOCAL__
  return 0;
#endif
}
