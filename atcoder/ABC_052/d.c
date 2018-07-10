/*
https://abc052.contest.atcoder.jp/tasks/arc067_b
*/

#include <stdio.h>

#define MAX 10001

int main() {
  int n;
  long int a,b;
  long int x,pre;
  int i;
  long int cost = 0;

  scanf("%d%ld%ld", &n, &a, &b);
  scanf("%ld", &x);
  pre = x;

  for(i = 0; i < n; i++){
    long int dx;
    scanf("%ld", &x);
    dx = x - pre;

    if(dx*a >= b){ //テレポートの方が便利なら
      cost += b;
    } else{
      cost += dx *a;
    }

    pre = x;
  }

  // for(i = 1; i < n; i++){
  //   dx = x[i] - x[i-1];
  //   // printf("%d ", dx);
  //
  //   if(dx*a >= b){ //テレポートの方が便利なら
  //     cost += b;
  //   } else{
  //     cost += dx *a;
  //   }
  // }

  printf("%ld", cost);

  return 0;
}
