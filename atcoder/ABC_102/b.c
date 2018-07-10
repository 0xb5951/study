/*
https://beta.atcoder.jp/contests/abc102/tasks/abc102_a
*/

#include <stdio.h>

#define MAX 100

int main() {
  int n;
  long a[MAX] = {};
  int i;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%ld", &a[i]);
  }

  long max = 0;
  long min = 1000000000;

  for(i = 0; i < n; i++){
    if(max < a[i]) max = a[i];
    if(min > a[i]) min = a[i];
  }

  long ans = 0;
  ans = max - min;
  printf("%ld", ans);

  return 0;
}
