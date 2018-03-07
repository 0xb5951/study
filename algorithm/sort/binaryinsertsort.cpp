/*２分挿入ソートのプログラム
計算量は　o(N^2) ソートは安定
単純挿入ソートと探索方法が違う。
バイナリサーチを使用している。
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 /*データの件数*/

int sort[N];

void BinaryInsertSort(void) {
  int i, sorted, temp, insert;
  int left,mid, right;

  for(sorted = 1; sorted < N; sorted++){
    insert = sort[sorted + 1]; //挿入対象（サーチ済み配列の１つ先）

    /*挿入する場所を見つける（バイナリサーチ）*/
    left = 0; //下端を配列の先頭に設定
    right = sorted; //上端をソート済み配列に設定
    while(left < right){ //下端より上端が大きいとき
      mid = (left + right)/2; //中間値を求める

      if(sort[mid] < insert) { //配列の中間より挿入対象のときが大きいとき
        left = mid + 1; //下端を中間値の次に設定
      } else{ //小さい場合
        right = mid; //上端を中間値に設定
      }
      i = left; //サーチ対象の値
    }
    while(i <= sorted + 1){ //挿入するとこ。配列なのである値を挿入したらそれ以後は全部ずれる
      temp = sort[i];
      sort[i] = insert;
      insert = temp;
      i++;
    }
  }
}

int main(void){
  int i;

  srand((unsigned int)time(NULL));

  printf("ソート準備:\n");
  /*ランダムな値を生成*/
  for(int i = 0; i < N; i++){
    sort[i] = rand();
    printf("%d ", sort[i]);
  }

  printf("\nソート開始:\n");
  BinaryInsertSort();

  printf("\nソート終了:\n");

  for(i = 0; i < N; i++){
    printf("%d ", sort[i]);
  }
  return 0;
}
