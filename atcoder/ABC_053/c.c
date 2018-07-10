/*
https://abc053.contest.atcoder.jp/tasks/arc068_a
*/

// 桁が足りてない場合だった。
// 代入する場合、すべての変数の桁をそろえておこう。

#include <stdio.h>

int main() {
  long long x;
  scanf("%lld" , &x);

  long long num = 0;
  long long count = 0;
  long long i;

  count += 2*(x / 11);
  if((x%11) != 0){
    if((x%11 > 6)) count += 2;
    else if((x%11 <= 6)) count += 1;

  }

  // count++;
  // count = 40 /11;
  printf("%lld", count);
  return 0;
}
