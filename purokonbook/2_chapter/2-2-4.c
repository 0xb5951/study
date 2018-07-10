/*Saruman's army
N個の点が直線状にある。
N個のうちいくつかの点に印を作る。
しかしN個のすべての点において距離がR以内の場所に印がないといけない。
条件を満たしながらできるだけ印をつける点を少なくしたい。何個の点に印をつける。
*/

/*一番左の点から考える。
その点から距離R以内で一番遠い点に所に印をつける
また次は印をつけた点から右にR以上離れている点を基準にして、
また距離R以内で一番離れた点に印をつける
*/

#include <stdio.h>

int main(){
  int n, r;
  int x[1000];
  int i, k;
  int ans = 0, flag;
  int temp, s;


  scanf("%d %d", &n, &r);

  for(i = 0; i < n; i++){
    scanf("%d", &x[i]);
  }

  do{
    flag = 0;
    for(i = 0; i < n - k - 1; i++){
      if(x[i] > x[i + 1]){
        flag = 1;
        temp = x[i];
        x[i] = x[i+1];
        x[i+1] = temp;
      }
    }
    k++;
  }while(flag == 1);

  while (i < n) {
    s = x[i++];
    //現在地点から距離Rを超える点まで進む
    while(i < n && x[i] <= s + r) i++;

    //pは新しく印をつける点の位置
    int p = x[i - 1]; //ここでｒ以内の一番遠い位置にいる。

    //pから距離ｒを超える点まで進む
    while(i < n && x[i] <= p + r) i++;

    ans++;
  }

  printf("%d", ans);
  // for(i = 0; i < n; i++){
  //   printf("%d", x[i]);
  // }

  return 0;
}
