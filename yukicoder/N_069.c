/*
https://yukicoder.me/problems/35
*/

#include <stdio.h>
#include <string.h>

int main() {
  int len;
  char a[11] = {};
  char b[11] = {};
  int moji_a[26] = {};
  int moji_b[26] = {};
  int flag = 0;

  scanf("%s\n", a);
  scanf("%s\n", b);

  len = strlen(a);

  for(int i = 0; i < len; i++){
    int temp;
    temp = a[i] - 'a';
    moji_a[temp]++;
  }

  for(int i = 0; i < len; i++){
    int temp;
    temp = b[i] - 'a';
    moji_b[temp]++;
  }

  for(int i = 0; i < 26; i++){
    if(moji_a[i] != moji_b[i]) flag = 1;
  }

  if(flag == 1){
    printf("NO");
  } else {
    printf("YES");
  }

  return 0;
}
