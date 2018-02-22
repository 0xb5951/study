/*リストのサーチプログラム*/

#include <stdio.h>
#include <stdlib.h>

/*リストのノードを表す構造体*/
typedef struct tagListNode{
  struct tagListNode *prev; /*前の要素へのポインタ*/
  struct tagListNode *next; //次のノードへのポインタ
  int data; /*このノードが持っているデータ*/
} ListNode;

int main(){
  int buf;
  ListNode *firstnode, *lastnode, *newnode, *thisnode, *removenode;

  firstnode = lastnode = NULL;

  do{
    printf("整数を入力してください（0を入力すると終了）:");
    scanf("%d", &buf);

    if(buf){ /*新たな入力があったら*/
      /*新しいノードを作成*/
      newnode = (ListNode*)malloc(sizeof(ListNode));
      newnode->data = buf;
      newnode->next = NULL;

      if(lastnode != NULL){
        lastnode->next = newnode;
        newnode->prev = lastnode;
        lastnode = newnode;
      } else { /*最初のノードをなら*/
        firstnode = lastnode = newnode;
        newnode->prev = NULL;
      }
    }
  }while(buf != 0);

  /*検索値を入力*/
  do{
    printf("検索する値を入力してください");
    scanf("%d", &buf);

    if(buf != 0){
      //最初に入力した値の中から検索し、見つかったら削除
      for(thisnode = firstnode; thisnode != NULL; thisnode = thisnode->next) {
        if(thisnode->data == buf){
          printf("入力されたデータの中に%dが見つかりました。ノードを削除します.",buf);

          if(thisnode->prev != NULL){ //先頭ノードではなければ
            thisnode->prev->next = thisnode->next;
          } else {
            firstnode = thisnode ->next;
          }

          if(thisnode->next != NULL) {
            thisnode->next->prev = thisnode ->prev;
          }

          free(thisnode);
          break;
        }
      }

      if(thisnode == NULL){
        printf("%dは入力されていないか、あるいはすでに削除されています。", buf);
      }
    }
  }while(buf != 0);

  /*残ったノードはすべて削除*/
  for(thisnode = firstnode; thisnode != NULL;){
    removenode = thisnode;
    thisnode = thisnode->next;
    free(removenode);
  }

  return EXIT_SUCCESS;
}
