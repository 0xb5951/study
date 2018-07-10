/*
https://abc101.contest.atcoder.jp/tasks/arc099_b
*/
#include <stdio.h>
#include <math.h>

int main() {
  long long k;
  int count = 9;
  int flag = 0;
  scanf("%lld", &k);

  long long num[k];

  for(int i = 0; i < 9; i++){
    if(i >= k) break;
    num[i] = i+1;
  }

  int i = 1;

  while(1){
    if(flag == 1) break;
    for(long long j = 1; j < 10; j++){
      if(count >= k){
        flag = 1;
        break;
      }
      num[count] = j*(long long)pow(10,i) + ((long long)pow(10, i) - 1);
      count++;
    }
    i++;
  }

  for(int i = 0; i < k; i++){
    printf("%lld\n", num[i]);
  }

  return 0;

}
