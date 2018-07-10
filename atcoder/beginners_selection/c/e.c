/*
あなたは、500 円玉を A 枚、100 円玉を B 枚、50 円玉を C 枚持っています。
これらの硬貨の中から何枚かを選び、合計金額をちょうど X 円にする方法は何通りありますか。

同じ種類の硬貨どうしは区別できません。2 通りの硬貨の選び方は、ある種類の硬貨についてその硬貨を選ぶ枚数が異なるとき区別されます。

制約
0≤A,B,C≤50
A+B+C≥1
50≤X≤20,000
A,B,C は整数である
X は 50 の倍数である

入力
入力は以下の形式で標準入力から与えられる。

A
B
C
X
出力
硬貨を選ぶ方法の個数を出力せよ。
*/

#include <stdio.h>

int main() {
  int a,b,c;
  int x;

  int i,j,k;
  int obj,count;

  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  scanf("%d", &x);

  for(i = 0; i <= a; i++){
    if(500 * i <= x){
      for(j = 0; j <= b; j++){
        if(500 * i + 100 *j <= x){
          for(k = 0; k <= c; k++){
            obj = 500*i + 100*j + 50*k;
            if(obj == x){
              count++;
            }
          }
        }
      }
    }
  }

  printf("%d", count);

  return 0;

}
