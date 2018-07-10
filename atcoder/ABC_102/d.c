/*
https://beta.atcoder.jp/contests/abc102/tasks/arc100_b
*/

#include <stdio.h>
#include <math.h>

#define MAX 200000

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

  do {
    flag = 0;
    for(i = 0; i < N - 1; i++){
      if(a[i] > a[i+1]){
        flag = 1;
        j = a[i];
        a[i] = a[i+1];
        a[i+1] = j;
      }
    }
  }while (flag == 1);

  


  printf("%ld", ans);

  return 0;
}
