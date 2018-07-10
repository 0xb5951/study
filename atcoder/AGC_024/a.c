/*問題文
高橋君、中橋君、低橋君は、それぞれ整数 A,B,C を持っています。
 以下の操作を K 回行った後、高橋君の持っている整数から中橋君の持っている整数を引いた値を求めてください。

3 人は同時に、他の 2 人の持っている整数の和を求める。その後、自分の持っている整数を求めた整数で置き換える。
ただし、答えの絶対値が 1018 を超える場合は、代わりに Unfair と出力してください。*/


/*このUNfairは絶対に起こらないので、無視してもいい*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
  long int a,b,c,k;
  long int ta,tb,tc;
  long int ans = 0;
  int flag = 0;

  scanf("%ld%ld%ld%ld", &a,&b,&c,&k);
  ta = b+c;
  tb = a+c;
  tc = a+b;
  if(k <= 0) {
    ta = a;
    tb = b;
    tc = c;
  }
  ans = ta - tb;
  ans = abs(ans);

  if(ans >= (long int)pow(10,18)){
    flag = 1;
    printf("Unfair");
  }

  if(a>b){
    if(k%2 == 1) ans = ans * -1;
  }else {
    if(k%2 == 0) ans = ans * -1;
  }

  if(flag == 0) printf("%ld", ans);
  return 0;
}
