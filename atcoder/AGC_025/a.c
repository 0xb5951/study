/*
https://agc025.contest.atcoder.jp/tasks/agc025_a
*/

#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int ans = 0;
  if(n < 10){
    ans = n;
  } else {
    while(n!=0){
      ans += n % 10;
      n /= 10;
    }
  }

  if(ans == 1) ans = 10;
  
  printf("%d", ans);

  return 0;
}
