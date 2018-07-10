/*
https://abc056.contest.atcoder.jp/tasks/abc056_a
*/

#include <stdio.h>

int main(){
  char a,b;

  scanf("%c %c", &a, &b);

  if(a == 'H'){
    if(b == 'H') printf("H");
    if(b == 'D') printf("D");
  }
  else if(a == 'D'){
    if(b == 'H') printf("D");
    if(b == 'D') printf("H");
  }

  return 0;
}
