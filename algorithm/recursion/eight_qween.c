//バックトラック法でエイトクイーン問題を解くプログラム

#include <stdio.h>
#include <stdlib.h>

//チェスの盤面を表す
int board[8][8];

//(x,y)にクイーンをおけるかチェックする関数
int check(int x, int y) {
  int q,p;

  //左側にクイーンがあるかチェック（左から埋めていくので右には存在しない）
  for(p = 0; p < x; p++) {
    if(board[p][y] == 1){ //クイーンがあったら
      return 0;
    }
  }

  //左上をチェック
  p = x; q = y;
  while(p > 0 && q > 0) { //一番左上にいくまで
    if(board[--p][--q]  == 1){ //クイーンがあったら
      return 0;
    }
  }

  //左下をチェック
  p = x; q = y;
  while(p > 0 && q < 7){ //一番左下まで
    if(board[--p][++q] == 1) {
      return 0;
    }
  }

  //ここまできたら対象の場所にクイーンを置くことができる。
  return 1;
}

//現在の盤面状態を表示
void showboard(void) {
  int x,y;
  for(y = 0; y < 8; y++){
    for(x = 0; x < 8; x++){
      printf("%c ", board[x][y] ? 'Q' : '.'); //盤面が１だとQ 0だと.を表示する
    }
    printf("\n");
  }
}

int solve(int x) {
  int i;

  if(x == 8){ //８このクイーンをおくことができたら
    return 1;
  }

  for(i = 0; i < 8; i++){ //y軸を動かす
    if(check(x, i)) { //実行されるのはチェックの返り値が1の時。つまりクイーンが置けるとき
      board[x][i] = 1;

      if(solve(x + 1)) { //この列が成功したときだけ、次の列のチェックが可能.
        return 1;
      } else {
        board[x][i] = 0;
      }

    }
  }
  return 0;
}

int main() {
  if(solve(0)) {
    showboard();
  }
  return 0;
}
