/*キューを用いた簡単な計算のプログラム*/

#include <stdio.h>
#include <stdlib.h>

#define QUEUE_MAX (5+1) /*キューのサイズ+1*/
#define QUEUE_EMPTY -1

/*配列によるキューの構造*/
int queue[QUEUE_MAX];

/*キューの先頭位置を示す(配列先頭からのオフセット)*/
int queue_first = 0;
/*キューのしっぽ位置を示す（配列先頭からのオフセット*/
int queue_tail = 0;

/*キューにデータを追加する*/
void enqueue(int val){
  /*tailの次がfirstならば*/
  if((queue_tail + 1) % QUEUE_MAX == queue_first){
    /*配列の中身がすべてキューの要素で埋まっている*/
    printf("ジョブが満杯です\n");
    return;
  } else {
    /*キューに新しい値を入れる*/
    queue[queue_tail] = val;
    /*queue_tailを一つ後ろにずらす。一番後ろの場合は先頭に持ってくる*/
    queue_tail = (queue_tail + 1) % QUEUE_MAX;
  }
}

/*キューからデータを取り出す*/
int dequeue(){
  int ret;

  if(queue_first == queue_tail){
    /*現在キューには何もない*/
    return QUEUE_EMPTY;
  } else {
    /*一番先頭のキューを返す準備*/
    ret = queue[queue_first];
    /*キューの先頭を次に移動する*/
    queue_first = (queue_first + 1) % QUEUE_MAX;
    return ret;
  }
}

/*キューの全内容を表示する*/
void queue_print(){
  int i;
  for(i = queue_first; i != queue_tail; i = (i + 1) % QUEUE_MAX){
    printf("%d ", queue[i]);
  }
}

int main(){
  int i, j;

  do{
    printf("現在のキュー:");
    queue_print();
    printf("\nコマンド 0:終了 1:ジョブをためる 2:ジョブを実行\n>");
    scanf("%d", &i);

    switch(i){
      case 1:
      printf("ジョブの識別番号(1～1000)を適当に入力してください:");
      scanf("%d", &j);

      if(j >= 1 && j <= 1000){
        enqueue(j);
      }
      break;
      case 2:
      j = dequeue();
      if(j == QUEUE_EMPTY){
        printf("ジョブがありません\n");
      } else {
        printf("識別番号%dのジョブを実行中...\n", j);
      }
      break;
      default:
      printf("入力された値は無効です");
      break;
    }
  }while(i != 0);

  return EXIT_SUCCESS;
}
