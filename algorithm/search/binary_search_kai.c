#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NOT_FOUND -1
#define N 1000

int binary_search(int x, int *a, int left, int right){
  int mid;


  while(left < right){
    mid = (left + right)/2;
    if(a[mid] < x){
      left = mid + 1;
    } else {
      right = mid;
    }

    if(a[left] == x){
      return left;
    }
  }


}


int main(void){
  int i,r,array[N];

  srand((unsigned int)time(NULL));

  /*適当にソートされた配列を作る*/
  printf("array");
  printf("[0]:%d ", array[0] = rand() % 3);
  for(i = 1; i < N; i++){
    printf("[%d:%d]", i, array[i] = array[i - 1] + rand() % 3);
  }

  printf("\n何をサーチしますか");
  scanf("%d", &i);

  r = binary_search(i, array, 0, N - 1);

  if(r == NOT_FOUND){
    printf("%dは見つかりませんでした", i);
  } else {
    printf("%dは%d番目でした", i, r);
  }

  return 0;
}