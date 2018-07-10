/*
問題文
N 枚のカードがあります. i 枚目のカードには, ai という数が書かれています.
Alice と Bob は, これらのカードを使ってゲームを行います. ゲームでは, Alice と Bob が交互に 1 枚ずつカードを取っていきます. Alice が先にカードを取ります.
2 人がすべてのカードを取ったときゲームは終了し, 取ったカードの数の合計がその人の得点になります. 2 人とも自分の得点を最大化するように最適な戦略を取った時, Alice は Bob より何点多く取るか求めてください.

制約
N は 1 以上 100 以下の整数
ai (1≤i≤N) は 1 以上 100 以下の整数
入力
入力は以下の形式で標準入力から与えられる.

N
a1 a2 a3 … aN
出力
両者が最適な戦略を取った時, Alice は Bob より何点多く取るかを出力してください.
*/

#include <stdio.h>

int main() {
  int n;
  int al,bo,sum = 0;
  int i;
  int temp,flag;

  int card[100] = {0};

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &card[i]);
  }

  /*card配列をソートする*/
  do{
    flag = 0;
    for(i = 0; i < n-1; i++){
      if(card[i] > card[i+1]) {
        flag = 1;
        temp = card[i];
        card[i] = card[i+1];
        card[i+1] = temp;
      }
    }
  }while(flag == 1);

  flag = 1;
  for(i = n-1; i >= 0; i--){

    if(flag == 1){
      al += card[i];
      flag = 0;
    } else {
      bo += card[i];
      flag = 1;
    }
  }

  sum = al - bo;

  printf("%d",sum);

  return 0;
}
