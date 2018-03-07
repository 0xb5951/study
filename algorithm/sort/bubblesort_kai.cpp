// バブルソート改のプログラム　
// ランダムで数字を生成し、それを小さい順で並べる
// ソートを一回行うと配列の後方要素は確実にソート済みになっていることを利用する
// 小さいのがどんどん前にくるので、大きいのは後ろに行く

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 /*データの件数*/

int sort[N];

//バブルソート関数
void BubbleSort(void) {
  int i,j,flag,k;

  k=0;
  do{
    flag = 0;
    for(i = 0; i < N-1-k; i++){
      /*配列の先頭から見ていく*/
      if(sort[i] > sort[i+1]){ //もし順番が違うと
        j = sort[i]; /*i番目の中身を一回逃がす*/
        sort[i+1] = j;  /*順番を入れ替える*/
        sort[i] = sort[i+1]; /*順番を入れ替える*/
      }
    }
    k++;
  } while(flag == 1);
}

int main(void){
  int i;

  /*乱数生成用*/
  srand((unsigned int)time(NULL));

  printf("ソート準備:\n");
  for(i = 0; i < N; i++){
    /*配列にランダムな値を格納*/
    sort[i] = rand();
    printf("%d ",sort[i]);
  }

  printf("\nソート開始:\n");
  BubbleSort();

  printf("ソート終了\n");

  for(i = 0; i < N;i++){
    printf("%d ",sort[i]);
  }

  return EXIT_SUCCESS;
}
