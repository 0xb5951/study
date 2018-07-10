/*
https://abc100.contest.atcoder.jp/tasks/abc100_a
*/

#include <stdio.h>

int main(){
  int a,b;

  scanf("%d%d", &a, &b);
  if(a > 8 || b > 8) printf(":(");
  else printf("Yay!");
  return 0;
}
