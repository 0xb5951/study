// バックトラック法で数列分割問題を解く
/*問題は数列に与えられたランダムな数字を、区切ってそれぞれのグループの合計値を計算する
すべてのグループのうち、一番大きな値を代表値とする。これが一番小さくなるような区切りかたを
考える。*/

#include <stdio.h>
#include <stdlib.h>

// 用意する数字の個数と分割する数
#define N 10
#define SEPARATOR 3

int value[N] = {15,3,7,6,10,4,13,2,3,6}; //目的の数列
int sep_pos[SEPARATOR] = {0}; //分割の場所を保存する配列

// ベストな分割とそのなかのグループの最大値を保存
int best_sep_pos[SEPARATOR] = {0};
int bast_sep_max_value = 9999;

// 分割を実装する再帰関数
void separate(int pos, int num) { //　分割スタートの位置　現在の分割数
  int i, j, k , start, end, max;

  // 新しい分割場所を設定
  // 分割場所を次に移す
  sep_pos[num++] = pos;

  // 分割がすべて決まってたら
  if(num == SEPARATOR) {
    max = 0;

    // 設定された分割で、最大のグループ和を算出する
    for(i = 0; i <= SEPARATOR; i++) {
      //三項演算子　真偽値 ? 真の場合の処理 :　偽の場合の処理
      start = (i == 0)? 0: sep_pos[i - 1]; //一分割のスタート場所を設定
      end = (i == SEPARATOR)? N: sep_pos[i]; //一分割の終端（temp）を設定
      k = 0; //分割の値を保存するための変数
      for(j = start; j < end; j++) { //一分割の和を求める
        k += value[j];
      }
      if(k > max) { //現在の分割での最大値をmaxに保存
        max = k;
      }
    }

    //最大のグループ和が保存されている和より小さければ
    if(max < bast_sep_max_value) {
      // 現在の分割を保存する
      bast_sep_max_value = max;
      for(i = 0; i < SEPARATOR; i++) {
        best_sep_pos[i] = sep_pos[i]; //その時の分割場所を保存
      }
    }
    return;
  }

  // 次の分割場所を設定
  // 一分割を再帰で繰り返す
  for(i = pos + 1; i < N - SEPARATOR + num + 1 ; i++) {
    separate(i, num);
  }
}

int main() {
  int i, j, start, end;
  // 最初の分割場所を設定して再帰を呼び出す
  for(i = 0; i < N -SEPARATOR + 1; i++) {
    separate(i, 0);
  }

  // 保存された分割場所を表示する
  for(i = 0; i <= SEPARATOR; i++) {
    start = (i == 0)? 0: best_sep_pos[i - 1];
    end = (i = SEPARATOR)? N: best_sep_pos[i];
    for(j = start; j < end; j++) {
      printf("%d ", value[j]);
    }
    printf("\n");
  }

  return 0;
}
