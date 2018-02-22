/*自己組織化探索のプログラム
サーチ対象が見つかるたびに対象位置を1つ前に持ってくる.
同じデータが何度もサーチされるとそのデータは配列の先頭付近にくるので
結果としてリニアサーチの早い段階で見つかる。
計算量はo(N)だが、局所参照性が高い（全体の中で一部のデータだけを何度も繰り返し
参照する可能性が高い。）

本来ならば見つかったデータを一気に先頭まで持ってくるのが理想。
しかし配列でそれをやろうとすると全てのデータをずらす必要があるので、
それだけでO(N)の計算量が必要になる。

これを適切に行うには配列ではなくリストを使う,
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define NOT_FOUND -1


int organization_search(int key, int *a, int num){
  int n=0, t;

  while(n < num && a[n] != key){ /*対象の値が見つかるまで増加*/
    n++;
  }

  if(n < num){
    if(n > 0){ /*一つ前と入れ替える。対象が先頭にあるとまずいのでif文で区切る*/
      t = a[n - 1];
      a[n - 1] = a[n];
      a[n] = t;
      return n - 1; //変更した先のアドレスを返す
    }
    return n;
  }

  return NOT_FOUND;
}
// 何も見ずに書いたやつ
//   int n, temp;
//
//   for(n = 0; n < num; n++){
//     if(key == a[n]){
//       temp = a[n - 1];
//       a[n - 1] = a[n];
//       a[n] = temp;
//       return n;
//     }
//   }
//   return NOT_FOUND;
// }



int main(){
  int i, r, array[N];

  srand((unsigned int)time(NULL));

  /*適当な配列を作る*/
  for(i = 0; i < N; i++){
    array[i] = rand() % 20; //20までのランダムな値を生成
  }

  for(;;){ //for文の無限ループ
    printf("array ");
    for(i = 0; i < N; i++){
      printf("[%d番目]:%d", i, array[i]);
    }

    printf("\n何を探しますか(-1で終了):");
    scanf("%d",&i);
    if(i == -1){
      break;
    }

    r = organization_search(i, array, N);

    if(r == NOT_FOUND){
      printf("%dはみつかりませんでした\n", i);
    } else {
      printf("%dは%d番目です\n",i, r);
    }
  }

  return EXIT_SUCCESS;
}
