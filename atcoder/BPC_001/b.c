/*
https://bitflyer2018-qual.contest.atcoder.jp/tasks/bitflyer2018_qual_b
*/

#include <stdio.h>

#define max 100000

int main() {
  long a,b,n;
  char x[max] = {};

  scanf("%ld%ld%ld", &a, &b, &n);
  scanf("%s", x);

  for(long i = 0; i < n; i++){
    if(x[i] == 'S') a--;
    if(x[i] == 'C') b--;

    if(x[i] == 'E'){
      if(a > b){
        a--;
      }
      else if(a < b){
        b--;
      }
      else if(a == b){
        a--;
      }
    }
  }

  if(a <= 0) a = 0;
  if(b <= 0) b = 0;

  printf("%ld\n%ld", a, b);
  return 0;
}
