/*
https://yukicoder.me/problems/361
星１
*/

#include <stdio.h>

int hukumame(int *fam, int k, int n, int f){
  int mame;
  mame = k*n;

  for(int i = 0; i < f;i++){
    mame -= fam[i];
  }

  if(mame < 0) return -1;
  else return mame;
}

int main() {
  int k,n,f;
  int fam[101] = {};
  scanf("%d%d%d", &k, &n, &f);

  for(int i = 0; i < f; i++){
    scanf("%d", &fam[i]);
  }

  int ans;
  ans = hukumame(fam,k,n,f);

  printf("%d", ans);
  return 0;
}
