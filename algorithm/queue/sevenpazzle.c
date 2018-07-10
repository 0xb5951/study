//幅優先探索を用いて７パズルを解くプログラム
#include <stdio.h>
#include <stdlib.h>

//今までの局面を記憶する配列。この配列はキュー代わりにも使われる
typedef struct tagPATTERN {
  unsigned long hash; //ハッシュ値を保存
  int pattern_from; //初期状態からの経過を保存
} PATTERN;

PATTERN *history;

int history_count = 0; //現在のパターンの個数
int queue_bottom;      //キューのしっぽの位置を表す添え字

//局面と対応する数字を作り出す関数
unsigned long make_hash(char* pattern) {
  unsigned long hash;
  int i;

  hash = 0;

  for(i = 0; i < 8; i++){
    hash |= ((unsigned long)(pattern[7 - i])) << (i * 4); //４は２の４乗で16
    printf("%d ", hash);
    // |= ビット単位のOR代入演算子
    //文字をビットに変換して,ORをとる。それに16の桁乗をかける
    //パターンの後ろから参照してる
    //ハッシュ値とパターンの各文字に対してORを取る
    //char型をlong型に変換
    //16の桁乗をかけることでハッシュ化
  }
  return hash;
}


//数字から局面を復元する関数
void pattern_from_hash(char* pattern, unsigned long hash){
  int i;
  for(i = 0; i < 8; i++) {
    pattern[7 - i] = (char)((hash >> (i * 4))  & 0xf);
    //long型からchar型に直して、ハッシュを桁ごとに戻す
    //0xfは１６進数で１５を表す
    //ハッシュの値と4桁分ANDすることで値を抽出する
  }
}

//局面を保存する関数
void save_history(char* pattern, int pattern_from) { //記憶する局面　その番号
  int i;
  unsigned long hash;

  hash = make_hash(pattern); //盤面のハッシュ値を生成

  //今までの局面と比較する。ハッシュ値が同じだと、同じ盤面。
  //history_countで今までの盤面をすべて比較
  for(i = 0; i < history_count; i++) {
    if(history[i].hash == hash) { //ハッシュ値が一致したら終了
      return;
    }
  }

  //新しく出てきた局面を保存.ここまできたら新しい局面ということ。
  history_count++;
  history = (PATTERN*)realloc(history, sizeof(PATTERN) * (history_count));
  // realloc関数は確保したメモリの割り当てを変更する
  // 第一引数に確保したメモリのポインタ 第二引数に変更後のメモリサイズ
  if(history == NULL) {
    printf("メモリが足りません");
    exit(EXIT_FAILURE);
  }

  history[history_count - 1].hash = hash;
  history[history_count - 1].pattern_from = pattern_from;
}

int solve_7puzzle(void) {
  int blank_pos;
  unsigned long hash;
  char pattern[8]; //パズル配置.4つ区切りで２行。

  queue_bottom = 0;
  while(queue_bottom != history_count) { //キューが空になるまで繰り返す
    //キューから一つ取得する
    hash = history[queue_bottom].hash;

    //解にたどりついたら終了
    if(hash == 0x12345670) {
      return 1;
    }
    //ハッシュから局面を生成
    pattern_from_hash(pattern, hash);

    //空白の場所を取得（0のとこが空白）
    for(blank_pos = 0; blank_pos < 8; blank_pos++) {
      if(pattern[blank_pos] == 0) {
        break;
      }
    }

    //上から空いている場所に移動
    //4から二列目なので、３以上だと上方向に移動できる
    if(blank_pos > 3){
      pattern[blank_pos] = pattern[blank_pos - 4]; //マイナス４で上に移動
      pattern[blank_pos - 4] = 0;
      //新しいパネル配置を保存した後、元の配置に戻す
      save_history(pattern, queue_bottom);
      pattern_from_hash(pattern, hash);
    }

    //下から空いている場所に移動
    if(blank_pos < 4){
      pattern[blank_pos] = pattern[blank_pos + 4];
      pattern[blank_pos + 4] = 0;
      //新しいパネル配置を保存した後、元の配置に戻す
      save_history(pattern, queue_bottom);
      pattern_from_hash(pattern, hash);
    }

    //左から空いている場所に移動
    //空白が0か４以外にあれば、移動させることが出来る
    if(blank_pos != 0 && blank_pos != 4){
      pattern[blank_pos] = pattern[blank_pos - 1]; //配置を-1することで空白を左に移動
      pattern[blank_pos - 1] = 0;
      //新しいパネル配置を保存した後、元の配置に戻す
      save_history(pattern, queue_bottom);
      pattern_from_hash(pattern, hash);
    }

    //右から空いている場所に移動
    //空白が3か7以外にあれば、移動させることが出来る
    if(blank_pos != 3 && blank_pos != 7){
      pattern[blank_pos] = pattern[blank_pos + 1];
      pattern[blank_pos + 1] = 0;
      //新しいパネル配置を保存した後、元の配置に戻す
      save_history(pattern, queue_bottom);
      pattern_from_hash(pattern, hash);
    }
    queue_bottom++;
  }
  return 0; //解が見つからなかった場合
}

int main() {
  int last, i;
  char pattern[8] = {2,7,1,4,5,0,3,6};
  unsigned long hash;

  history = NULL;

  //最初のパターン１を記録
  save_history(pattern, -1);

  printf("\n ");

  if(solve_7puzzle() == 0) {
    printf("全パターンを試しましたが、解が見つかりませんでした\n");
  } else { //解を表示する
    last = -1;
    while(last != queue_bottom) {
      //最初の解から表示していく
      for(i = queue_bottom; history[i].pattern_from != last;) {
        i = history[i].pattern_from;
      }
      last = i;

      //パネル配置を表示
      pattern_from_hash(pattern, history[last].hash);
      for(i = 0; i < 8; i++){
        printf("%c ", pattern[i] ? pattern[i] + '0': ' ');
        if(i % 4 == 3) {
          printf("\n");
        }
      }
      getchar(); //リターンキーで次を表示
    }
  }

  free(history);
  return 0;
}
