/*蔵書検索プログラム
ある構造体の配列をクイックソート＆バイナリサーチするプログラム
*/
#include <stdio.h>
#include <stdlib.h>

#define N 5

/*蔵書を表すデータ*/
typedef struct {
  char *title;
  char *author;
  int bookID;
  int available; /*貸出中なら0,そうでなければ1*/
} book;

book *bookarray[N]; /*蔵書データのポインタ配列*/

/* 蔵書のデータを初期化する */
void initdata(void){
  int n;
  for(n = 0; n < N; n++){
    bookarray[n] = (book*)malloc(sizeof(book));
  }
  /*malloc: 配列や構造体のメモリサイズを定義、確保するための関数
  引数で指定するバイト数分のメモリが確保され、確保したメモリ領域へのポインタを返す。
  確保したメモリはfree()関数で開放する
  戻り値のポインタはvoid型で帰ってくるため,関数の前に利用するデータ型にキャスト(変換)
  してやる必要性がある。char型のポインタにキャストするなら(char*)と書く.
  確保したメモリは必ず最後に開放する必要がある。
  */

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
void cleanupdata(void){
  int n;
  for(n = 0; n < N; n++){
    free(bookarray[n]);
  }
}

/*本のデータをbookIDの順に昇順でクイックソートする*/
void sortbook(int bottom, int top){
  int lower,upper,x;
  book *temp;

  if(bottom >= top){
    return;
  }

  /*配列の先頭を基準の値にする*/
  x = bookarray[bottom]->bookID;
  for(lower = bottom, upper = top; lower < upper;){
    while(/*lower < upper &&*/bookarray[lower]->bookID < x){
      lower++;
    }
    while(/*lower < upper &&*/bookarray[upper]->bookID > x){
      upper--;
    }

    /*データの順序を入れ替える 構造体ごとまとめてデータを入れ替える*/
    if(lower < upper){
      temp = bookarray[lower];
      bookarray[lower] = bookarray[upper];
      bookarray[upper] = temp;
      lower++;
      upper--;

    }
  }

  sortbook(bottom, upper);
  sortbook(upper+1, top);
}

/*booksの中からbookIdがkeyと一致するデータをバイナリサーチで検索して
その添え字を返す。見つからなければ-1を返す*/
int searchbook(book *books[], int size, int key){
  int left,right,mid;


  left = 0;
  right = size;
  while(left < right){
    mid = (left+right)/2;

    if(books[mid]->bookID < key){
      left = mid + 1;
    } else{
      right = mid;
    }
  }

  if(books[left]->bookID == key){
    return left;
  }

  return -1;
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
