/*
https://abc052.contest.atcoder.jp/tasks/abc052_b
*/

// Iなら+, Dなら--.　この時、カウントの最大値を返せ。

#include <stdio.h>

int main(){
  int n;
  char s[101] = {};
  int count = 0;
  int max = 0;

  scanf("%d", &n);
  scanf("%s", s);

  for(int i = 0; i < n; i++){
    if(s[i] == 'I') count++;
    if(s[i] == 'D') count--;
    if(count > max) max = count;
  }

  printf("%d", max);
  return 0;
}
