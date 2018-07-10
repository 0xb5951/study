/*
https://abc053.contest.atcoder.jp/tasks/abc053_b
*/

// おかしいミスの原因は変数を初期化せず、使ってたから。
// 大きさを比較するときは必ず初期化を行う。

#include <stdio.h>
#include <string.h>

int main() {
  char s[200001] = {};
  int c_a,c_z;
  int flag = 0;

  scanf("%s", s);
  int len;
  len = strlen(s);

  for(int i = 0; i < len; i++){
      if(s[i] == 'A' && flag == 0){
       c_a = i;
       flag = 1;
     }
      if(s[i] == 'Z') c_z = i;

  }


  int ans;

  ans = c_z - c_a;
  ans += 1;
  printf("%d", ans);
  return 0;
}
