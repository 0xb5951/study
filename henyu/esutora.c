/*
エラトステネスの篩のプログラム。
指定した範囲内の素数を出力する。

1.範囲内の数をすべて１で初期化する
2.2から素数を求めていく
方法は調べたい数の２乗以上の数のフラグを0にする。
3.これをインクリメントする
4.調べる数の2乗が範囲を超えたら、終了
*/

#include <stdio.h>
#include <stdlib.h>

int count = 0;

unsigned int check_flag(unsigned int *flag, unsigned int p){
  return flag[p];
}

void reset_flag(unsigned int *flag, unsigned int p) {
  flag[p] = 0;
}

void prime1(unsigned int max){
  unsigned int p, i;
  unsigned int *flag = malloc(sizeof(unsigned int) * (max + 1));

  // フラッグの初期化
  for(p = 2; p <= max; p++) flag[p] = 1;

  // ふるい部分
  for(p = 2; p*p <= max; p++){
    if(check_flag(flag, p) != 0){
      count++;
      for(i = p*p; i <= max; i += p) reset_flag(flag, i);
    }
  }

  // max以下の素数を出力する
  for(p = 2; p <= max; p++)
  if(check_flag(flag, p) != 0){
    count++;
    printf("%d ", p);
  }
  printf("\n");
}


int main() {
  unsigned int i;

  printf("素数を求めたい範囲を入力してください\n");
  scanf("%d", &i);

  prime1(i);
  printf("%d", count);

  return 0;
}
