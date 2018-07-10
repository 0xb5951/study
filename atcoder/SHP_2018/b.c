/*
https://soundhound2018-summer-qual.contest.atcoder.jp/tasks/soundhound2018_summer_qual_b
*/

#include <stdio.h>
#include <string.h>

#define MAX 1000

int main() {
  char s[MAX] = {};
  char ans[MAX] = {};
  int w;
  scanf("%s", s);
  scanf("%d", &w);

  int l;
  l = strlen(s);

  for(int i = 0; i < strlen(s); i += w){
    printf("%c", s[i]);
  }

  return 0;
}
