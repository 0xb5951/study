/*
https://abc054.contest.atcoder.jp/tasks/abc054_b
*/

#include <stdio.h>

#define MAX 50

int main(){
  char a[MAX+1][MAX+1] = {};
  char b[MAX+1][MAX+1] = {};
  int n,m;
  int i,j;

  scanf("%d%d", &n, &m);

  for(i = 0; i < n; i++){
    scanf("%s", a[i]);
  }

  for(i = 0; i < m; i++){
    scanf("%s", b[i]);
  }

  // for(i = 0; i < m; i++){
  //   printf("%s", b[i]);
  //   printf("\n", b[i]);
  // }


  return 0;
}
