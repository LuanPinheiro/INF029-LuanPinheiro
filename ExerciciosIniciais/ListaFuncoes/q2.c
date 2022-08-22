#include <stdio.h>

int subtrai(int x, int y, int z);

int main() {

  int a;
  int b;
  int c;

  scanf("%d%d%d", &a, &b, &c);

  printf("Subtracao dos valores %d, %d e %d: %d", a, b, c, subtrai(a, b, c));
  return 0;
}

int subtrai(int x, int y, int z) {
  int res;

  res = x - y - z;
  return res;
}