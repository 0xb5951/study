/*
https://abc100.contest.atcoder.jp/tasks/abc100_b
*/

#include <stdio.h>

#define MAX 10000

int main(){
  int n;
  long long num[MAX] = {};
  int count = 0;

  scanf("%d", &n);

  for(int i  = 0; i < n; i++){
    scanf("%lld", &num[i]);
  }

  for(int i = 0; i < n;){
    if(num[i]%2 == 1 || num[i] == 0){
      i++;
    } else{
      num[i] /= 2;
      count++;
    }
  }

  printf("%d", count);
  return 0;
}
