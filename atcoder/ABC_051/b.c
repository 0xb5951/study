/*
https://abc051.contest.atcoder.jp/tasks/abc051_b
*/

/*forループではn^3乗になるから動かない。
どうにかして他の方法で作る必要がある。
x+y+z=sなので、z = s - x - y;
これが正でK以下ならSを作ることは可能.
*/

#include <stdio.h>

int main(){
  int k,s;
  int x,y,z;
  int count;

  scanf("%d%d", &k, &s);

  for(x = 0; x <= k; x++){
    for(y = 0; y <= k; y++){
      z = s - x - y;
      if(0 <= z && z <= k)count++;
    }
  }

  printf("%d", count);
  return 0;
}


// #include <stdio.h>
//
// int main(){
//   int k,s;
//   int x,y,z;
//   int count = 0;
//
//   scanf("%d%d", &k, &s);
//
//   for(x = 0; x <= k; x++){
//     if(x > s) break;
//
//     for(y = 0; y <= k; y++){
//       if(y > s) break;
//
//       for(z = 0; z <= k; z++){
//         if(x+y+z == s) count++;
//         if(x+y+z > s) break;
//         if(z > s) break;
//       }
//     }
//   }
//
//   printf("%d", count);
//   return 0;
// }
