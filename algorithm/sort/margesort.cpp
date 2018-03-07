#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 /*データの件数*/

int sort[N];
int buffer[N];

void MargeSort(int n, int x[]){
  int i, j, k, m;
  if(n <= 1){ //要素数が一つなら
    return;
  }

// 中間地点を指定
  m = n/2;

  /*ブロックを前半と後半に分ける*/
  MargeSort(m,x); //後半部
  MargeSort(n-m,x+m); //前半部
  //ここで分割は終了

  /*マージ操作*/
  for(i=0; i < m;i++){ //分割した配列のbufferに保存する
    buffer[i] = x[i];
  }
  j = m; //中間値を保存
  i = k = 0;

  while(i < m && j < n) { //前半部は中間値より小さくて、後半部が終端より小さいとき
    if(buffer[i] <= x[j]) { //前半部より後半部の値が大きい時(正常なとき)
      x[k++] = buffer[i++]; //同じ値を代入
    } else{ //順番が違う時
      x[k++] = x[j++]; //順番を入れ替える
    }
  }
  while(i < m){ //中間値の方が大きいとき
    x[k++] = buffer[i++]; //
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
  MargeSort(N, sort);

  printf("\nソート終了:\n");

  for(i = 0; i < N; i++){
    printf("%d ", sort[i]);
  }
  return 0;
}
