/*
https://yukicoder.me/problems/43
*/

#include <stdio.h>

int main(){
  int a,b;
  int i;
  int cal = 0;

  scanf("%d%d", &a, &b);
  for(i = 0; ;i++){
    cal = a*i;
    if(cal >= b) break;
  }

  printf("%d", i);
  return 0;
}
