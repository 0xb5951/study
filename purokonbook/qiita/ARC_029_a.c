/*
高橋君とお肉
高橋君は同じ性能の肉焼き器を持っている。いったん焼きだしたら焼きあがるまで
取り外すことができない。
肉は全部でN個あり、肉iを焼くのに時間tiかかる。
すべての肉を焼くのにかかる最小時間を求める。
*/

/*フラグ管理用の配列と現在時刻を管理する変数を使う
順番に焼く必要はない。

nが４までという制約があるから、各肉にビットフラグを割り振ることで
全探索を行い、その中の最小値を保存する
*/

#include <stdio.h>

int MIN(int a,int b){return a<b?a:b;}
int MAX(int a,int b){return a<b?b:a;}

int main() {
  int n;
  int niku[5];
  int i, j, ans = 999999;
  int ykk_1, ykk_2;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &niku[i]);
  }

  for(i = 0; i < (1 << n); i++){ //bitですべてのパターンを列挙
    ykk_1 = ykk_2 = 0;
    for(j = 0; j < n; j++){
      if(i>>j &1){
        ykk_1 += niku[j];
      }else{
        ykk_2 += niku[j]; //その桁にフラグが立っていたら
      }
    }

    ans = MIN(MAX(ykk_1, ykk_2), ans);

  }

  printf("%d\n", ans);
  // for(i = 0; i < n; i++){
  //   printf("%d", niku[i]);
  // }

  return 0;
}
