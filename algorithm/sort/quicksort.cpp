#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 /*データ件数*/

// データ配列格納用。グローバル関数。
int sort[N];

void QuickSort(int bottom,int top,int *data){
  // 変数定義.順番に配列を下から見ていく変数,上から見ていく変数,先頭の値を格納する,順番入れ替え用
  int lower, upper, point, temp;

  /*終了を判断する*/
  if(bottom >= top){
    return;
  }

  /*先頭の値を基準とする*/
  point = data[bottom];

  /*ソート部分*/
  for(lower = bottom, upper = top; lower < upper;){
    while(lower <= upper && data[lower] < point){ /*（部分）配列の中で基準より大きい要素を探す*/
      lower++;
    }
    while(lower <= upper && data[upper] > point){ /*(部分)配列の中で基準より小さい要素を探す*/
      upper--;
    }
    if(lower < upper){ /*要素を交換する*/
      temp = data[lower];
      data[lower] = data[upper];
      data[upper] = temp;
    }
  }

  /*最初に選択した値を中央に移動する*/
  temp = data[bottom];
  data[bottom] = data[upper];
  data[upper] = temp;

  QuickSort(bottom, upper - 1, data); /*分割した右を再帰的にソート*/
  QuickSort(upper + 1, top, data); /*分割した左を再帰的にソート*/
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
  QuickSort(0, N - 1, sort);

  printf("\nソート終了:\n");

  for(i = 0; i < N; i++){
    printf("%d ", sort[i]);
  }
  return 0;
}
