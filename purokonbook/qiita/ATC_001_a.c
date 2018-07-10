/*
長方形の町。各区画は道、塀のどちらかであり、高橋君は東西南北に移動できる。
高橋君は塀を壊したりすることなく、魚屋にたどりつけるかどうか判定。

これを読め.深さ優先探索についてかいてある。
https://atc001.contest.atcoder.jp/tasks/dfs_a
*/

/*塗りつぶし　到達できる場所を全部調べること*/

#include <stdio.h>

#define MAX_H 501
#define MAX_W 501

int W, H; //マップの横幅と縦幅
char maze[MAX_H][MAX_W]; //迷路全体
int reached[MAX_H][MAX_W]; //到達可能かを保存する

int search(int x, int y);

int main() {
  int i, j;
  int start_x, start_y;
  int goal_x, goal_y;


  scanf("%d%d", &H, &W);

  for(i = 0; i < H; i++){
    scanf("%s", maze[i]);
  }

  for(i = 0; i < H; i++){
    for(j = 0; j < W; j++){
      //それぞれの座標を入手
      if(maze[i][j] == 's'){
        start_x = j;
        start_y = i;
      }
      if(maze[i][j] == 'g'){
        goal_x = j;
        goal_y = i;
      }
    }
  }

  search(start_x, start_y);

  if(reached[goal_y][goal_x] == 1) printf("Yes");
  else printf("No");

  return 0;
  // printf("%s", search(start_x, start_y)? "YES": "NO");
}

int search(int x, int y) {
  //迷路の外側か塀の場合は何もしない
  if(x < 0 || x >= W || y < 0 || y >= H || maze[y][x] =='#') return;
  //以前に到達していたら何もしない
  if(reached[y][x]) return 0;

  reached[y][x] = 1; //到達したことを表す

  //その場から四方向を試す
  search(x+1, y); //右
  search(x-1, y); //左
  search(x, y+1); //下
  search(x, y-1); //上
}
