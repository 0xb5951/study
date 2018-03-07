//2分木のプログラム
/*数字を格納して、自分より大きい値を右。小さい値を左にする
こうすることで２分木にする*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _tag_tree_node {
  int value;
  struct _tag_tree_node *left;
  struct _tag_tree_node *right;
} tree_node;

tree_node *tree_root = NULL;

//新しいノードを追加する
tree_node* create_new_node(int num) {
  tree_node *tree_new;

  tree_new = (tree_node*)malloc(sizeof(tree_node));
  if(tree_new == NULL){
    exit(EXIT_FAILURE);
  }
  tree_new->left = NULL;
  tree_new->right = NULL;
  tree_new->value = num;

  return tree_new;
}

void insert_tree(int num, tree_node *node) {
  //1つも挿入されていない場合
  if(node == NULL){
    tree_root = create_new_node(num);
    return;
  }

  //numが現在のnodeの値よりも小さい場合
  if(node->value > num){
    if(node->left != NULL) { //このノードが中間にある場合
      insert_tree(num, node->left);
    } else { //このノードが葉の場合
      node->left = create_new_node(num);
    }
  } else {
    //numが現在のnodeの値以上の場合
    if(node->right != NULL){
      insert_tree(num, node->right);
    } else {
      node->right = create_new_node(num);
    }
  }

  return;
}

tree_node* find_value(tree_node* node, int val){
  //発見したtree_nodeのポインタを返す。ない場合はNULL

  //自分より小さい値ならば左側
  if(node->value > val){
    if(node->left == NULL) { //もし左側になければvalはない
      return NULL;
    }
    return find_value(node->left, val);
  }

  //自分より大きい値ならば右側
  if(node-> value < val){
    if(node->right == NULL) {
      return NULL;
    }
    return find_value(node->right, val);
  }

  //みつかった値を返す
  return node;
}

int delete_tree(int val) {
  //valを削除する。成功すれば１、失敗すれば0を返す
  tree_node *node, *parent_node;
  tree_node *left_biggest;
  int direction;

  node = tree_root;
  parent_node = NULL;
  direction = 0;

  //while文で削除すべき対象を見つける(find_valueと同じ)
  while(node != NULL && node->value != val) {
    if(node->value > val){ //対象よりノードの値が大きい場合
      parent_node = node;
      node = node->left; //ノードの左に移動
      direction = -1; //親の左側
    } else {
      parent_node = node;
      node = node->right;
      direction = 1; //親の右側
    }
  }
  if(node == NULL) { //見つからなかった場合
    return 0;
  }

  if(node->left == NULL || node->right == NULL){
    //右か左、どちらかがNULLであった場合(対象ノードのどっちかがない場合)
    if(node->left == NULL){
      //親のポインタを変更する
      if(direction == -1){ //親ノードの左側
        parent_node->left = node->right;
      }
      if(direction == 1){ //親ノードの右側
        parent_node->right = node->right;
      }
      if(direction == 0){ //親ノードの左側
        tree_root = node->right;
      }
    } else {
      if(direction == -1){ //親ノードの左側
        parent_node->left = node->left;
      }
      if(direction == 1){ //親ノードの右側
        parent_node->right = node->left;
      }
      if(direction == 0){ //親ノードの左側
        tree_root = node->left;
      }
    }

    free(node);
  } else {
    //両者ともNULLでなかった場合

    //nodeの左側の最も大きな値（もっとも右側の値）を取得する
    left_biggest = node->left;
    parent_node = node;
    direction = -1;
    while(left_biggest->right != NULL) {
      parent_node = left_biggest;
      left_biggest = left_biggest->right;
      direction = 1;
    }

    //left_biggestの値をnodeに代入し、left_biggestは左側の枝を入れる
    node->value = left_biggest->value;
    if(direction == -1){
      parent_node->left = left_biggest->left;
    } else {
      parent_node->right = left_biggest->left;
    }
    free(left_biggest);
  }

 return 1;
}

void print_tree(int depth, tree_node* node){
  int i;

  if(node == NULL){
    return;
  }
  print_tree(depth+1, node->left);
  for(i = 0; i < depth; i++){
    printf(" ");
  }
  printf("%d\n", node->value);
  print_tree(depth+1, node->right);
}

void free_tree(tree_node* node){
  if(node == NULL){
    return;
  }
  //まず子nodeのメモリを解放する
  free_tree(node->left);
  free_tree(node->right);

  //自分自身を解放
  free(node);
}

int main(){
  int i, action;

  for(i = 0; i < 10; i++){
    insert_tree(rand() % 99 + 1, tree_root);
  }
  for(;;){
    print_tree(0, tree_root);
    printf("実行する操作のタイプを入力してください\n \
           1:追加\t2 :検索\t3 :削除\t それ以外:終了>");
    scanf("%d", &action);
    switch (action) {
      case 1:
      printf("1~100の範囲で追加する数字を入力してください");
      scanf("%d", &i);
      if(i < 1 || i > 100) {
        continue;
      }
      insert_tree(i, tree_root);
      break;
      case 2:
      printf("検索する数字を入力してください:");
      scanf("%d", &i);
      if(find_value(tree_root, i) != NULL) {
        printf("%dを発見しました\n", i);
      } else {
        printf("%dは見つかりませんでした\n", i);
      }
      break;
      case 3:
      printf("削除する場合を入力してください:");
      scanf("%d", &i);
      if(delete_tree(i) == 1) {
        printf("%dを削除しました\n", i);
      } else {
        printf("%dは見つかりませんでした\n", i);
      }
      break;
      default:
       free_tree(tree_root);
       return EXIT_SUCCESS;
    }
  }
}
