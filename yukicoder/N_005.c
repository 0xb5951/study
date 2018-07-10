/*
https://yukicoder.me/problems/14
星１
*/

#include <stdio.h>

void Insertsort(int n, int *block){
  int i, sorted, temp, insert;

  for(sorted = 0; sorted < n - 1; sorted++){
    insert = block[sorted+1];

    /*挿入する場所を見つける*/
    for(i = 0; i <= sorted; i++){
      if(block[i] > insert) break;
    }

    /*ソート済み領域直後の値を変更する。*/
    while(i <= sorted + 1){
      temp = block[i];
      block[i] = insert;
      insert = temp;
      i++;
    }
  }
}


int main(){
  int l,n;
  int i;
  int block[10001] = {};
  int cal = 0, count = 0;

  scanf("%d%d", &l, &n);

  for(i = 0; i < n; i++){
    scanf("%d", &block[i]);
  }

  Insertsort(n, block);
  //
  // for(i = 0; i < n; i++){
  //   printf("%d ", block[i]);
  // }

  for(i = 0; ; i++){
    cal += block[i];
    count++;
    if(cal > l){
      count--;
      break;
    } else if(cal == l){
      break;
    } else if(count >= n) break;
  }

  printf("%d", count);
  return 0;
}
