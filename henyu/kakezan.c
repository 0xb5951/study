/*
https://arc051.contest.atcoder.jp/tasks/arc051_c
*/

#include <stdio.h>


void Quick_sort(int bottom, long long int num[]){
  int lower, upper, kijun, temp;
  if(bottom >= top){
    return;
  }

  kijun = num[bottom];

  for()
  if(n <= 1) return;

  m = n/2;
}

int main() {
  long long int n,a,b;
  long long int num[50] = {};

  scanf("%lld%lld%lld", &n, &a, &b);

  for(int i = 0; i < n; i++){
    scanf("%lld", &num[i]);
  }

  for(int i = 0; i < b; i++){
    long long int min = 99999999999999;
    for(int j = 0; j < n; i++){
      if(min > num[j]){
          min = num[j];
          num[j] *= a;
      }
    }
  }

  Quick_sort(n, num);


}
