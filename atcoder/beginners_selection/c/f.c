/*
問題文
1 以上 N 以下の整数のうち、10 進法での各桁の和が A 以上 B 以下であるものの総和を求めてください。

制約
1≤N≤10^4
1≤A≤B≤36
入力はすべて整数である
入力
入力は以下の形式で標準入力から与えられる。

N A B
出力
1 以上 N 以下の整数のうち、10 進法での各桁の和が A 以上 B 以下であるものの総和を出力せよ。

*/

#include <stdio.h>

int main() {
  int n,a,b;
  int i;
  int calc,sum = 0;


  scanf("%d %d %d", &n,&a,&b);

  for(i = 1; i <= n; i++){
    calc = 0;
    calc = (i/10000) % 10 + (i/1000) % 10 + (i/100) % 10  + (i/10) % 10 + i % 10;
    if(calc >= a && calc <= b) sum += i;
  }


  printf("%d", sum);

  return 0;
}
