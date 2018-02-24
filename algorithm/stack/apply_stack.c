/*カッコの対応を調べるプログラム
標準入力から与えられたテキストの中身を調べカッコの対応を調べる。*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*カッコの種類*/
#define STAPLE_SMALL  1
#define STAPLE_MEDIUM 2
#define STAPLE_LARGE  3

/*１つのカッコを示す構造体*/
typedef struct _tagstaple {
  int line; //カッコのある行
  int column; //カッコのある行（行頭からの文字数）
  int type; //カッコの種類

  /*リストによるスタック構造*/
  struct _tagstaple *staple_next;
  struct _tagstaple *staple_prev;
} staple;

/*リストによるスタック構造*/
staple *staple_head = NULL;
staple *staple_last = NULL;

/*スタックへのpush*/
void stack_push(int line, int column, int type){
  staple *staple_new;

  /*新しい領域を確保*/
  staple_new = (staple*)malloc(sizeof(staple));
  if(staple_new == NULL){
    printf("スタックオーバーフローです.メモリが足りません");
    exit(EXIT_FAILURE);
    return;
  }

  /*渡された値をスタックに積む*/
  staple_new->line = line;
  staple_new->column = column;
  staple_new->type = type;

  /*リストの最後に追加する*/
  staple_new->staple_next = NULL;
  staple_new->staple_prev = staple_last;
  staple_last = staple_new; //値を代入
  if(staple_head == NULL){
    staple_head = staple_new;
  }
}

/*スタックからpop*/
int stack_pop(staple *ret) {
  staple *temp_staple;

  if(staple_head == NULL){
    /*スタックに何もない:カッコの対応がとれていない*/
    return 0; /*エラー*/
  }

  /*一番最後にpushされたカッコの情報を返す*/
  ret->line = staple_last->line;
  ret->column = staple_last->column;
  ret->type = staple_last->type;
  ret->staple_next = ret->staple_prev = NULL;
  temp_staple = staple_last;

  /*リストから削除する*/
  if(staple_last->staple_prev == NULL) {
    staple_head = NULL;
  } else {
    staple_last->staple_prev->staple_next = NULL;
  }

  staple_last = staple_last->staple_prev;

  free(temp_staple);

  return 1; /*成功*/
}

int main(){
  char buffer[4096];
  int i, len, line = 1, carryover = 0;
  staple open;

  for(;;){
    if(fgets(buffer, 4096, stdin) == NULL) {
      /*fgets:ファイルから文字列を一行取得してくれる関数
      char *fget(読み取ったデータを格納する配列、最大読み取りバイト数、ファイルポインタ);
      ファイルポインタをstdinとすると標準入力を指定できる。
      */
      /*終端まで読み込んだ*/
      break;
    }
    len = strlen(buffer); //文字列のサイズを取得
    if(len == 0){
      continue;
    }

    for(i = 0; i < len; i++){　//バッファの長さまで
      switch (buffer[i]) {
        case '(':
        stack_push(line, carryover+i+1, STAPLE_SMALL);
        break;
        case '{':
        stack_push(line, carryover+i+1, STAPLE_MEDIUM);
        break;
        case '[':
        stack_push(line, carryover+i+1, STAPLE_LARGE);
        break;
        case ')':
        if(stack_pop(&open) == 0) {
          printf("カッコの対応がとれていません\n");
          printf("%d行列%d文字に対応する開きカッコがありません\n", line, carryover+i+1);
          return EXIT_FAILURE;
        }
        if(open.type != STAPLE_SMALL) {
          printf("カッコの対応がとれていません\n");
          printf("%d行%d文字に対応するカッコと"
                 "%d行%d文字に対応するカッコの種類が違います", open.line, open.column, line, carryover+i+1);
          return EXIT_FAILURE;
        }
        break;
        case '}':
        if(stack_pop(&open) == 0) {
          printf("カッコの対応がとれていません\n");
          printf("%d行%d文字に対応するカッコの種類がありません", line, carryover+i+1);
          return EXIT_FAILURE;
        }
        if(open.type!=STAPLE_MEDIUM) {
          printf("カッコの文字と対応がとれていません\n");
          printf("%d行%d文字目に対応するカッコと%d行%d文字目"
                 "に対応するカッコの種類が違います\n", open.line, open.column, line, carryover+i+1);
          return EXIT_FAILURE;
        }
        break;
        case ']':
        if(stack_pop(&open) == 0) {
          printf("カッコの対応がとれていません\n");
          printf("%d行%d文字に対応するカッコの種類がありません", line, carryover+i+1);
          return EXIT_FAILURE;
        }
        if(open.type!=STAPLE_LARGE) {
          printf("カッコの文字と対応がとれていません\n");
          printf("%d行%d文字目に対応するカッコと%d行%d文字目"
                 "に対応するカッコの種類が違います\n", open.line, open.column, line, carryover+i+1);
          return EXIT_FAILURE;
        }
        break;
      }
    }

    if(buffer[len - 1] == '\n'){ //列の最後が改行なら
      carryover = 0; //何文字目かの情報をリセット
      line++; //行情報をプラス
    } else {
      /*4096文字読み込んでも改行に出会わなかった場合*/
      carryover += len;
    }
  }

  /*完全にカッコの対応が取れていればスタックは空になっているはず*/
  if(staple_head != NULL){
    /*開きカッコが多い*/
    printf("カッコの対応が取れていません\n");
    printf("開きカッコの数が多すぎます\n");
    return EXIT_FAILURE;
  }

  printf("カッコの対応は正しくとれています\n");
  return EXIT_SUCCESS;
}
