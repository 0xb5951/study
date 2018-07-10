/*
https://abc052.contest.atcoder.jp/tasks/arc067_a
*/

// N!の約数の個数を10^9+77で割ったあまりを出力する
// 階乗がめちゃでかくなるので、その処理が大事。
// 欲しいのは約数のかず

// 約数の個数を求めるので、素因数分解をする必要がある。
// N！はそこまでの数の積。素因数はN以下しか出てこない。
//
#include<stdio.h>

int main(){
  int n,i,j,m,M=1e9+7,d[100010]={};

  long long s=1;

  scanf("%d",&n);

  for(i=2;i<=n;i++){ //n以下を列挙
    m=i;
    for(j=2;j<=n;j++){
      for(;m && m%j == 0; m/=j )d[j]++; //ｍがその数で何回割れるか
    }
  }
  //for(i=0;i<=n;i++)printf("%d %d\n",i,d[i]);
  for(i=0;i<=n;i++)
  s=(s*(d[i]+1))%M;

  
  printf("%lld",s);
  return 0;
}


// #include <stdio.h>
//
// int main() {
//   int n;
//   int flag[1002];
//   int count = 0;
//
//   scanf("%d",&n);
//   num[0] = 1;
//
//   for(int i = 1; i <= n; i++){
//     for(int j = 0; j < i; j++){
//       if(flag[j] == 1)
//     }
//   }
//
//   int ans;
//   ans = num[n] % 100000007;
//   printf("%d", ans);
//   return 0;
// }
