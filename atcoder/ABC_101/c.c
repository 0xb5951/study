/*
https://abc101.contest.atcoder.jp/tasks/arc099_a
*/

#include <stdio.h>

#define MAX 100001

int main() {
  int n,k;
  int count = 0;
  int a[MAX] = {};

  scanf("%d%d", &n, &k);

  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  for(int i = 1; ; i += (k-1)){
    if(i >= n) break;
    count++;
  }

  printf("%d", count);

  return 0;

}
