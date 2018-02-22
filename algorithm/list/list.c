#include <stdio.h>
#include <stdlib.h>

/*リストのノードを表す構造体*/
typedef struct tagListNode {
  struct tagListNode *prev;  /*前のノードの参照ポインタ*/
  struct tagListNode *next;  /*次のノードの参照ポインタ*/
  int data;  /*このノードが持っているデータ*/
} ListNode;

int main(){
  int buf,sum;
  ListNode *firstnode, *lastnode, *newnode, *thisnode, *removenode;

  firstnode = lastnode = NULL;

  do{
    printf("整数を入力してください（0を入力すると終了）:");
    scanf("%d", &buf);
    if(buf){ /*新たな入力があったら*/
      /*新しいノードを作成*/
      newnode = (ListNode*)malloc(sizeof(ListNode)); /*新しいノードのメモリを確保*/
      newnode->data = buf; /*値を入力*/
      newnode->next = NULL; /*新しいノードは既存のリストの最後に追加するので、その次のノードはNULL*/

      if(lastnode != NULL) { /*すでにあるリストの末尾に新しいノードを繋げる*/
        lastnode->next = newnode; /*最後のノードの次に新しいノードを追加する*/
        newnode->prev = lastnode; //新しいノードをリストの最後と紐づける
        lastnode = newnode; //新しいノードを既存のリストの最後にする
        /*配列みたいに[]で区別しない。ノードのつながりをポインタで示すだけでOK*/
      } else { /*これが最初の入力だった場合*/
        firstnode = lastnode = newnode;
        newnode->prev = NULL; //見ているのはアドレスなので、代入後変えても有効。
      }
    }
  }while(buf != 0);

  /*合計値を算出*/
  printf("--入力されたのは以下の数です--\n");
  sum = 0;
  for(thisnode = firstnode; thisnode != NULL; thisnode = thisnode->next){
    printf("%d\t", thisnode->data);
    sum += thisnode->data;
  }
  printf("\n----\n以上の数の合計値は%dです.", sum);

  /*リストの全ノードを削除*/
  for(thisnode = firstnode; thisnode != NULL;){
    removenode =thisnode;
    thisnode = thisnode->next;
    free(removenode);
  }

  return EXIT_SUCCESS;
}
