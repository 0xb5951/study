/*
https://abc100.contest.atcoder.jp/tasks/abc100_d
*/

/*
N種類のケーキをM個食べる。
その時、同じ種類のケーキを食べないようにしつつ、得点の絶対値が大きくなるようにしたい。
*/

/*
絶対値の最大値はmax{±x,±y,±z}の八通りのそれぞれを全探索すればいい。
配列の各要素を足して、方向を決める方法もあるが桁あふれが起きる可能性がある。
よって、正負の方向自体を探索すればいいです。
そうしてM個だけ、方向に応じて探索する。答えは全探索した８通りの中でもっともいいものを返す。
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//standard
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define abs(a) ((a)>(0)?(a):-(a))

//printf
#define PRINTD(d) printf("%d\n",(d))
#define PRINTL(d) printf("%lld\n",(d))

//Prototype
void bubbleSort(long int* N, int len);
void Swap(int long *a,long int *b);


int main() {
    int n,m;
    long int x[1000];
    long int y[1000];
    long int z[1000];

    long tameru[8][1000];
    long ans = 0;

    //input
    scanf("%d",&n);
    scanf("%d",&m);

    for(int i = 0; i < n; i++){
        scanf("%ld %ld %ld",&x[i],&y[i],&z[i]);
        tameru[0][i] = x[i] + y[i] + z[i];
        tameru[1][i] = x[i] + y[i] - z[i];
        tameru[2][i] = x[i] - y[i] + z[i];
        tameru[3][i] = x[i] - y[i] - z[i];
        tameru[4][i] = -x[i] + y[i] + z[i];
        tameru[5][i] = -x[i] + y[i] - z[i];
        tameru[6][i] = -x[i] - y[i] + z[i];
        tameru[7][i] = -x[i] - y[i] - z[i];
    }

    //calculation
    for(int i = 0; i < 8; i++){
        bubbleSort(tameru[i], n);
        long count = 0;
        for (int j = n-1; j >= n - m; j--) {
            count += tameru[i][j];
        }
        ans = max(ans, count);
    }

    printf("\n%ld\n",ans);
    return 0;
}


//BubbleSort
void bubbleSort(long int* N, int len){
    int i,j;

    for(i=0; i<len; i++){
        for(j=len-1; j>i; j--){
            if(N[j] < N[j-1]){
                Swap(&N[j],&N[j-1]);
            }
        }
    }
}

//general function
void Swap(long int *a, long int *b) {
    long int tmp = *a;
    *a = *b;
    *b = tmp;
}
