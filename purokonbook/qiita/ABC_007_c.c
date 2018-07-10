/*
幅優先探索
迷路が与えられるので、迷路を解くのに必要な最小移動手段を求める。
これを幅優先探索で実装する。

・スタート地点を0と置き、そこから迷路を移動するのにかかるコストを書いていく。
隣接しているマスを順番に見ていく。

・これを実装するにはキューを用いるのが効率的。

迷路用配列とコスト保存用配列を用意して、そこにキューを使う。
*/

#include <stdio.h>
#include <memory.h>

typedef struct{
  int x,y;
}queue;

int main(void){
  int r,c;
  int sy,sx,gy,gx
  int i,head, tail;
  int dy[4]={1,-1,0,0},dx[4]={0,0,1,-1},f[50][50];

  char m[50][50];
  queue q[100000];

  //コスト保存用
  memset(f,-1,sizeof(f));//f[50][50]に-1をセットしている

  //キューを初期化
  memset(q,0,10000); //q[100000]に0をセットしている

  scanf("%d %d",&r,&c); //行　列
  scanf("%d %d",&sy,&sx);//スタート地点
  scanf("%d %d",&gy,&gx);//ゴール地点

  for(i=0;i<r;i++){
    scanf("%s",&m[i]);
  }

  r--;c--;sy--;sx--;gy--;gx--;//配列の添え字と対応させるために数値を1引く
  head=tail=0;//headとtailは0

  //キューにスタート地点を記憶
  q[head].y=sy;//q[head]のyはsyの座標が入る
  q[head].x=sx;//q[head]のxはsxの座標が入る

  //コストを保存する
  f[sy][sx]=0;//スタート地点のコストは0

  while(q[head].x != 0){//q[head].xが!=0の間繰り返す
    //一つ前の場所のコストを取り出す
    int ty=q[head].y;
    int tx=q[head].x;

    //キューの先頭を一つずらす
    head++;

    for(i=0;i<4;i++){
      int ny=ty+dy[i];
      int nx=tx+dx[i];

      //上下左右を確認
      //その場所が空白で、コストが-1なら（測定前なら）
      if(m[ny][nx]=='.' && f[ny][nx]==-1){
        //前の場所から1を足す
        f[ny][nx] = f[ty][tx] + 1;
        tail++;
        //新しい場所をキューに追加する
        q[tail].y=ny;
        q[tail].x=nx;
      }
    }

  }
  printf("%d\n",f[gy][gx]);
  return 0;
}
