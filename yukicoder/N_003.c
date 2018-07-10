/*
https://yukicoder.me/problems/11
*/

#include <stdio.h>

int main(){
  int n;
  int count = 1;
  int move[10001] = {};
  int flag[10001] = {};
  int i,j;

  scanf("%d", &n);

  for(i = 0; i < n; i++){ //bitですべてのパターンを列挙
    int digit_num = 0;
    for(j = 0; j < i; j++){
      if(i >> j & 1){ //その桁にフラグが立っていたら。
        digit_num++;
      }
    }
    move[i] = digit_num;
  }

  flag[1] = 1;
  int next = 0, temp = 1;

  while(1){
    next = move[temp];


    if(flag[temp] == 1){
      printf("-1");
      break;
    }
    if(temp == n){
      printf("%d", count);
      break;
    }
    if(temp+next > n){
      temp += move[next]; 

    }
  }
    flag[temp] = 1;

  return 0;
}
