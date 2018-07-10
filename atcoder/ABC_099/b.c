/*
http://abc099.contest.atcoder.jp/tasks/abc099_b
*/

#include <stdio.h>

int main() {
  long a,b;
  long num[1010] = {};

  scanf("%ld%ld", &a, &b);

  long sub;
  sub = b - a;
  long ans = 0;

  for(int i = 1; i <= 1000; i++){
    num[i] = num[i-1] + i;
    if(sub == i) ans = num[i-1] - a;
  }

  printf("%d", ans);
  return 0;
}
