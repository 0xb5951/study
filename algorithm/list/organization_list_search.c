/*リストを用いた自己組織化探索のプログラム*/

#include <stdio.h>
#include <stdlib.h>

/*リストのノードを表す構造体*/
typedef struct tagListNode{
  struct tagListNode *next; /*次の要素へのポインタ*/
  int data; /*この要素が持っているデータ*/
} ListNode;

int main(){
  int buf;
  ListNode *firstnode, *lastnode, *thisnode, *newnode, *removenode;

  srand((unsigned int)time(NULL));

  firstnode = lastnode = NULL;

  /*ユーザーからの入力を受け付けて，リスト化*/
  do {
    printf("整数を入力してください(0を入力すると終了):");
    scanf("%d", &buf);

    if(buf){ /*新たな入力があったら*/
      newnode = (ListNode*)malloc(ListNode);
      newnode->data = buf;
      newnode->next = NULL;

      if(lastnode != NULL){ //既存のリストがある場合
        lastnode->next = newnode;
        lastnode = newnode;
      } else {
        firstnode = lastnode = newnode;
      }
    }
  }while(buf != 0);

  /*ユーザからの入力リストをソートして，見つかると一番前に持ってくる*/
  do{
    printf("現在の並び:\n");
    for(thisnode = firstnode; thisnode != NULL;thisnode = thisnode->next){
      printf("%d\t", thisnode->data);
    }

    /*検索値を入力*/
    printf("検索したい値を入力してください(0を入力すると終了):");
    scanf("%d", &b)
  }
}
