#include <stdio.h>
#include <stdlib.h>

#define PATTERN_LENGTH 13
unsigned char original_text[] = "a eighty-eighty-eighth key";
unsigned char original_pattern[PATTERN_LENGTH+1] = "eighty-eighth";

#define _SHOW_WORKING_

unsigned char *kmp_search(unsigned char *text, unsigned char *pattern) {
  int table[PATTERN_LENGTH + 1] = {0,0}; //不一致が出た場合のずらす量を保存する配列
  int text_index = 1, pattern_index = 0; //パターンのずらし方を比較する変数　
  int i = 0, j;

  //まずkmpの探索に必要な情報を集め、テーブルとして保存する = 不一致だったときのずらす量を保存
  while((pattern[text_index]) != '\0'){  //パターンをすべて比較するまで
    if(pattern[text_index] == pattern[pattern_index]) { //パターンの中で一致したら
      table[++text_index] = ++pattern_index; //テーブルの値にずらす数字を格納
    } else if(pattern_index == 0) { //一文字目が不一致だったとき
      table[++pattern_index] = 0; //そこは一文字ずらすだけ
    } else {  // パターン一文字目以外で不一致ならば再検索の位置はtableから参照
      pattern_index = table[pattern_index];
    }
  }
  //以上でテーブルが完成。実際の検索にとりかかる

  while((*text) != '\0') {
    #ifdef _SHOW_WORKING_
    // 分かりやすいようになにを比較しているか表示
    printf("本文:      %s \nパターン:", original_text);
    for(j = 0; j< text - original_pattern; j++){
      printf(" ");
    }
    printf("%c \n", pattern[i]);
    #endif

    if((*text) == pattern[i]) {  //テキストとパターンが一致していれば１字ずつ比較を続ける
      text++;
      if(pattern[++i] == '\0') {          //すべて一致すれば正解
        return text - PATTERN_LENGTH;
      }
    }
    else if(i == 0) {        //パターン最初の文字で失敗した場合は比較場所を１つすすめる
      text++;
    } else {  //最初の文字でない場合はテーブルから比較位置を取得する
      i = table[i];
    }
  }

  return NULL;
}

int main() {
  unsigned char *result;
  result = kmp_search(original_text, original_pattern);
  if(result == NULL) {
    printf("見つかりませんでした\n");
  } else {
    printf("見つかりました");
  }

  return 0;
}
