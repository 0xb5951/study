// 蔵書検索プログラム
#include <stdio.h>
#include <stdlib.h>

#define N 5

//蔵書クラス
class Cbook{
public:
  char *title;
  char *author;
  int bookID;
  int available;


  //比較演算子のオーバーロード
  // sortbook()の中でCbook同士を比較
  bool operator > (Cbook& book) {
    return bookID > book.bookID;
  }
  bool operator < (Cbook& book) {
    return bookID < book.bookID;
  }
  //int型へのキャストをオーバーロード
  //searchbook()の中でkeyとbookIDを比較
  operator int(){
    return bookID;
  }
};

Cbook* bookarray[N]; /*蔵書データのポインタの配列*/

/*蔵書データを初期化する*/
void initdata(){
  int n;
  for(n = 0; n < N; n++){
    bookarray[n] = new Cbook;
  }

  bookarray[0]->title = "みんなのPython";
  bookarray[1]->title = "アルゴリズムとデータ構造";
  bookarray[2]->title = "編入数学過去問特訓";
  bookarray[3]->title = "ゼロから作るDeepLearning";
  bookarray[4]->title = "プログラミングコンテストチャレンジブック";

  bookarray[0]->author = "柴田淳";
  bookarray[1]->author = "木平卓夫,春日伸弥";
  bookarray[2]->author = "桜井基晴";
  bookarray[3]->author = "斎藤康毅";
  bookarray[4]->author = "秋葉拓哉,岩田陽一,北川宜稔";

  bookarray[0]->bookID = 1000;
  bookarray[1]->bookID = 502;
  bookarray[2]->bookID = 731;
  bookarray[3]->bookID = 628;
  bookarray[4]->bookID = 1;

  bookarray[0]->available = 1;
  bookarray[1]->available = 0;
  bookarray[2]->available = 0;
  bookarray[3]->available = 1;
  bookarray[4]->available = 1;
}


/*蔵書データのメモリを解放*/
void cleanupdata() {
  int n;
  for(n = 0; n < N; n++) {
    delete bookarray[n];
  }
}

int main(void) {
  int key, position;

  initdata();
  sortbook(0, N - 1);  /*最初に管理番号順にソートしておく*/

  /*検索キーとして本の管理番号を入力*/
  while(1){
    printf("検索する本の番号を入力してください");
    scanf("%d", &key);
    if(key == 0) {
      break; /*0が入力されたら終了*/
    }

    /*検索して結果を表示*/
    position = searchbook(bookarray, N - 1, key);
    if(position != -1) {
      printf("--次の本が見つかりました--\n [タイトル]%s \n[著者]%s \n[管理番号]%d \n",
      bookarray[position]->title,
      bookarray[position]->author,
      bookarray[position]->bookID);

      if(bookarray[position]->available != 0){
        puts("この本は貸出可能です.\n");
      } else {
        puts("この本は貸出中です.\n");
      }

    } else {
      puts("お探しの本は見つかりませんでした.\n");
    }
  }

  cleanupdata();
  return 0;
}
