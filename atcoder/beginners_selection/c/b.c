/*
シカのAtCoDeerくんは二つの正整数 a,b を見つけました。 a と b の積が偶数か奇数か判定してください。

入力は以下の形式で標準入力から与えられる。

a b

積が奇数なら Odd と、 偶数なら Even と出力せよ。
*/

#include <stdio.h>

int main() {
  int a,b;
  int out;

  scanf("%d %d\n", &a, &b);

  out = a*b;
  if(out % 2 == 1){
    printf("Odd\n");
  } else {
    printf("Even\n");
  }

  return 0;
}
