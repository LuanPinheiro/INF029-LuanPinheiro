#include <stdio.h>

int soma(int x, int y);

int main() {

  int a;
  int b;

  scanf("%d%d", &a, &b);

  printf("Soma dos valores %d e %d: %d", a, b, soma(a, b));
  return 0;
}

int soma(int x, int y) {
  int res;

  res = x + y;
  return res;
}