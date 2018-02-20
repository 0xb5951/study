/*リニアーソートのプログラム。
配列の最初から見ていって、対象が見つかるまで探す*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NOT_FOUND -1
#define N 10 /*データの件数*/

int linear_search(int i, int *data, int n) { /*　探索対象　探索する配列　配列の最大値*/
  int x = 0; /*探索サーチ用*/

  while( x < n && i != data[x]){
    x++;
  }
  if( x < n){
    return x;
  }

  return NOT_FOUND;

}

int main(void) {
  int i,r,array[N];

  srand((unsigned int)time(NULL));

  /*適当な配列を作る*/
  printf("array ");
  for(i = 0; i < N; i++){
    printf("[%d]:%d ", i, array[i] = rand() % 20);
  }

  printf("\n何を探しますか");
  scanf("%d", &i);

  r = linear_search(i, array, N);

  if(r == NOT_FOUND){
    printf("%dは見つかりません\n", i);
  } else {
    printf("%dは%d番目です", i, r);
  }

  return 0;
}
