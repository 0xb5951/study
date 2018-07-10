/*
https://beta.atcoder.jp/contests/abc102/tasks/abc102_a
*/

#include <stdio.h>

int main() {
  long n;
  scanf("%ld", &n);

  if(n%2 == 0){
    printf("%ld", n);
  } else {
    printf("%ld", 2*n);
  }

  return 0;
}
