/*
N+1 個のマスが左右に一列に並んでいます． これらのマスには，左のマスから順に 0,1,…,N の番号が付けられています．

あなたは，最初マス X にいます． 隣り合うマスの間は自由に移動することができ，マス 0 またはマス N にたどり着くとゴールすることができます． ただし，i=1,2,…,M について，マス Ai には料金所があり，そのためマス Ai に移動してくる際には 1 のコストがかかります． なお，マス 0，マス X，マス N には料金所がないことが保証されます．

ゴールするまでにかかるコストの最小値を求めてください
*/

#include <stdio.h>

int main() {
  int n,m,x; //マス　料金所の数　現在地
  int i;
  int cost,costp, costm;
  int a[100] = {0};


  scanf("%d %d %d", &n,&m,&x);

  for(i = 0; i < m; i++){
    int c;
    scanf("%d", &c);
    a[c] = 1;
  }

  for(i = x; i <= n; i++){
    costp += a[i];
    // printf("%d " , a[i]);
  }

  for(i = x; i >= 0; i--){
    costm += a[i];
  }

  if(costp < costm){
    cost = costp;
  } else {
    cost = costm;
  }

  printf("%d", cost);
}
