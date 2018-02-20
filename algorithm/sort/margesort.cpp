#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 /*データの件数*/

int sort[N];
int buffer[N];

void MargeSort(int n, int x[]){
  int i, j, k, m;
  if(n <= 1){
    return;
  }

// 中間地点を指定
  m = n/2;

  /*ブロックを前半と後半に分ける*/
  MargeSort(m,x);
  MargeSort(n-m,x+m);

  /*マージ操作*/
  for(i=0; i < m;i++){
    buffer[i] = x[i];
  }
  j = m;
  i = k = 0;

  while(i < m && j < n) {
    if(buffer[i] <= x[j]) {
      x[k++] = buffer[i++];
    } else{
      x[k++] = x[i++];
    }
  }
  while(i < m){
    x[k++] = buffer[i++];
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
