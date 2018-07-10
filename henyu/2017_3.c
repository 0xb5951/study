/*
筑波大学情報メディア創生学類の2017年問題。
structについて問われている.

試験結果（数学、英語）の結果を成績順に出力するプログラム。
(1)print_tableは一行ごとに数学の点数、の低い順の順位、
学籍番号、数学、英語の点数を出力する関数である。これを完成させろ
*/

/*書いてある部分*/
#include <stdio.h>

#define N 1024 //扱える最大の範囲

struct item{
  char id[8];
  int math;
  int eng;
};

// int int main(int argc, char const *argv[]) {
//
//   struct item table[N]; //成績が格納される配列
//   int rank[N]; //順位に従って、tableの添え字が格納される配列
//   int size = N;
//   make_ranking(size, rank, table);
//   print_table(size, rank, table);
//   return 0;
// }

//構造体の型宣言
struct OLD {
  int no;        //番号
  char *name;    //名前
  int s_year;    //年
  char s_class;  //クラス
};

void print_table0(int size, struct OLD old[]){
  int i;
  for(i = 0; i < size; i++){
    printf("%7d%15s%5d%10c\n", old[i].no, old[i].name, old[i].s_year, old[i].s_class);
  }
}

int main()
{
  int i = 0;
  printf("学籍番号\t 名前\t学年\tクラス\n");

  //構造体の初期化
  struct OLD old[15] =
  {
    { 1,"上杉謙信"    ,3,'A'},
    { 2,"武田信玄"    ,3,'A'},
    { 3,"豊臣秀吉"    ,3,'A'},
    { 4,"明智光秀"    ,3,'A'},
    { 5,"織田信長"    ,3,'A'},
    { 6,"徳川家康"    ,3,'A'},
    { 7,"聖徳太子"    ,3,'A'},
    { 8,"マッカーサー",3,'A'},
    { 9,"ザビエル"    ,3,'A'},
    {10,"北条政子"    ,3,'A'},
    {11,"沖田総司"    ,3,'A'},
    {12,"永倉新八"    ,3,'A'},
    {13,"斉藤一"      ,3,'A'},
    {14,"松原忠治"    ,3,'A'},
    {15,"武田観柳斎"  ,3,'A'},
  };

  print_table0(15, old);
  return 0;
}
