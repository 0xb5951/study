/*
問題文
X 段重ねの鏡餅 (X≥1) とは、X 枚の円形の餅を縦に積み重ねたものであって、どの餅もその真下の餅より直径が小さい（一番下の餅を除く）もののことです。例えば、直径 10、8、6 センチメートルの餅をこの順に下から積み重ねると 3 段重ねの鏡餅になり、餅を一枚だけ置くと 1 段重ねの鏡餅になります。

ダックスフンドのルンルンは N 枚の円形の餅を持っていて、そのうち i 枚目の餅の直径は di センチメートルです。これらの餅のうち一部または全部を使って鏡餅を作るとき、最大で何段重ねの鏡餅を作ることができるでしょうか。

制約
1≤N≤100
1≤di≤100
入力値はすべて整数である。
入力
入力は以下の形式で標準入力から与えられる。

N
d1
:
dN
出力
作ることのできる鏡餅の最大の段数を出力せよ。

*/

#include <stdio.h>

int main() {
  int n;
  int mochi[101];
  int i;
  int temp,flag,count;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &mochi[i]);
  }

  /*餅をソート*/
  do{
    flag = 0;
    for(i = 0; i < n;i++){
      if(mochi[i] > mochi[i+1]){
        flag = 1;
        temp = mochi[i];
        mochi[i] = mochi[i+1];
        mochi[i+1] = temp;
      }
    }
  }while(flag == 1);

  temp = mochi[0];
  count = 1;

  for(i = 1; i < n; i++){
    if(temp < mochi[i]){
      temp = mochi[i];
      count++;
    }
  }

  printf("%d", count);

  return 0;

}
