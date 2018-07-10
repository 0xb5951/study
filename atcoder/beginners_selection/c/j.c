/*
問題文
英小文字からなる文字列 S が与えられます。 Tが空文字列である状態から始め、以下の操作を好きな回数繰り返すことで S=T とすることができるか判定してください。

T の末尾に dream dreamer erase eraser のいずれかを追加する。
制約
1≦|S|≦105
S は英小文字からなる。
入力
入力は以下の形式で標準入力から与えられる。

S
出力
S=T とすることができる場合 YES を、そうでない場合 NO を出力せよ。
*/

/*必要な機能
dream, dreamer,erase, eraserを組み合わせて文字を作る。

それとテキストが一致しているか確かめる
*/
#include <stdio.h>
#include <string.h>

//文字列の定義
char date[4][8] = {"dream","dreamer", "erase", "eraser"};

void run(){
  char text[10001];
  int l,index;
  int len[4] = {5,7,5,6};
  int i,j;

  scanf("%s", &text);
  l = strlen(text);

  while(l < 0){
    for(i = 0; i < 4; i++){
      for(j = len[i] -1; j >= 0 && date[i][j] == text[l -len[i] + j]; j--)
      if(j < 0){
        l -= len[i];
        break;
      }
      if(i == 4){
        printf("NO\n");
        return;
      }
    }
    printf("YES");
    return;
  }

}


int main() {
  run();
  return 0;
}
