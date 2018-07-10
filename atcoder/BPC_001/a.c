/*
codeFlyerの説明
https://bitflyer.com/ja-jp/recruit/codeflyer201806
*/

#include <stdio.h>

int main(){
 int a,b;
 int ans = 0;

 scanf("%d%d", &a, &b);
  int i = 0;

  while (1) {
    if(ans <= a)  ans = b*i;
    else{
      ans -= b;
      break;
    }
    i++;
  }

  printf("%d", ans);
  return 0;
}
