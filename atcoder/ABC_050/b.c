/*
https://abc050.contest.atcoder.jp/tasks/abc050_b
*/

/*strcpyは数列に使えない。文字列だけ*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  int n,m;
  int t[101] = {};

  scanf("%d", &n);

  for(int i  = 0; i < n; i++){
    scanf("%d", &t[i]);
  }

  scanf("%d", &m);

  for(int i  = 0; i < m; i++){
    int p, x;
    int sum = 0;
    int temp[101] = {};
    scanf("%d%d", &p, &x);

    p--;
    for(int i= 0; i < n; i++) temp[i] = t[i];

    temp[p] = x;

    for(int j = 0; j < n; j++){
      sum += temp[j];
    }

    printf("%d\n", sum);
  }

  return 0;
}
