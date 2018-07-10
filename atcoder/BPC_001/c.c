/*
https://bitflyer2018-qual.contest.atcoder.jp/tasks/bitflyer2018_qual_c
*/

#include<stdio.h>

long x[100001];

long search(long a,long left,long right){
  long mid;

  if(right<left)
    return right;
  mid=(left+right)/2;

  if(x[mid]>a)
    return search(a,left,mid-1);
  else
    return search(a,mid+1,right);

}

int main(){
  long n,i,a[100000],j,cnt=0;
  long b[100001]={};
  long d;

  scanf("%ld %ld",&n,&d);

  for(i=0;i<n;i++){
    scanf("%ld",&x[i]);
 }

  x[n] = x[n-1] + d+1;

  for(i=0;i<n;i++) a[i]=search(x[i]+d,i+1,n-1);

  b[0]=a[0];

  for(i=1;i<n;i++) b[i]=b[i-1]+a[i];

  for(i=0;i<n-2;i++){
    cnt += b[a[i]] - b[i] - (a[i] * (a[i]-i));
  }

  printf("%ld\n",cnt);
}
