/*
https://beta.atcoder.jp/contests/arc030/tasks/arc030_1
*/

/*閉路グラフの問題

グラフが輪になってつながっている。
このグラフの頂点を消去することでk個の連結成分を持ったグラフに
することができるかを調べる。
*/

#include <stdio.h>

int main(){
  int n,k;

  scanf("%d%d", &n, &k);

  if((n/2) >= k){
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
