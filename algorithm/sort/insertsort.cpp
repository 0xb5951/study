/*単純挿入ソートのプログラム
計算量は　o(N^2) ソートは安定
ほとんど整列が終わっている配列に対しては効率がよく、他のソートと組み合わせて使われる
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 /*データの件数*/

int sort[N];

void InsertSort(void) {
  int i, sorted, temp, insert;

  /*最初から最後まで全てソート済みになるまで繰り返す*/
  for(sorted = 0; sorted < N - 1; sorted++){
    /*ソート済み領域の直後の値を取り出す*/
    insert = sort[sorted + 1];

    /*挿入する場所を見つける*/
    for(i = 0; i <= sorted; i++){
      if(sort[i] > insert) {
        break;
      }
    }
    while(i <= sorted + 1){
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
  InsertSort();

  printf("\nソート終了:\n");

  for(i = 0; i < N; i++){
    printf("%d ", sort[i]);
  }
  return 0;
}
