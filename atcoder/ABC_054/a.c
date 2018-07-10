/*
https://abc054.contest.atcoder.jp/tasks/abc054_a
*/


#include <stdio.h>

int main(){
  int a,b;
  int card[] = {0, 13, 1, 2, 3 ,4 ,5 ,6 ,7 ,8 ,9 ,10 , 11 , 12};
  scanf("%d%d",&a, &b);

  // printf("%d %d\n", card[a], card[b]);
  if(card[a] == card[b]) printf("Draw");
  if(card[a] > card[b]) printf("Alice");
  if(card[a] < card[b]) printf("Bob");

  return 0;
}
