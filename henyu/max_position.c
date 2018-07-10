/*
arrayの先頭のn個の要素のうち、最大の要素の添え字を返す。
*/
#include <stdio.h>

int count;

//呼び出された回数をcountに保存
int max_position(int n, int array[]) {
  count++;

  if (n > 1) {
    int p = max_position(n - 1, array);
    printf("%d %d\n", p, count);
    if (array[n - 1] < array[p]) {
      return max_position(n - 1, array);
    } else {
      return n-1;
    }
  }

  return 0;
}

int main() {
  int array[18] = {1,7,5,8,9,4,5,6,4,8,6,5,4,8,5,5,4,3};

  int i;
  int t;

  printf("求めたい範囲を入力してください\n");
  scanf("%d", &i);
  t = max_position(i, array);
  printf("%d", t);

  return 0;
}
