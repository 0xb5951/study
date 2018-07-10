/*
2つの整数 A, B が与えられます。 A+B, A−B, A×B の中で最大の値を求めてください。
*/

#include <stdio.h>


int main(){
  int a,b;
  int add,sub,mul;
  int max = 0;

  scanf("%d%d", &a, &b);

  add = a+b;
  sub = a-b;
  mul = a*b;

  if(add >= sub && add >= mul){
    max = add;
  }
  else if(sub >= add && sub >= mul){
    max = sub;
  } else {
    max = mul;
  }


  printf("%d", max);
}
