/*バイナリサーチのプログラム
対象が中間値より大きいか小さいかで判断し、
どんどん分割していって、見つかるまで行う。
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NOT_FOUND -1
#define N 1000

int binary_search(int x, int *a, int left, int right){ //左からサーチ対象、目的配列、下端、上端
  int mid;

  while(left < right){ //下端より上端の方が大きいとき
    mid = (left + right)/2; //中間値を求める
    if(a[mid] < x){ //配列の中間よりサーチ対象の方が大きいとき
      left = mid + 1; //下端と中間値より右側に持ってくる
    } else { //小さいとき
      right = mid; //上端を中央値に持ってくる
    }

    if(a[left] == x){ //配列の下端がサーチ対象が見つかったとき
      return left; //その場所を返す
    }
  }

  return NOT_FOUND;
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
