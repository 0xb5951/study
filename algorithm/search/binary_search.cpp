/*バイナリサーチのプログラム
これを行うにはまず対象をソートする必要はあるが、かなり優れたサーチ方法

配列の半値と対象を比べ、大小関係を明らかにする。それを繰り返してどんどんと領域を狭めていく
計算量はo(logN)*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 /*データの件数*/
#define NOT_FOUND -1

int binary_search(int i, int *data, int left , int right){
  int mid;

  while(left <= right){
    mid = (left + right) / 2;
    if(data[mid] == i){
      return mid;
    }
    if(i < data[mid]){
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return NOT_FOUND;
}

int main(void) {
  int i,r, array[N];

  srand((unsigned int)time(NULL));

  /*適当なソートされた配列を作る*/
  printf("array ");
  printf("[0]:%d",array[0] = rand() % 3);
  for(i = 1; i < N;i++){
    printf("[%d]:%d",i, array[i] = array[i - 1] + rand() % 3);
    /*配列の一つ前の要素に付け足していくから必ず増加する*/
  }

  printf("何を探しますか");
  scanf("%d", &i);

  r = binary_search(i, array, 0 , N-1);
  if(r == NOT_FOUND) {
    printf("%dは見つかりませんでした\n", i);
  } else {
    printf("%dは%d番目にあります\n", i, r);
  }
}
