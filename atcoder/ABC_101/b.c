/*
https://abc101.contest.atcoder.jp/tasks/abc101_b
*/

#include <stdio.h>

int main() {
  long n,t;
  long sum = 0;

  scanf("%ld", &n);
  t = n;

  while(1){
    sum += t % 10;
    t /= 10;
    // printf("%ld%ld\n", n, sum);
    if(t <= 0) break;
  }

  if(n % sum == 0){
    printf("Yes");
  } else {
    printf("No");

  }

  return 0;

}
