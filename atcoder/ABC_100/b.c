/*
https://abc100.contest.atcoder.jp/tasks/abc100_b
*/

#include <stdio.h>

int main(){
  long d,n;
  long ans = 0;

  scanf("%ld%ld", &d, &n);

  if(d == 0){
    ans = 1*n;
    if(n == 100) ans = 101;
  }
  if(d == 1){
    ans = 100*n;
    if(n == 100) ans = 10100;
  }
  if(d == 2){
    ans = 10000*n;
    if(n == 100) ans = 1010000;
  }

  printf("%ld", ans);
  return 0;
}
