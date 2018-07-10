/*
バウムテストとは、被験者に「木」の絵を描かせることで被験者の心理状態を読み取る心理検査である。
この検査を受けた高橋君は、 N 個の頂点と M 本の辺からなる無向グラフを描いた。
このグラフの連結成分のうち木であるようなもの、すなわち閉路を持たないものの個数を求めよ

入力
N M
これ以下は連結情報が入力される

出力
無向グラフの連結部分のうち木であるものの個数を出力
(木構造になっているもの。)

１つの頂点から成るものも木とみなされる
*/

/*隣接リストにまとめて、その数を表示すればいい*/

/*実装がむずいので、隣接行列で実行*/

/*連結を列挙するためにまだ見ていない頂点を選んでそこからDFSを繰り返す.
dfsする上で無限ループを防ぐためにすでに訪れた頂点をマークしていく。
もし閉路があれば、列挙ずみの点に再度訪れようとするので木の判別が可能.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// typedef struct Tree {
//   struct Tree *next; //次の要素へのポインタ
// }

#define MAX_NODES 101

bool is_connected[MAX_NODES][MAX_NODES]; //連結行列
bool is_visited[MAX_NODES]; //探索済みノードを入れる

bool is_tree(int index, int prev_index, int num_node){ //ノード　前のノード　
  is_visited[index] = true; //そこを探索済みに

  for(int i = 1; i <= num_node; i++) { // 次のノードを見る
    if(i == prev_index) { // 前のノードはすでに見ているのでスキップ
      continue;
    }

    if(is_connected[index][i]) { //結合関係があれば
      if(is_visited[i]) { //すでに見ていれば
        return false;
      }
      if(!is_tree(i, index, num_node)) {
        return false;
      }
    }
  }

  return true;
}

int cnt_tree(int num_node){

  int cnt = 0;

  for(int i = 1; i <= num_node; i++) {
    if(!is_visited[i] && is_tree(i, -1, num_node)) {
      cnt++;
    }
  }

  return cnt;
}



int main() {

  //すべてをfalseで初期化
  memset(is_visited, false, sizeof(is_visited));
  memset(is_connected, false, sizeof(is_connected));

  int num_node, num_edge;
  scanf("%d%d", &num_node, &num_edge);


  for(int i = 0; i < num_edge; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    is_connected[a][b] = true;
    is_connected[b][a] = true;
  }

  printf("%d\n", cnt_tree(num_node));
  return 0;

  return 0;
}
