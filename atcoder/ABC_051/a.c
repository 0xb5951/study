/*
https://abc051.contest.atcoder.jp/tasks/abc051_a
*/

#include <stdio.h>

int main(){
  char s[20];

  scanf("%s", s);

  s[5] = ' ';
  s[13] = ' ';

  printf("%s", s);
  return 0;
}
