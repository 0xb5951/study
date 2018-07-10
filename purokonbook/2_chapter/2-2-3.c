/*辞書順最小の問題
N文字の文字列Sが与えられ、N文字の文字列Tを作る。Tは長さ0で次の操作が可能。
1.Sの先頭の１文字を削除し、Tの末尾に追加する
2.Sの末尾の1文字を削除し、Tの末尾に追加する

この状況で辞書順比較でできるだけ小さくなるようにTを作る
*/

/*
辞書順比較においてTの後方がどんなに悪くても前の方がよければOK。
よって貪欲法のアルゴリズムとして採用するルールは以下のことが考えられる。
・Sの先頭と末尾、どちらかのより小さい文字をTの末尾に付け加える。

しかし、Sの先頭と末尾が同じ文字の場合が定義されていない。
この場合、次の文字ができるだけいい文字を使うようにしたい。
次のようなアルゴリズムを採用する
・SとSを反転させた文字列S’を辞書順比較する
・Sが小さいのであれば、Sの先頭を削除する
・S'が小さいのであれば、Sの末尾を削除する
*/

#include <stdio.h>

int main(){
  int N;
  char s[2001];
  int bottom, top;
  int i;

  scanf("%d", &N);

  scanf("%s", s);

  bottom = 0;
  top = N - 1;

  while(bottom <= top){
    int left = 0;
    for(i = 0; bottom + i <= top; i++) { //ここでfor文を使うのは同じ文字だった時用
      if(s[bottom + i] < s[top - i]){
        left = 1;
        break;
      }
      else if(s[bottom + i] > s[top - i]){
        left = 0;
        break;
      }
    }

    if (left) putchar(s[bottom++]);
    else putchar(s[top--]);
  }

  // printf("%s", s);
  putchar('\n');

  return 0;
}
