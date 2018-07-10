/*
https://abc055.contest.atcoder.jp/tasks/abc055_a
*/

#include <stdio.h>

int main(){
  int n;
  int x,y;
  int ans = 0;

  scanf("%d", &n);

  x = n*800;
  y = (n/15)*200;
  ans = x-y;
  printf("%d", ans);
  return 0;
}
