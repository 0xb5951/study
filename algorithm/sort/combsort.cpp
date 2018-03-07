/*コームソートのプログラム
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 /*データの件数*/

int sort[N];

void CombSort(void){
  int i, temp, flag,gap;
  gap = N;

  do{
    // gapを小さくする（1/1.3）
    gap = (gap * 10) /13;
    if(gap == 0) {
      gap = 1;
    }

    flag = 1;
    for(i = 0; i < N -　gap; i++){
      /*距離がgapだけ離れた要素を比較し、並びがおかしければ*/
      if(sort[i] > sort[i + gap]){
        temp = sort[i];
        sort[i] = sort[i + gap];
        sort[i + gap] = temp;
      }
    }
  } while((gap > 1) || flag != 1);
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
  CombSort();

  printf("\nソート終了:\n");

  for(i = 0; i < N; i++){
    printf("%d ", sort[i]);
  }
  return 0;
}
