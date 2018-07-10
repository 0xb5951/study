/*
https://abc053.contest.atcoder.jp/tasks/arc068_b
*/

// はじめてDまで全部とけた！！！！！！！！！！！！！！！！！！

#include <stdio.h>

int main(){
  long n;
  long a[100001] = {};
  long count = 0;
  long maxt = 0;

  scanf("%ld", &n);

  for(long i = 0; i < n; i++){
    long t;
    scanf("%ld", &t);
    a[t]++;
    if(maxt < t) maxt = t;
  }
  // printf("%d" , maxt);

  for(long i = 0; i <= maxt; i++){
    if(a[i] >= 2) count += a[i] - 1;
  }

  if(count%2 == 1) count++;

  long ans;
  ans = n - count;

  printf("%ld", ans);
  return 0;
}
