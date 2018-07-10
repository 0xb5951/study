// 単純に文字列の先頭から比較していく文字列検索プログラム

#include <stdio.h>
#include <stdlib.h>

unsigned char original_text[] = "Team Swift";
unsigned char original_pattern[] = "if";

#define _SHOW_WORKING_

unsigned char* simple_search(unsigned char* text, unsigned char *pattern) {
  int i;

  while((*text) != '\0') {
    #ifdef _SHOW_WORKING_
    // 分かりやすいようにいま何の検索位置を表示
    printf(" 本文：    %s \n パターン：", original_text);
    for(i = 0; i < text - original_text; i++){ //iがtext-original_textよりも小さい
// ここでtextとoriginal_textはどちらもchar型のポインタである
      printf(" ");
    }
    printf("%s \n", pattern);
    printf("%d \n", original_text);
    printf("%d \n", text);
    #endif

    //ifdef 識別子がdefineされていたら処理を実行。endifで囲う.
    // printf("%d", text+2 - original_text);
    //配列はポインタで計算される。ポインタ変数の演算はポインタに格納されているアドレスに
    //変数のサイズ分変更を加える。

    // この場合は文字列が格納されている先頭アドレスとポインタで動かすアドレスで比較している。


    // パターンの先頭から比較を始める
    for(i = 0; pattern[i] != '\0'; i++){
      if(pattern[i] != text[i]){
        break;
      }
    }
    if(pattern[i] == '\0'){
      return text;
    }

    text++;
  }

  return NULL;
}

int main(){
  unsigned char* result;
  result = simple_search(original_text, original_pattern);
  if(result == NULL){
    printf("対象は見つかりませんでした。");
  } else {
    printf("対象を見つけました。");

  }
}
