/*
https://beta.atcoder.jp/contests/abc102/tasks/arc100_a
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 20000000

int main() {
  long n;
  long a[MAX] = {};
  long flag[MAX] = {};
  long i;
  long b = 0;

  scanf("%ld", &n);

  for(i = 1; i <= n; i++){
    scanf("%ld", &a[i]);
  }


  for(i = 1; i <= n; i++){
    a[i] = abs(a[i] - i);
  }

  int count = 0;
  for(i = 0; i <= n; i++){
    if(count < flag[i]){
      count = flag[i];
      b = -1*i;
      // printf("%d", b);
    }
  }

  long ans = 0;

  for(i = 1; i <= n; i++){
    ans += abs(a[i] - (b+i));
  }

  printf("%ld", ans);

  return 0;
}
