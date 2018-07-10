/*
https://abc056.contest.atcoder.jp/tasks/abc056_b
*/

#include <stdio.h>

int main() {
  int w,a,b;
  int table = 0;
  int min = 999999, max = 0;

  scanf("%d%d%d", &w, &a, &b);

  if(a <= b) {
    min = a;
    max = b;
  }
  if(a >= b){
    min = b;
    max = a;
  }

  table = (min+w);

  if(table < max){
    printf("%d", max-table);
  }
  else if(table >= max){
    printf("0");
  }

  return 0;
}
