/*
https://abc050.contest.atcoder.jp/tasks/arc066_a
*/

/*ギブ*/

#include <stdio.h>

int dat[100001] = {};

int main() {
    long n, ans=1;
    int t;

    scanf("%ld", &n);

    for (long i=0; i<n; i++) {
        long a;
        scanf("%ld", &a);
        dat[a]++;
    }

    t = n % 2 + 1;

    if (t == 2 && dat[0] != 1) { //偶数で0がにこあるなら
        puts("0");
        return 0;
    }

    for (long i=t; i<n; i+=2) //偶数、きすうに対応
        if (dat[i] != 2) {
            puts("0");
            return 0;
        }

    for (long i=1; i<=n/2; i++)
        ans = (2 * ans) % 1000000007;
    printf("%ld\n", ans);
}
