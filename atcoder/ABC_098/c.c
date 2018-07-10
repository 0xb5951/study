/*
N人が一列にならんでいる。
それぞれは右(E)か左(W)どちらかを向いている。

このうち１人をリーダーに任命する。他の人はリーダーの方を向く。
この時、方向を替える人が最小になるリーダーを選び、向きを替える人の人数を求める。
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//standard
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define abs(a) ((a)>(0)?(a):-(a))

int main() {
  int n;
  int ans = 300000;
  char a[300001];
  int ruiseki[300001];
  int count = 0;

  //input
  scanf("%d",&n);
  scanf("%s",a);

  for(int i = 0; i <= n-1; i++){
    if(a[i]=='E'){
      count++;
    }
    ruiseki[i] = count;
  }

  //calculation
  for(int i = 0; i <= n-1; i++){
    if(i == 0){
      ans = ruiseki[n-1] - ruiseki[i];
    }else{
      ans = min(ans,i - ruiseki[i-1] + ruiseki[n-1] - ruiseki[i]);
    }
  }


  //Output
  printf("\n%d\n",ans);
  return 0;
}
