/*ソート
https://www.youtube.com/watch?v=S1IkBhwnuYU*/

/*
動かした数に印をつける。そうすると、印がつかない数が存在する。
その数は操作されないので、順番に連結する。
なので、印をつけたもの以外は順番にならんだ数である必要性がある。
つまり、それ以外の数が動かした数になり、その個数を返せばいい。

まず、与えられた配列を数字順に並べなおし、配列番号を振る。
その中で、値が昇順になっている最大区間を見つける。
与えられた数からそれを引けば答え。
*/

#include <stdio.h>

#define MAX 20000

int main(){
  int array[MAX+1],temp[MAX+1];
  int n,max;
  int i,j,count = 0;

  scanf("%d", &n);
  for(i = 1; i <= n+1; i++){
    scanf("%d", &array[i]);
  }

  for(i = 0; i <= n; i++){
    for(j = 0; j <= n; j++){
      if(i == array[j]){
        temp[i] = j;
        break;
      }
    }
  }

  // for(i = 1; i <= n; i++){
  //   printf("%d", temp[i]);
  // }


  for(i = 1; i <= n; i++){
    // printf("%d%d\n", tp, temp[i]);

    if(temp[i] < temp[i+1]){
      count++;
    }else{
      if(max<count) max=count;
      count = 1;
    }
  }

  int ans;
  ans = n - max;

  printf("%d", ans);

  return 0;
}
