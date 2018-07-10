/*
https://soundhound2018-summer-qual.contest.atcoder.jp/tasks/soundhound2018_summer_qual_a
*/

#include <stdio.h>

int main() {
  int a,b;
  scanf("%d%d", &a, &b);

  if(a+b == 15) printf("+");
  else if(a*b == 15) printf("*");
  else printf("x");

  return 0;
}
