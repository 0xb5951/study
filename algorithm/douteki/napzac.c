// ナップザック問題を動的計画法で解くプログラム
/*ナップザック問題は限られた容量のかばんに荷物を入れるとき、もっとも価値が高くなる
ような組み合わせを探す問題

動的計画法による解法では、荷物の種類を増やしていくことで状態を更新する。
判断はナップザックの大きさにおける価値の大きさを用いる*/

#include <stdio.h>
#include <stdlib.h>

// 商品の数とそれぞれの大きさ、価値
#define N 5
int size[N] = {2,3,5,6,9};
int value[N] = {2,4,7,10,14};

// ナップザックの大きさ
#define NAP_SIZE 16

int main() {
  // ナップザックの現時点での価値
  int nap_value[NAP_SIZE + 1] = {0}; //それぞれのサイズにおいてナップザック中身を初期化
  int i, j, new_value;

  printf("ナップザックの大きさ:");
  for(i = 1; i < NAP_SIZE + 1; i++){
    printf("%2d ", i);
  }
  printf("\n\n");

  // 扱う品物を1つずつ増やしていく
  for(i = 0; i < N; i++) {
    // ナップザックの大きさがjのものに対して品物i番を入れてみる
    for(j = size[i]; j < NAP_SIZE + 1; j++) {
      // 品物iを入れてみた場合、新しい価値はどうかわるか
      new_value = nap_value[j - size[i]] + value[i]; //一個前の値に対して、選択してる品物の価値を足す

      if(new_value > nap_value[j]) { //新しい値が現在の価値より高ければ
        nap_value[j] = new_value;  //状態を更新
      }
    }

    printf("      品物 %dまで使う:", i+1);
    for(j = 1; j < NAP_SIZE + 1; j++) {
      printf("%2d ", nap_value[j]);
    }
    printf("\n");
   }

  return 0;
}
