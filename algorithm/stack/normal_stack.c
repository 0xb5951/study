/*配列を用いたスタックのプログラム*/

#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX 10

/*double型のデータを格納するスタックを作成*/
double stack[STACK_MAX];

/*スタック頂上の位置(最下部からのオフセット)*/
int stack_top = 0;

/*スタックへpush*/
void stack_push(double val){
  if(stack_top == STACK_MAX){
    printf("エラー：スタックがいっぱいになっています\n");
    exit(EXIT_FAILURE);
  } else {
    stack[stack_top] = val;
    stack_top++;
  }
}

/*スタックからデータをpop*/
double stack_pop(){
  if(stack_top == 0){
    printf("エラー：スタックが空なのにpopが呼ばれました。\n");
    exit(EXIT_FAILURE);
  } else {
    stack_top--;
    return stack[stack_top];
  }
}

int main(){
  int buf;
  double val;

  do{
    printf("スタックへの命令を出してください:\n0.終了\n1.push\n2.pop");
    scanf("%d", &buf);
    printf("現在のスタック頂上の値:%d\n", stack_top);
    switch (buf) {
      case 0:
        break;
      case 1:
      printf("スタックしたい値を入力してください(double型):");
      scanf("%lf", &val);
      stack_push(val);
      break;
      case 2:
      printf("データのポップを行います。\n");
      val = stack_pop();
      printf("%d番目のデータは%lfです\n", stack_top, val);
      break;

      default:
      printf("入力された値は無効です");
    }
  }while(buf != 0);

  //ver1.0
  // do{
  //   if(buf == 1){
  //     printf("スタックしたい値を入力してください(double型):");
  //     scanf("%lf", &val);
  //     stack_push(val);
  //   } else if(buf == 2){
  //     printf("データのポップを行います。");
  //     val = stack_pop();
  //     printf("%d番目のデータは%lfです", stack_top, val);
  //   } else {
  //     printf("入力された操作は無効です");
  //   }
  // }while(buf != 0);

  return 0;
}
