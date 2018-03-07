/*複数の値の最大公約数を求めるプログラム
これで再帰の強さを判断する。普通に書くと引数を目的の値の数だけ用意しないといけない。
ex.
int gcd(int a, int b){
int i;
for(i = a; i > 0; i--){
if(a % i == 0 && b % i == 0) {
break;
}
}
return i;
}

これを複数の値に適応すると引数が
gcd(q, gcd(b, gcd(c, gcd(d, e))))
みたいになる。数が増えるほど、値を入れ子で入れる必要性がある。
最大公約数を求める数字をあらかじめ全て把握しておく必要性がある。
こんなときに再帰が使える。
*/

/*再帰を利用したgcd()関数
配列Nの先頭～ｎ番目に格納されている整数の最大公約数を再帰を使ってもとめる。
N[0]~N[n]の最大公約数はN[0]~N[n-1]の最大公約数を求めておいてその値と
N[n]の最大公約数を求めればいい。
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 6
#define N[MAX] = {98,140,84,28,42,126};

int gcd(int a, int b){
  int i;
  for(i = a; i > 0; i--){
    if(a % i == 0 && b % i == 0) {
      break;
    }
  }
  return i;
}

int multi_gcd(int n){
  /*n == 1(数が二つしかない)場合には普通にgcdをよぶだけ*/
  if(n == 1){
    return gcd(N[0], N[1]);
  }

  /*n>1の場合はN[n]とN[0]..N[n-1]のｇｃｄを呼び出す*/
  return gcd(N[n], multi_gcd(n - 1));
}

int main(){
  printf("配列Nの最大公約数は%dです\n", multi_gcd(MAX - 1));
  return EXIT_SUCCESS;
}
