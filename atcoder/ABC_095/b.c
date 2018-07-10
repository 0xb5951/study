/*
全てを一種類ずつ作ってから、必要グラム数が一番少ないものを限度いっぱいまで作る

引いていくんじゃなくて、足していく
*/

#include <stdio.h>

int main() {
  int N,X;
  int mg[101];
  int i,count = 0;
  int min_d, cal = 0;

  scanf("%d %d", &N, &X);

  for(i = 0; i < N; i++){
    scanf("%d", &mg[i]);
    // printf("%d\n", mg[i]);
  }

  min_d = mg[0];

  for(i = 1; i < N; i++){
    if(min_d > mg[i]){
      min_d = mg[i];
    }
  }

  for(i = 0; i < N; i++){
    cal += mg[i];
    count++;
  }

  while(1){
    cal += min_d;
    if(cal <= X){
      count++;
    } else {
      break;
    }
  }

  printf("%d\n", count);

  return 0;
}
