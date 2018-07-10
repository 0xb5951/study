// 動的計画法で線分分割問題を解く

#include <stdio.h>
#include <stdlib.h>

// 個数
#define N 10
// 分割数
#define SEPARATOR 3

// 与えられる数列
const int array[N] = {15,3,7,6,10,4,13,2,3,6};

#define MAX(a,b) (((a) > (b))? (a) : (b))

// 表のセルにあたる構造体
typedef struct {
  int sol; // この地点の最適解
  int num; //その地点から何個か
} cell;

int main() {
  //表を宣言
  cell solutions[N][SEPARATOR + 1]; //配列の中身　分割したやつを入れる　
  int i, j, s, sum;

  // 表の後ろの方から順に埋めていく
  for(i = N - 1; i >= 0; i--) { //配列の中身
    for(j = 0; j < SEPARATOR + 1; j++) { //分割を表す
      solutions[i][j].num = 0; //対象を初期化
      for(sum = 0, s = i; s < N; s++) { //iで見てるとこから一番後ろまでをループ
        sum += array[s]; //和を計算
        if(j == 0 || i == N - 1 || solutions[i][j].num == 0
          || (s != N - 1 && solutions[i][j].sol > MAX(sum, solutions[s + 1][j - 1].sol))) {
            // 分割がない状態　中身を初めて参照する　sのループ一回目　
            //　ｓのループが最後じゃなく
            if(j == 0 || i == N - 1) { //1行目もしくは最終列ならば処理なし
              solutions[i][j].sol = sum;
            } else { //よりよい解決方法を記録する
              solutions[i][j].sol = MAX(sum, solutions[s + 1][j - 1].sol);
            }
            solutions[i][j].num = s - i + 1; //次の分割までの値
          }
      }
    }
  }

  // デバッグ用のテーブルを表示
  for(j = 0; j < SEPARATOR + 1; j++) {
    for(i = 0; i < N; i++) {
      printf("%2d,%2d ", solutions[i][j].num, solutions[i][j].sol);
    }
    printf("\n");
  }

  printf("\n最大の和:%d\n分割方法:", solutions[0][SEPARATOR].sol);
  for(i = 0, j = SEPARATOR; j >= 0 && i != N; j--) {
    printf("[%d]個 ", solutions[i][j].num);
    i += solutions[i][j].num;
  }

  return 0;
}
