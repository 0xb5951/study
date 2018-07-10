/*
https://abc101.contest.atcoder.jp/tasks/abc101_a
*/

#include <stdio.h>

int main() {
  char s[5] = {};
  int ans = 0;

  scanf("%s", s);

  for(int i = 0; i < 4; i++){
    if(s[i] == '+') ans++;
    else if(s[i] == '-') ans--;
  }

  printf("%d", ans);
}
