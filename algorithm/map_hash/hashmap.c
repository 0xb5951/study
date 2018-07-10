/*ハッシュマップのプログラム*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 英単語＆和訳を保持する構造体
typedef struct {
  char *english;
  char *japanese;
} WORDSET;

// ハッシュマップ
typedef struct{
  WORDSET **data; //ポインタのポインタ。ポインタ変数のアドレスを変更するのに使う
  //この場合WORDSETのenglishとjapaneseというポインタを格納する。
  // つまりハッシュテーブル用
  unsigned int size;
} HASHTABLE;

// 文字列のASCIIコードに重率をかけてハッシュ値を生成
unsigned int MakeHash2(char* str, unsigned int hashmax) { //ハッシュ対象の文字列　ハッシュマップの最大値
  unsigned int n, length, hash, weight;

  length = strlen(str); //入力された文字の文字列長を取得
  for(n = weight = hash = 0; n < length; n++, weight++) {
    // 重率が256＾7まで到達したら、一巡して再びもとに戻す.int型の限界はそこ。
    if(weight > 7){
      weight = 0;
    }
    // (4 * weight)は(256^weight)と同じ意味
    hash += (int)str[n] << (4 * weight);
    //(int)とつけることでchar型をint型に変換する
    // 2の4乗は16なのでこれでいい。weightで桁を区別。
    //ハッシュは各桁に１６の桁乗をかける
  }

  return hash % hashmax; //ハッシュマップの最大値で割ることで容量を制限
}

// firsthashの位置が埋まっていた場合に再ハッシュを行うための関数
// 衝突が起きた場合、K^2の番地に移動する
unsigned int ReHash(HASHTABLE *hashtable, unsigned int firsthash) { //ハッシュテーブル　検索先のアドレス
  unsigned int hashval, k;
  // firstvalからK^2だけ後ろにある空き位置を探す。
  // Kがハッシュマップの半分以上行くと意味なし
  for(k = 1; k <= hashtable->size / 2; k++) {
    hashval = (firsthash + k * k) % hashtable->size; //再ハッシュは現在のハッシュ番地にKの2乗を足す
    if(hashtable->data[hashval] == NULL) { //もし再ハッシュ先が空だったらその先に入れる
      return hashval;  //ハッシュ値（配列番号）
    }
  }
  // 空き位置が見つからなかったら-1を返す
  return -1;
}

// newdataをhashtableに追加する
void AddDataToMap(HASHTABLE *hashtable, WORDSET *newdata) { //追加先のハッシュマップ　追加する文字データ
  unsigned int hashval;
  // 英単語を基にハッシュ値を生成
  hashval = MakeHash2(newdata->english, hashtable->size); //新しく追加するデータ　ハッシュマップの最大値

  // もしもhashの位置がすでに埋まってる場合再ハッシュを行う
  if(hashtable->data[hashval] != NULL) {
    hashval = ReHash(hashtable, hashval);

    // 再ハッシュ結果が-1であれば、空き位置が見つからなかった（マップが満杯）
    if(hashval == -1){
      printf("%sをマップに挿入しようと試みましたが、空き位置がありあせんでした\n", newdata->english);
      return;
    }
  }

  // ここまで来ると空のハッシュテーブルがある。
  // hashvalの位置にnewdataへのポインタを格納
  hashtable->data[hashval] = newdata;
}

// 英単語keyに対応する和訳をhashtableから探し出して返す。返り値がポインタ
char *GetDataFromMap(HASHTABLE *hashtable, char *key) { //サーチ対象のハッシュテーブル　検索対象
  unsigned int hashval, k;
  WORDSET *word;

  // 探索を開始するハッシュ値を求める
  hashval = MakeHash2(key, hashtable->size); //対象のハッシュ値を計算

  // その位置から順番にkeyと同じ値を持つデータが現れるまで探索を行う
  for(k = 0; k <= hashtable->size / 2; k++) {
    word = hashtable->data[(hashval + k*k) % hashtable->size];
    if(word != NULL) {
      if(strcmp(key, word->english) == 0){
        // str1とstr2が等しいならば0、
        // str1>str2ならば正の値、
        // str1<str2ならば負の値を返す。
        return word->japanese;
      }
    }
  }

  // ハッシュマップサイズの半分に相当する回数探し続けても見つからない場合は該当するデータがハッシュマップの中にない
  return NULL;
}

// 英単語keyに関するデータをhashtableから取り除く(データそのものは削除しない)
WORDSET *DeleteDataFromMap(HASHTABLE *hashtable, char *key) {
  unsigned int hashval, k;
  WORDSET *word;

  // 探索を開始するハッシュ値を求める
  hashval = MakeHash2(key, hashtable->size);

  // その位置から順番にkeyと同じ値を持つデータが現れるまで探索を行う
  for(k = 0; k <= hashtable->size / 2; k++) {
    word = hashtable->data[(hashval + k*k) % hashtable->size];
    if(word != NULL) {
      if(strcmp(key, word->english) == 0){
        hashtable->data[(hashval + k*k) % hashtable->size] = NULL;
        return word;
      }
    }
  }

  // ハッシュマップサイズの半分に相当する回数探し続けても見つからない場合は該当するデータがハッシュマップの中にない
  return NULL;
}

// ハッシュテーブルを指定したサイズに初期化する
void InitHashTable(HASHTABLE *hashtable, unsigned int size) {
  hashtable->data = (WORDSET**)malloc(sizeof(WORDSET*)*size);
  // ハッシュテーブルをNULLで埋める
  memset(hashtable->data, 0, sizeof(WORDSET*)*size);

  //メモリに指定バイト数分の値をセットする
  //   void *memset(void *buf, int ch, size_t n);
  // 第一引数はメモリのポインタ
  // 第二引数はセットする値
  // 第三引数はセットするサイズ

  // これはエラーが出た
  // memset(hashtable->data, NULL, sizeof(WORDSET*)*size);
  // NULLで初期化するのはダメ。ポインタならNULLでいいけど、値は0じゃないとダメ。
  hashtable->size = size; //ハッシュマップの大きさは503
}

// ハッシュテーブルのクリーンアップ
void CleanupHashTable(HASHTABLE *hashtable) {
  free(hashtable->data);
  hashtable->size = 0;
}

// hashtable中の全データを表示する
void PrintAllData(HASHTABLE *hashtable) {
  unsigned int n;
  for(n = 0; n < hashtable->size; n++){
    if(hashtable->data[n] != NULL) {
      printf("%d:\t%s\t%s\n", n, hashtable->data[n]->english, hashtable->data[n]->japanese);
    }
  }
}

int main() {
  unsigned int n;
  char key[64], *japanese;
  HASHTABLE hashtable;
  WORDSET *wordfound;
  WORDSET words[5] = {
    {"dolphin", "イルカ"}, {"beluga", "シロイルカ"}, {"grampus", "シャチ"},
    {"medusa", "海月"}, {"otter", "カワウソ"}
  };

  // ハッシュテーブルの初期化
  InitHashTable(&hashtable, 503);

  // データを追加
  for(n = 0; n < 5; n++){
    AddDataToMap(&hashtable, &words[n]);
  }

  do{
    printf("どの検索を行いますか？（1：検索 2：削除 3：全表示 0:終了）\n>");
    scanf("%d", &n);

    switch(n) {
      case 1: //検索
      printf("検索する英単語を入力してください:");
      scanf("%s", key);
      japanese = GetDataFromMap(&hashtable, key);
      if(japanese != NULL) {
        printf("%sの和訳は%sです。\n", key, japanese);
      } else {
        printf("%sがマップの中に見つかりませんでした\n", key);
      }
      break;
      case 2: //削除
      printf("削除する英単語を入力してください:");
      scanf("%s", key);
      wordfound = DeleteDataFromMap(&hashtable, key);
      if(wordfound != NULL) {
        printf("%sをマップから削除しました。\n", key);
      } else {
        printf("%sがマップの中に見つかりませんでした\n", key);
      }
      break;
      case 3: //全表示
      PrintAllData(&hashtable);
      break;
    }
  } while(n != 0);

  CleanupHashTable(&hashtable); //クリーンアップ

  return 0;
}
