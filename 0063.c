#include <stdio.h>
#include <stdlib.h>

int main() {
  int s, p;
  scanf("%d %d", &s, &p);

  int x = -1, y = -1;
  for (int i = 1; i <= 1000; ++i) {
    for (int j = 1; j <= 1000; ++j) {
      if (i + j == s && i * j == p) {
        x = i;
        y = j;
        break;
      }
    }
    if (x != -1) break;
  }

  int min_val = (x < y) ? x : y;
  int max_val = (x > y) ? x : y;

  printf("%d %d\n", min_val, max_val);

  return 0;
}

