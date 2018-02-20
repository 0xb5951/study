/*リニアーソートのプログラム。
配列の最初から見ていって、対象が見つかるまで探す*/
/*少し高速化してある。配列の中に目的の値が見つからない場合のために配列の最後の値を目的の値にする
こうすることでオーバフローによるクラッシュの防止と光速かを*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NOT_FOUND -1
#define N 10 /*データの件数*/

int linear_search(int i, int *data, int n) { /*　探索対象　探索する配列　配列の最大値*/
  int x = 0,t; /*探索サーチ用*/

/*配列の最後を目的の値にする(番兵)*/
  t = data[n - 1]; /*最後の値を保存*/
  data[n - 1] = i; /*配列の最後に代入*/

  /*見つかるまでソート(最後で絶対に見つかる)*/
  while(data[x] != i){
    x++;
  }
  data[n - 1] = t; /*配列の最後値を基に戻す*/

  if(i == t){ /*目的の値と配列の一番最後が一致*/
    return x;
  }
  if(x < n){
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
