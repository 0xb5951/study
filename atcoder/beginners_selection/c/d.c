/*黒板に N 個の正の整数 A1,…,AN が書かれています．

すぬけ君は，黒板に書かれている整数がすべて偶数であるとき，次の操作を行うことができます．

黒板に書かれている整数すべてを，2 で割ったものに置き換える．
すぬけ君は最大で何回操作を行うことができるかを求めてください．
*/

/*
Q. スペースで区切った入力をどんな風にうけとうるか

A.一行読み取ってスペースで区切ればいい
char *fgets(char *s, int n, FILE *fp);　一行読み取る

第一引数は文字配列のポインタ
第二引数は一行の最大文字数
第三引数はファイルポインタ　標準入出力のときはstdin


char *strtok(char *s1, const char *s2); 文字列を区切りで分解する

s1 : 分割対象
s2 : 区切る文字

文字列の中に区切り文字が複数ある場合は、2回目以降は第一引数をNULLにして実行すると、
戻り値がNULLになるまで、トークンのポインタが返ってきます。

*/

#include<stdio.h>

/*見たあと*/
int main() {
  int n,i = 0;
  int a[200] = {0};
  int count,flag = 0;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  while(1){
    flag = 0;
    for(i = 0; i < n; i++){
      if(a[i] % 2 == 0){
        a[i] = a[i] /2;
        flag++;
      }
    }

    if(flag != n) {break;}
    count++;
  }

  printf("%d\n", count);

}

/*見る前
int main() {
int n,i = 0;
int count,flag = 0;

//入力される数
scanf("%d", &n);

//必要な分だけ確保
int a[n];
char buf[256];

while(flag != 1) {
for(i = 0; i < n; i++){
if(count == 0){
fgets(buf, n*2, stdin);
a[0] = strtok(buf, " ");
do{
a[++i] = strtok(NULL, " ");
} while( (i < n) && (a[i] != NULL))
}

if(a[i] % 2 == 1){
flag = 1;
break;
}
a[i] = a[i] /2;
}
count++;
}
return 0;
}*/
