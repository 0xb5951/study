#include <stdio.h>

int ans[100001];

int min(int a, int b) {
  return a < b ? a : b;
}

void build_table(int a) {
  for (int i = 1; i <= a; i++) {
    ans[i] = 1000000;

    for (int x = 1; x <= i; x *= 9) {
      ans[i] = min(ans[i], ans[i - x] + 1);
    }

    for (int x = 1; x <= i; x *= 6) {
      ans[i] = min(ans[i], ans[i - x] + 1);
    }
  }
}

int main() {
  int a;
  scanf("%d", &a);
  build_table(a);
  printf("%d\n", ans[a]);
  return 0;
}
