/*
問題文
いろはちゃんは 長さ L の文字列を N 個持っており、それぞれ S1,S2,…,SN です。

それらの文字列を好きな順番で全て結合してできる文字列のうち、もっとも辞書順で小さいものを求めてください。

なお、ある文字列 s=s1s2s3...sn と t=t1t2t3...tm について、以下のどちらかを満たすとき、辞書順比較で s<t であるといいます。

ある整数 i(1≦i≦min(n,m)) に関して、 1≦j<i を満たす任意の整数 j において sj=tj が成立し、かつ si<ti が成立する。
任意の整数 i(1≦i≦min(n,m)) に関して si=ti が成立し、かつ n<m が成立する。
制約
1≦N,L≦100
全ての i(1≦i≦N) に対し、Si の長さは L に等しい。
各 i について, Si は全て半角英小文字のみから成る文字列である。
入力
入力は以下の形式で標準入力から与えられる。

N L
S1
S2
:
SN
出力
与えられる文字列を好きな順番で全て結合してできる文字列のうち、もっとも辞書順で小さいものを出力せよ。
*/

#include <stdio.h>
#include <string.h>

int main() {
  int n,l;
  int i,j = 0;
  char input[101][101];
  char temp[101];

  scanf("%d %d", &n, &l);

  for(i = 0; i < n; i++){
    scanf("%s", input[i]);
    // printf("%s", input[i]);
  }

  for(j = 0;j < n; j++){
    for(i = 0; i < n; i++){
      // if(input[i] > input[i+1]){
      if(strcmp(input[i], input[i+1]) >= 1){
        strcpy(temp, input[i+1]);
        strcpy(input[i+1], input[i]);
        strcpy(input[i], temp);
      }
    }
  }

  for(i = 0; i <= n;i++){
    printf("%s", input[i]);
  }

  return 0;
}
