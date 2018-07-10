//BM法で文字探索を行うプログラム
#include <stdio.h>
#include <stdlib.h>

#define PATTERN_LENGTH 4
unsigned char original_text[] = "On a dark desert highway, cool wind in my hair";
unsigned char original_pattern[PATTERN_LENGTH +1 ] = "wind";

#define _SHOW_WORKING_

unsigned char *bm_search(unsigned char* text, unsigned char *pattern) {
  // char型全体においてその文字で一致しなかった場合、どれだけ比較点を移動するかのテーブル
  int table[256];

  //本文とパターンの比較点
  int text_index, pattern_index, text_len, i;

  for(i = 0; i < 256; i++) { //たいていの文字は失敗した場合、patternの長さ分比較点をずらせばいい
    table[i] = PATTERN_LENGTH;
  }
  //この時点でテーブルの中はすべて４になっている。つまり、不一致なら4文字ずらすということ.


  // パターンに含まれている文字はその文字に合わせてずらす。
  // 同じ文字が2回以上ある場合は後方の文字を優先する
  for(i = 0;  i < PATTERN_LENGTH-1; i++){
    table[pattern[i]] = PATTERN_LENGTH - i - 1;
    //このpatten[i] はパターンの文字を10進数に直している。その文字にtableに番号を格納することでずらしかたを変えている.
    // printf("%d", pattern[i]);
  }

  //本文の長さを知る
  for(text_len = 0; text[text_len] != '\0'; ++text_len)
  ;

  //最初の比較点はテキストのパターン文字目から
  text_index = PATTERN_LENGTH -1;

  while(text_index < text_len) { //検索はテキストの長さ分行う
    #ifdef _SHOW_WORKING_
    // 分かりやすいようにいま何の検索位置を表示
    printf(" 本文：    %s \n パターン：", original_text);
    for(i = 0; i < text_index - PATTERN_LENGTH; i++){
      printf(" ");
    }
    printf("%s \n", pattern);
    #endif

    //パターンの後ろから比較を始める
    pattern_index = PATTERN_LENGTH - 1;
    while(text[text_index] == pattern[pattern_index]) {  //テキストとパターンを後ろから比較して一致した場合
      if(pattern_index == 0) { //パターンがすべて一致した場合
        return text+text_index; //テキストの先頭アドレスにindexの値を加えて、発見部を返す
      }

      //後ろから比較しているのでどっちも一つ戻す
      text_index--;
      pattern_index--;
    }

    //ここに来たら不一致が発生しているということ
    //よって必要な作業はBM法にのっとって検索場所を移動させること
    if(table[text[text_index]] > PATTERN_LENGTH - pattern_index) {  //検索を行っている文字のテーブル値 > パターンの長さから比較しているパターン文字の場所を引いたもの
      text_index += table[text[text_index]];  //検索している場所をその文字に対応するtableの値だけ移動させる
    } else {
      text_index += PATTERN_LENGTH - pattern_index;
    }
  }

  return NULL;
}

int main(){
  unsigned char* result;
  result = bm_search(original_text, original_pattern);
  if(result == NULL){
    printf("対象は見つかりませんでした。");
  } else {
    printf("対象を見つけました。");
  }

  return 0;
}
