/*
以下の条件を満たす, 長さ N の数列 a1,a2,…,aN を 1 つ出力してください.

ai (1≤i≤N) は 55 555 以下の素数である.
a1,a2,…,aN の値はすべて異なる.
a1,a2,…,aN からどの異なる 5 個の整数を選んでも, この合計は合成数になる.
条件を満たす数列が複数個存在するとき、条件を満たすもののうちどのような数列を出力しても正解となります.
*/

/*時間内にとけず。
解説リンク　https://www.youtube.com/watch?v=geZKa28g93o
*/

#include <stdio.h>

int calc_sosuu(int x){

  for( j=2; j<n ;++j ){
    if( i%j==0 ){
      return 0;
    }
  }

  return 1;
}


int main() {
  int n;
  int array[50] = {};

  scanf("%d", &n);

  while(num < n){
    for(i = 2; i < 55555; i++){
      if( calc_sosuu == 1 &&  )
    }
    num++;
  }


}
