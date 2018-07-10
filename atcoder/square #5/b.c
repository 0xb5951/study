/*
問題文
E869120 君は, square869120Contest #5 の開催を記念するために, 1,2,3,[cdots],N+M の番号がつけられた N+M 個の円を用いて 2 次元平面上にエンブレムを作ろうとしている.
番号 1,2,3,[cdots],N の円は, 中心座標 (xi,yi) と半径 ri が決まっている.
その一方で, 番号 N+1,N+2,N+3,[cdots],N+M の円は, 中心座標 (xi,yi) が決まっているが, 半径は決まっていない.
エンブレムに使われる円は接してもよいが, どの円も他の円と交わるまたは含んではならないとき, 最も小さい円の半径を最大化しなさい.

入力
入力は以下の形式で標準入力から与えられる.

N M
x1 y1 r1
x2 y2 r2
:    :
xN yN rN
xN+1 yN+1
xN+2 yN+2
:    :
xN+M yN+M
出力
最も小さい円の半径としてありうる最大値を, 1 行で出力しなさい.
ただし, 相対誤差または絶対誤差が 10−6 以内であるとき正解とみなされる.

制約
N は 0 以上 100 以下の整数.
M は 0 以上 100 以下の整数.
N+M≥2.
xi,yi (1≤i≤N+M) は −100 以上 100 以下の整数.
ri は 1 以上 100 以下の整数.
入力で与えられる座標はすべて異なる.
番号 1,2,3,[cdots],N の円は交差せず, ある円がほかの円を含まない.
番号 N+1,N+2,N+3,[cdots],N+M の円は, 番号 1,2,3,[cdots],N の円の内部または円周上にない.
*/

#include <stdio.h>
#include <math.h>

double ans[200];

void make_range(int start, int m, int *x, int *y){
  int i;

  double alk, dist;
  double minrange[m];

  for(i = start; i < m;i++){
    alk = pow(x[i] - x[i+1], 2) + pow(y[i] - y[i+1], 2);
    dist = sqrt(alk);
    minrange[i] = dist / 2;
  }
  ans[start] = minrange[0];
  for(i = 1; i < m;i++){
    if(minrange[i] <= ans[start]){
      ans[start] = minrange[i];
    }
  }

}

int main() {
  int n,m;
  int x[201], y[201], r[101];
  int i;

  double dist, alk, minrange;

  scanf("%d %d", &n, &m);

  for(i = 0; i < n; i++){
    scanf("%d %d %d", &x[i], &y[i], &r[i]);
  }

  for(i = n; i < n+m; i++){
    scanf("%d %d", &x[i], &y[i]);
  }

  if(m <= 0){
    minrange = r[0];
    for(i = 1; i < n; i++){
      if(minrange >= r[i]) minrange = r[i];
    }
  }

  make_range(0 ,m, x, y);

  minrange = ans[0];
  for(i = 1; i < n+m; i++){
    if(minrange >= ans[i]) minrange = ans[i];
  }

  printf("%lf", minrange);

  return 0;
}
