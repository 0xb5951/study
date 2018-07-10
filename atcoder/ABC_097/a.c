/*
Colorful Transceivers
*/

#include <stdio.h>

int main (){
  int a,b,c,d;

  scanf("%d%d%d%d", &a, &b, &c, &d);

  int ab, bc, ca;
  ab = b - a;
  bc = b - c;
  ca = c - a;

  if(( abs(ab) <= d && abs(bc) <= d ) || abs(ca) <= d){
    printf("Yes");
  } else {
    printf("No");
  }

  return 0;
}
