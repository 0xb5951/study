/*猫と犬が合わせて A+B 匹います． このうち A 匹は猫であることがわかっていますが，残りの B 匹は猫と犬のどちらであるかわかっていません．

この A+B 匹の中に，猫がちょうど X 匹いるということはありうるかどうか判定してください

入力
入力は以下の形式で標準入力から与えられる。

A B X
出力
猫がちょうど X 匹いるということがありうるならば YES を，ありえないならば NO を出力せよ．

*/

#include <stdio.h>

int main() {
  int a,b,x = 0;
  int c;

  scanf("%d %d %d", &a,&b,&x);

    if(a+b >= x && x >= a){
      printf("YES");
    } else {
      printf("NO");
    }

  // if(flag == 1){
  // } else {
  //   printf("NO");
  // }

  return 0;
}
