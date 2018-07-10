/*
派閥
Atcoder国には高橋君を除いてN人の国会議員とM個の人間関係(x,y)が存在する。
人間関係とは議員xと議員yが知り合いであることを意味する。
高橋君はN人の中から何人かを選んで派閥を作ろうとしている。
派閥に含まれるすべての議員は互いに知り合いでないといけない。
作成することのできる最大派閥に属する議員数を求めろ。
*/

/*bit全探索で解く*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
  int n, m;
  int i, j;
  int relation[2] = {0};
  unsigned int friends[12] = {0};
  int answer = 1;
  int member = 0;
  int digit;

  scanf("%d %d", &n, &m);

  for (i = 0; i < m; i++){ //すべての知り合い関係を列挙
    scanf("%d %d", &relation[0], &relation[1]); //それぞれに入力
    friends[relation[0]-1] += pow(2, relation[1]-1); //それぞれの議員に関係を与える
    friends[relation[1]-1] += pow(2, relation[0]-1);
    //それぞれの議員に他の議員との関係配列を与える
    //議員番号を二の累乗にすることでフラグを管理
  }

  for (i = 1; i < (1 << n); i++){ //bit全探索
    digit = 0;
    member = 0;
    for (j = 1; j < 1 << n; j = j << 1){ //bit桁ごとに調べる
      if ((i & j) == j && ((friends[digit] + (int)pow(2, digit))& i) == i){
        //その桁にフラグが立っていたら　かつ　
        member++;
      }
      digit++;
    }
    answer = answer>member?answer:member;
  }

  printf("%d\n", answer);

  return 0;
}
