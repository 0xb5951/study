/*
https://abc050.contest.atcoder.jp/tasks/abc050_a
*/

#include <stdio.h>

int main(){
  long a,b;
  char op;
  long ans;

  scanf("%d %c %d", &a, &op, &b);

  if(op == '+') ans = a+b;
  if(op == '-') ans = a-b;

  printf("%d", ans);

  return 0;

}
