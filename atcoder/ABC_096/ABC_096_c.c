/*
H 行 W 列のマス目で表されるキャンバスがあります. 上から i 番目, 左から j 番目のマスを (i,j) と表します.
最初, すべてのマス目は白色です. square1001 君は, 黒い絵の具を使って絵を描きたいと思いました. 具体的には, square1001 君の目標は, si,j= # のときマス (i,j) を黒色, si,j= . のときマス (i,j) を白色にすることです.
しかし, 彼は絵を描くことが得意ではないので, 何回か (0 回でもよい)「上下左右に隣接する 2 つのマスを選び, 両方黒く塗る」ことしかできません. ただし, すでに黒く塗られているマスを選ぶこともでき, この場合マスの色は黒のまま変わりません.
square1001 君が目標を達成することができるか判定してください.
*/

#include <stdio.h>

int h, w;
char field[51][51] = {};
int already[51][51] = {};

int flag = 0;

void check_field(int x, int y){

  if(x < 0 || x >= w || y < 0 || y >= h) return;

  //すでに調査済みなら
  if(already[y][x] == 1) return ;

  already[y][x] = 1;

  if(field[y+1][x] == '.' && field[y-1][x] == '.' && field[y][x-1] == '.' && field[y][x+1] == '.'){
    flag = 1;
  }

  return;
}

int main(){
  int i, j;

  scanf("%d %d", &h, &w);

  for(i = 0; i < h; i++){
    scanf("%s", field[i]);
  }

  for(i = 0; i < h; i++){
    for(j = 0; j < w; j++){
      if(field[i][j] == '#' && already[i][j] == 0) check_field(j,i);
    }
  }

  if(flag == 1){
    printf("No");
  } else {
    printf("Yes");
  }

  return 0;
}
