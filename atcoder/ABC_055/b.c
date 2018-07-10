/*
https://abc055.contest.atcoder.jp/tasks/abc055_b
*/

/*
このままだと、桁あふれを起こしてしまうので、対策が必要。
配列を桁に見立てて対応する。
*/

#include <stdio.h>

int main(){
  long n;
  long ans[100] = {};
  long temp[100] = {};

  scanf("%ld", &n);
  temp[0] = 1;

  long ans[100] = {};
  for(long i = 2; i <= n; i++){
    for(long j = 0; j <= 100; j++){
      if(temp[j] != 0) temp[j] *= i; //その桁が0じゃなければ計算
    }

    for(long j = 0; j <= 100; j++){//桁あふれを調整する。
      if(temp[j] >= 10){
        
      }
    }

  }

  if(ans > 100000007)   ans %= 100000007;
  printf("%ld", ans);
  return 0;
}
