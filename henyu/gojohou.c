/*
https://arc051.contest.atcoder.jp/tasks/arc051_b
*/

/*ユークリッドの互除法
mod処理

の逆版。解がKになるようなa,bの組みを見つける.

*/

#include <stdio.h>

int main() {
  int k;
  scanf("%d", &k);

  int dp[45] = {};

  dp[0] = 1;
  dp[1] = 2;

  for(int i = 2; i < 45; i++){
    dp[i] = dp[i-1] + dp[i-2];
  }

  // for(int i = 0; i < 45; i++){
    printf("%d %d\n", dp[k], dp[k-1]);
  // }

}
