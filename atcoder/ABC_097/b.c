/*
Exponential

与えられた数以下の最大のべき乗数を求める。
ただし、１以上で2乗以上じゃないとだめ。
*/

#include <stdio.h>
#include <math.h>

int main(){
  int x;
  int i,j;
  int max = 1;
  int num = 1;

  scanf("%d", &x);

  for(i = 1; i < x; i++){
    if(pow(i,2) >= x) break;

    for(j = 2; j < x; j++){
      num = (int)pow(i, j);
      if(num > max && x >= num){
        max = num;
      }
    }
  }

  // max = 961;
  printf("%d", max);

  return 0;
}
