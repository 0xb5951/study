/*
埋め立て
https://beta.atcoder.jp/contests/arc031/tasks/arc031_2

10マス×10マスの島国の地図が与えられるので、1マスを埋め立てたときに1つの島にできるか
判定する。ただし、地図で陸地を表すマスが上下左右についてつながってる領域のことを島という。

陸地が〇、海が×。

海を1マスだけ陸地にすることで全体を一つの島にできるならYES、
できないならNOを出力する。もとから一つの島だったらYESにする。
*/

/*深さ優先探索で解く
まずは〇が重なっている領域を検索。(上下左右でOK)
その後つながっていない部分に対して、〇を置く作業を行い、
つながればYES,すべてを行いつながらなければNOを返す。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF 100000000
#define FOR(i,a,n) for(i=(a);i<(n);i++)

int comp(const void* a,const void* b){
  return *(int*)a-*(int*)b;
}

void fill(int a[],int b,int c){
  int i;
  FOR(i,0,b) a[i]=c;
  return;
}

char map[10][11];
char s[10][11];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

//陸なら呼び出される関数
void dfs(int x,int y){
  int nx,ny,i;
  s[x][y] = 'x';

  //上下左右の陸を全部海にする
  FOR(i,0,4){
    nx=x+dx[i],ny=y+dy[i];
    if(nx >= 0 && ny>= 0 && nx < 10 && ny < 10 && s[nx][ny] == 'o'){
      dfs(nx,ny);
    }
  }

  return;
}

//条件分岐用の関数。これが１なら陸続きにできる
int check(){
  int cnt=0,i,j;

  //入力をｓにコピーする
  FOR(i,0,10) strcpy(s[i],map[i]);

  FOR(i,0,10){
    FOR(j,0,10){
      if(s[i][j] == 'o'){ //その場所が陸なら
        cnt++; //カウントアップ
        //つながっている〇をなくす
        dfs(i,j);
      }
    }
  }

  return cnt==1; //一回ですべてが海に代われば
}

int main(void)
{
  int i,j;

  //入力情報の読み込み
  FOR(i,0,10) scanf("%s",map[i]);

  FOR(i,0,10){
    FOR(j,0,10){
      if(map[i][j] == 'x'){ //その場所が海なら
        map[i][j] = 'o'; //陸に入れ替える

        //もしその場所を〇にしたことですべてがつながれば
        if( check() ){ //check関数がTrueなら
          puts("YES");
          return 0;
        }
        map[i][j] = 'x'; //もとの状態に戻す
      }
    }
  }


  puts("NO");
  return 0;
}
