/*
高橋君はデータの加工が行いたいです。
整数 a,b,cと、文字列 s が与えられます。
整数 a+b+c と、文字列 s を並べて表示しなさい。

入力は以下の形式で与えられる。

a
b c
s
*/

#include <stdio.h>

int main() {
  int a,b,c;
  char s[100];

  scanf("%d\n", &a);

  scanf("%d %d", &b, &c);

  scanf("%s\n", &s);

  printf("%d %s\n", a+b+c, s);


}
