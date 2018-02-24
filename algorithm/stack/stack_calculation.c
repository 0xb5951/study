/*スタックを用いた計算の例
以下のような手順で計算を行う
1.数字が表れたらその数字をスタックに積む
2.演算子が現れたら，スタックの上から2つの数字を取り出して演算子に対応した
加減乗除を行い，その結果をスタックに積む.
入力例
30 50 + 4 12 + / = (30 + 50) / (4 + 12)
*/

#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX 10

/*配列によるスタック配列*/
double stack[STACK_MAX];

/*スタック頂上の位置(最下部からのオフセット)*/
int stack_top = 0;

/*スタックへのpush*/
void stack_push(double val){
  if(stack_top == STACK_MAX){
    printf("エラー:スタックが満杯になっています\n");
    exit(EXIT_FAILURE);
  } else {
    stack[stack_top] = val;
    stack_top++;
  }
}

/*スタックからpop*/
double stack_pop(){
  if(stack_top == 0){
    /*スタックには何もない*/
    printf("エラー：スタックが空なのにpopが呼び出されました");
    exit(EXIT_FAILURE);
    return 0;
  } else {
    /*一番上の値を返す*/
    stack_top--;
    return stack[stack_top];
  }
}

int main(){
  char buffer[256];
  double cal1, cal2;
  int i;

  do {
    printf("現在のスタック(%d):" stack_top);
    for(i = 0; i < stack_top; i++){
      printf("%0.3f", stack[i]) //現在のスタック状態を表示
    }

    printf("\n>");
    gets(buffer);
    /*gets: 標準入出力からの文字列入力
    キーボードからの1行の入力を読み込み()内の変数に格納
    ただgets()は配列に書き込む最大サイスを指定できないためあまり使用しない方がいい
    この例255文字以上の入力が発生するとバッファオーバーランを起こしてしまう*/
    switch(buffer[0]){
      case '+':
      cal1 = stack_pop();
      cal2 = stack_pop();
      stack_push(cal2 + cal1);
      break;
      case '-':
      cal1 = stack_pop();
      cal2 = stack_pop();
      stack_push(cal2 - cal1);
      break;
      case '/':
      cal1 = stack_pop();
      cal2 = stack_pop();
      stack_push(cal2 / cal1);
      break;
      case '*':
      cal1 = stack_pop();
      cal2 = stack_pop();
      stack_push(cal2 * cal1);
      break;
      case '=':
      /*＝の場合はすぐにwhile分から抜けるようにしておく*/
      break;
      default:
       /*数字が入力されているはずなのでスタックに積む*/
       stack_push(atoi(buffer));
       break;
    }

  }while(buffer != '=');

  printf("計算結果は%fです\n", stack_pop());
  if(stack_top != 0){
    printf("まだスタックに数字が残っています\n");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
