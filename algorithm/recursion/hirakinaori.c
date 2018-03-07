/*開き直り数のプログラム
問題は以下の通り。
3435という数は1桁ずつに分けて、それぞれの数を自分と同じ数のべき乗した足し合わせると
自分と同じ3435というになる。
3435　＝　3^3 + 4^4 + 3^3 + 5^5
このような数を開き直り数とよぶことにする。では1以上の整数で3435以外の開き直り数を
すべて見つけていただきたい。ただし0^0=0とする。
*/

/*教科書のやつ
必要な関数
1　1～10の数字の組み合わせをすべて作る。
2　それぞれの数字の組み合わせについて、各桁のべき乗の和を計算する
3　計算した値に含まれる各桁の数字をしらべて、もとの組み合わせと一致するかどうかを調べる。
*/

#include <stdlib.h>
#include <stdio.h>

// 0~9のべき乗を１度だけ計算して、下記の配列に結果を格納しておく。
unsigned long power[10] = {0};

/*現在使用している数字群の個数*/
int number_using[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

/*numberの中にdigit(0~9の1桁の整数)が何文字あるかを数える*/
int NumOfDigit(unsigned long number, unsigned long digit) {
  int ret;
  ret = 0;

  /*0桁ならば0を返す（何も含まれていない）*/
  if(number == 0){
    return 0;
  }

  /*1の位が"digit"であるかどうかのチェック*/
  if(number % 10 == digit){
    ret = 1; //digitであれば返値に１つ足す
  }

  /*10で割ることによって次の桁以降のチェックを再帰的に行う。*/
  ret += NumOfDigit(number / 10, digit);

  return ret;
}

/*生成した数字群が開き直り数かどうかの判定を行う。
これは新しい数を生成した直後に行われる。
現在の数字群に対して各桁のべき乗した数の和を求め、その
計算結果が現在の数字群とい一致するかどうか判断する。
*/
void CheckNumber(void){
  //数字群を基に計算した結果の数字の個数がもとの数字群
  //と同じだけ使われているかどうかのチェック
  int i;
  unsigned long result;
  result = 0;

  /*数字群をもとに計算結果を作成する*/
  for(i = 1; i <= 9; i++){
    result += power[i] * number_using[i];
  }

  //計算結果の中の数字の個数が数字群と同じかどうかチェックする
  for(i = 1; i <= 9; i++){
    if(NumOfDigit(result, i) != number_using[i]){
      return;  //１つでも違えば、それは解ではない
    }
  }

  printf("%lu \n", result);
  return;
}

/*使用する数字の組み合わせをnumber_usingに格納する.
あくまで数字の個数で見るので大きさは関係ない。
ex. 3345
 number_using[3] == 2
 number_using[4] == 1
 number_using[5] == 1
 これ以外の要素は全て0となる。
*/
void MakeNumbers(int start, int kosuu){
  int i;

  //10桁を超えた数字に開き直り数は存在しない
  if(kosuu > 10){
    return;
  }
  //start~9までの数を新たに生成する
  for(i = start; i <= 9; i++){
    //新しい数を末尾に追加する
    number_using[i]++;
    //それが開き直り数になるかどうかのチェック
    CheckNumber();
    //追加した数の後ろにさらに1行追加した場合を調べる
    MakeNumbers(i, kosuu + 1);
    //先ほど追加した数を消す
    number_using[i]--;
  }
}

int main() {
  unsigned long i, j, k;
  //あらかじめべき乗数を計算してpower配列に保存する
  //0の0乗は0なので1から9まで計算すればいい
  for(i = 1; i <= 9; i++){
    k = 1;
    for(j = 0; j < i; j++){
      k *= i;
    }
    power[i] = k;
  }

  //1を１つ使うという条件から始める
  MakeNumbers(1, 1);

  return EXIT_SUCCESS;
}




/*僕が考えたアルゴリズム
開き直り数は表現に限界があるのでそこまででOK。
11桁以上の数字になるとすべての数を9にしても
足し合わせても元の桁数に戻らないのでもとめるのは10桁まででいい。

1　最初に10桁までの数字をすべて求める
2　それを分解して開き直り数をもとめる。
3　もとめた値と同じであれば開き直り数として認定する。

これじゃ重い。正直全然動かなかった。
開き直り数は数字の大きさではなく組み合わせで発生する。
だから3435が開き直り数なら同じ組み合わせの5334とか4353とかは開き直り数では
ないことになる。これが分からんないと絶望的。
*/
// #include <stdio.h>
// #include <stdlib.h>
//
// #define MAX_NUM 1000000000
// #define KETA 10
//
// int ret[KETA];
// int keta = 0;
// int stack_top = 0;
//
// /*リストのノードを表す構造体*/
// typedef struct tagListNode {
//   struct tagListNode *prev;  /*前のノードの参照ポインタ*/
//   struct tagListNode *next;  /*次のノードの参照ポインタ*/
//   int data;  /*このノードが持っているデータ*/
// } ListNode;
//
// /*リストによるスタック構造*/
// ListNode *firstnode = NULL;
// ListNode *lastnode = NULL;
//
// /*スタックへのpush*/
// void stack_push(int data){
//   ListNode *newnode;
//
//   /*新しい領域を確保*/
//   newnode = (ListNode*)malloc(sizeof(ListNode));
//   if(newnode == NULL){
//     printf("スタックオーバーフローです.メモリが足りません");
//     exit(EXIT_FAILURE);
//     return;
//   }
//
//   /*渡された値をスタックに積む*/
//   newnode->data = data;
//   stack_top++;
//
//   /*リストの最後に追加する*/
//   newnode->next = NULL;
//   if(lastnode != NULL) { /*すでにあるリストの末尾に新しいノードを繋げる*/
//     lastnode->next = newnode; /*最後のノードの次に新しいノードを追加する*/
//     newnode->prev = lastnode; //新しいノードをリストの最後と紐づける
//     lastnode = newnode; //新しいノードを既存のリストの最後にする
//     /*配列みたいに[]で区別しない。ノードのつながりをポインタで示すだけでOK*/
//   } else { /*これが最初の入力だった場合*/
//     firstnode = lastnode = newnode;
//     newnode->prev = NULL; //見ているのはアドレスなので、代入後変えても有効。
//   }
// }
//
// /*スタックからpop*/
// int stack_pop(void) {
//   ListNode *thisnode;
//   int ret;
//
//   ret = thisnode->data;
//   //対象の前結合を無くす．
//   if(thisnode->prev != NULL){ //先頭ノードではなければ
//     thisnode->prev->next = thisnode->next;
//   } else {
//     firstnode = thisnode ->next;
//   }
//
//   //対象の次結合を無くす
//   if(thisnode->next != NULL) {
//     thisnode->next->prev = thisnode ->prev;
//   }
//
//   free(thisnode); //メモリを解放
//   return ret; /*エラー*/
// }
//
// int num_of(unsigned int value) {
//   /*valueが0桁（もうこれ以上解析する桁がない）*/
//   if(value == 0){
//     return 0;
//   }
//   ret[keta] = value % 10;
//   keta++;
//
//   num_of(value / 10);
//   /*10で割って桁を一つずらし、再びnum_of_one()を調べる*/
//   return 0;
// }
//
// int main(){
//   int i, sum, j, k;
//   int cal[KETA];
//
//   for(i = 0; i < MAX_NUM ; i++){
//     /*数字を10で割ってあまりを求める。それで一桁ずつ分解する*/
//     num_of(i);
//     for(j = 0; j < k; j++){
//       cal[j] = ret[j] ^ ret[j];
//       sum += cal[j];
//     }
//
//     if(sum == i){
//       stack_push(sum);
//     }
//   }
//
//   printf("すべての開き直り数が求まりました。結果を表示します:\n");
//   for(i = 0; i < stack_top; i--){
//     printf("%d ", stack_pop());
//   }
//   return 0;
// }
