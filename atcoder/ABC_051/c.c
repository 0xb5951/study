/*
https://abc051.contest.atcoder.jp/tasks/abc051_c
*/

/*
問題文より4つの経路を見つける必要がある。
これより、スタートとゴールの周りはぜったいにすべて訪れる。

マップなどめんどくさいものを使う必要はなく、
スタートとゴールの差を求めればいい。
必ず右上にあるので、最短路は上に上がって右に行き、下に下がって、左に行くしかない。


*/

#include <stdio.h>

int main(){
  int sx, sy, tx, ty;
  scanf("%d%d%d%d", &sx, &sy, &tx, &ty);

  // 差を求める
  int dx,dy;
  dx = tx - sx;
  dy = ty - sy;

  // 経路１
  for(int i = 0; i < dy; i++){
    printf("U");
  }
  for(int i = 0; i < dx; i++){
    printf("R");
  }

  // 経路２
  for(int i = 0; i < dy; i++){
    printf("D");
  }
  for(int i = 0; i < dx; i++){
    printf("L");
  }

  // // 経路３
  printf("L");
  for(int i = 0; i < dy+1; i++){
    printf("U");
  }
  for(int i = 0; i < dx+1; i++){
    printf("R");
  }
  printf("D");

  // // 経路４
  printf("R");
  for(int i = 0; i < dy+1; i++){
    printf("D");
  }
  for(int i = 0; i < dx+1; i++){
    printf("L");
  }
  printf("U");

  return 0;
}



// #include<stdio.h>
// #include<string.h>
//
// int dy[4] = {-1,0,1,0};
// int dx[4] = {0,1,0,-1};
//
// int book[51][51],h,w,head,tail,flag;
//
// char ST[5000];
// int stack_top = 0;
//
// void push_stack(char move){
//   ST[stack_top] = move;
//   stack_top++;
//   return;
// }
//
// char pull_stack(){
//   char tp;
//   stack_top--;
//   tp = ST[stack_top];
//   return tp;
// }
//
// int int main() {
//
//   return 0;
// }
