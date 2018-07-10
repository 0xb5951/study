/*できるだけ少ないコインでA円を支払う。*/

#include <stdio.h>

const int coin[6] = {1, 5, 10, 50, 100, 500};

int main() {
  int a;
  int m_c[6];
  int i, t;

  for(i = 0; i < 6; i++){
    scanf("%d", &m_c[i]);
  }
  scanf("%d", &a);

  for(i = 5; i > 0; i--){
    int t = (a/coin[i] <= m_c[i] ? a/coin[i] : m_c[i]);
    a -= t * coin[i];
    ans += t;
  }

  printf("%d", ans);
  return 0;
}
