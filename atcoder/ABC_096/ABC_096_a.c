/*
AtCoder 王国では, 5 月 5 日のような月の数と日の数が同じ日を「高橋」と言う.
2018 年 1 月 1 日から 2018 年 a 月 b 日までに, 「高橋」は何日あるか.
ただし, AtCoder 王国ではグレゴリオ暦を利用しているものとする.
*/

#include <stdio.h>

int main(){
  int a,b;
  int i,j;
  int count = 0;

  scanf("%d %d", &a, &b);

  if(a == b) count = a;

  if(a < b) count = a;

  if(a > b) count = a - 1;

  printf("%d", count);

  return 0;
}
