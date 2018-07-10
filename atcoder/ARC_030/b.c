/*
https://beta.atcoder.jp/contests/arc030/tasks/arc030_2
*/

/*n頂点から成り、n-1子の辺を持つ連結グラフ。
これは閉路を持たないことが証明されている。*/

#include <stdio.h>

#define max_num 100

int map[max_num][max_num] = {};
int cost = 0;
int n,x;

void cal_cost(int i){
  for(int j = 1; j <= n; i++){
    if(map[i][j] == 1){
      printf("%d->%d ", i, j);
      cal_cost(j);
    }
  }
}

int main(){
  int juel[max_num] = {};

  scanf("%d%d", &n,&x);

  for(int i = 1; i <= n; i++){
    scanf("%d", &juel[i]);
  }

  for(int i = 0; i <= n-1; i++){
    int x,y;
    scanf("%d%d", &x, &y);
    map[x][y] = 1;
    map[y][x] = 1;
  }

  cal_cost(1);

  // for(int i = 1; i <= n; i++){
  //   if(juel[i] == 1){
  //     cal_cost(x, i);
  //     x = i;
  //   }
  // }


  return 0;
}
