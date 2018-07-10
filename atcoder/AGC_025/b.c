/*
https://agc025.contest.atcoder.jp/tasks/agc025_b
*/

//今度また解いてください。

/*
  解けませんでした。

　GはA+Bなので、AとBの組み合わせとすればOK。
　そうすると、２種類で塗りつぶす問題になる。

　トータルでA*x+b*y==kになる組み合わせを選択すればいい。
*/

#include <stdio.h>
#include <stdlib.h>
#define int long long
#define p 998244353

int *fact, *fact_inv;

int MOD(int a){ //a mod pを返す
	a %= p;
	return a >= 0 ? a : a + p;
}

int power(int a, int N){
	if(N == 0){
		return 1;
	}
	else if(N % 2 == 0){
		return power(MOD(a * a), N / 2);
	}
	else{
		return MOD(a * power(a, N - 1));
	}
}

int comb(int N, int k){
	return MOD(fact[N] * MOD(fact_inv[k] * fact_inv[N - k]));
}

signed main(){
	int N, A, B, K, i, j, ans = 0;
	scanf("%lld%lld%lld%lld", &N, &A, &B, &K);

	fact = (int *)malloc(sizeof(int) * (N + 1));
	fact_inv = (int *)malloc(sizeof(int) * (N + 1));

  fact[0] = 1;
	fact_inv[0] = 1;

  for(i = 1; i <= N; i++){
		fact[i] = MOD(fact[i - 1] * i); //階乗を求める。
		fact_inv[i] = power(fact[i], p - 2);
	}

  for(i = 0; i <= N; i++){
		if((K - i * A) % B == 0){ //色の和が0になるなら
			j = (K - i * A) / B; //Bの個数を求める.
			if(j >= 0 && j <= N){ //Bが0以上N以下の時
 				ans = MOD(ans + comb(N, i) * comb(N, j)); //組み合わせの数を足す
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
