/*
https://abc056.contest.atcoder.jp/tasks/arc070_a
*/

#include <stdio.h>

int main() {
  long x;
  long temp = 0;
  long ans = 0;

  scanf("%ld", &x);

  for(long i = 0; ; i++){
    temp += i;
    if(temp >= x) {
      ans = i;
      break;
    }
  }

  printf("%ld", ans);
  return 0;
}
