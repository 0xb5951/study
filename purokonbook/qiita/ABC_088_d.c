/*
Grid repainting
縦H、横Wのマス目。
ゲームの開始時点に（1,1）にプレーヤーがいる。
このプレーヤーは上下左右に動くことができる。白いマスだけを通って右下まで行く。

ただし、ゲームが開始する前にいくつかのマスの色を変えることができる。
黒から白に変更した数がゲームのスコアとなる。
最大スコアを獲得しろ。
*/

/*最短路を計算し、それ以外の白を黒にすればOK*/

#include<stdio.h>
#include<string.h>

char map[51][51];
int next[4][2]={0,1,1,0,0,-1,-1,0};
int book[51][51],h,w,head,tail,flag;

struct {
  int x,y;
  int step;
}que[2501];

void bfs(int x,int y);

int main(){

  int i,j,sum=0;
  head=1;
  tail=1;

  que[head].x=1;
  que[head].y=1;
  que[head].step=0;

  tail++;

  //開始地点を探索済みにする
  book[1][1]=1;


  scanf("%d%d",&h,&w);

  for(i = 1;i <= h; i++){
    getchar();
    for(j=1;j<=w;j++)
    {
      scanf("%c",&map[i][j]);
      //白の場所をカウントアップ
      if(map[i][j]=='.')
      sum++;
    }
  }

  sum -= 1;
  bfs(1,1);

  if(flag==0)
  printf("-1\n");
  else
  printf("%d\n",sum-que[tail-1].step);

  return 0;
}

void bfs(int x,int y){

  int i,tx,ty;

  //キューが終わるまで
  while(head<tail){

    for(i=0;i<4;i++){

      //その場所から上下左右を調べる
      tx= que[head].x + next[i][0];
      ty= que[head].y + next[i][1];

      //範囲外なら無視
      if(tx<1||tx>h||ty<1||ty>w) continue;

      //その場所が白で探索前なら
      if(map[tx][ty]=='.' && book[tx][ty]==0){

        //キューにその場所を追加
        que[tail].x=tx;
        que[tail].y=ty;
        que[tail].step=que[head].step+1;
        tail++;

        //その場所を探索済みに
        book[tx][ty]=1;
      }

      //もしゴールなら
      if(tx == h && ty == w){
        flag=1;
        break;
      }
    }

  //ゴールしたら終了
  if(flag==1)
    break;
    head++;
  }

  return;
}
