/*
長さNの文字列S.この文字列を一箇所で切断する。
どちらにも含まれる文字数を最大化せよ。
*/

#include<stdio.h>

int main()
{
  char s[100];
  int N;
  scanf("%d",&N);
  scanf("%s",s);

  int alpha[1000];
  int i,j,k,count=0,count_max=0;;

  for(i=1;i<N;i++){
    count=0;
    for(j=0;j<1000;j++){
      alpha[j]=0;
    }

    for(j=i;j<N;j++){ //後半(iから)
      for(k=0;k<i;k++){ //前半(iまで)
        if(s[j]==s[k] && alpha[s[j]]==0){
          count++;
          alpha[s[j]] = 1;
        }
      }
    }
    if(count>=count_max){
      count_max=count;
    }
  }

  printf("%d\n",count_max);

  return 0;
}
