/*
半分のピザの値段を求めて、それを基に一番安い一枚を積み上げていく
こっちがあってた

for文で総当たり方式で求める
*/

#include <stdio.h>

int main() {
  int a,b,c,x,y;
  int i, j, k;
  int m_price,temp;

  scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);

  // m_price = 9999999;
  // for(i = 0; i < x; i++){
  //   for(j = 0; j < y; j++){
  //     for(k = 0; k < x+y; k += 2){
  //       if(i+(k/2) == x && j +(k/2) == y){
  //         temp = a*i+b*j+c*k;
  //         if(m_price > temp){
  //           m_price = temp;
  //         }
  //       }
  //     }
  //   }
  // }

  if(a+b >= c*2){
    m_price = a*x + b*y;
  } else {
    m = (x >= y ? x : y) * c * 2;
    if(x > y){
      n = y*c*2 +(x - y)*a;
    }
  }

  printf("%d", m_price);

  return 0;
}
