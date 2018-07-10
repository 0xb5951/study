/*
黒板に, 3 つの正の整数 A,B,C が書かれています. E869120 君は, 以下の操作を K 回行います.

黒板に書かれている整数のうち 1 つを選び, これを 2 倍した値に書き換える.
さて, K 回の操作を終えた後の, 黒板に書かれる整数の合計としてありうる最大の値はいくつでしょうか？
*/

#include <stdio.h>

int MAX(int a,int b){return a<b?b:a;}

int main(){
  int a,b,c;
  int k;
  int i;
  int max = 0, count = 0;

  scanf("%d %d %d\n", &a, &b, &c);
  scanf("%d", &k);

  max = MAX(MAX(a, b), c);
  if(a == max){
    count += b + c;
  }
  else if(b == max){
    count += a + c;
  }
  else if(c == max){
    count += a + b;
  }

  for(i = 1; i <= k; i++){
    max = max * 2;
  }
  count += max;

  printf("%d", count);
}
