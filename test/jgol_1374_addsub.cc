#define __LOCAL__

#ifdef __LOCAL__
#include "gtest/gtest.h"
#endif

#include <stdio.h>
#include <cstring>
#include <cmath>

#define TEN_8 100000000

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
    n[j] += (x[x_end-i-1] - '0') * pow(10, k++);
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
    memset(r,  0, 26*sizeof(int));
    
    // string to int array
    to_int_arr(s1, end_1, n1);
    to_int_arr(s2, end_2, n2);
    
    // last index of int array
    end_1 /= 8;

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
