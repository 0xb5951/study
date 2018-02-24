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
  ListNode *firstnode, *lastnode, *thisnode, *newnode, *tmpnode;


  firstnode = lastnode = NULL;

  /*ユーザーからの入力を受け付けて，リスト化*/
  do {
    printf("整数を入力してください(0を入力すると終了):");
    scanf("%d", &buf);

    if(buf){ /*新たな入力があったら*/
      newnode = (ListNode*)malloc(sizeof(ListNode));
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
    printf("\n検索したい値を入力してください(0を入力すると終了):");
    scanf("%d", &buf);

    if(buf != 0){
      /*最初に入力した値の中から検索*/
      for(thisnode = firstnode; thisnode != NULL;
        tmpnode = thisnode, thisnode = thisnode->next){
          if(thisnode->data == buf) {
            printf("入力された値の中に%dが見つかりました。\n", buf);

            //見つかった値を先頭に持ってくる
            if(thisnode != firstnode){ //ノードが先頭じゃないとき
              tmpnode->next = thisnode->next; //thisnodeを一つ次に移す。

              if(lastnode == thisnode) { //このノードが最後のノードの場合。
                lastnode = tmpnode; //このノードをlasrnodeにする
              }

              thisnode->next = firstnode;
              firstnode = thisnode;
            }
            break;　//値が見つかればfor文を抜ける
          }

        }
        if(thisnode == NULL){
          printf("%dは入力されていませんでした。\n", buf);
        }
      }
    }while(buf != 0);

    thisnode = firstnode;
    while(thisnode != NULL){ //対象がもと合った場所を消去
      tmpnode = thisnode->next;
      free(thisnode);
      thisnode = tmpnode;
    }

    return EXIT_SUCCESS;
  }
