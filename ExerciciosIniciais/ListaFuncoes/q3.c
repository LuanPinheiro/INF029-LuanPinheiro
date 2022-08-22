#include <stdio.h>

long int fatorial(int x);

int main() {

  int a;
  long int fat;

  scanf("%d", &a);

  fat = fatorial(a);
  if (fat == 0)
  {
    printf("Erro");
    return 0;
  }
  
  printf("Fatorial de %d: %ld", a, fatorial(a));
  
  return 0;
}

long int fatorial(int x) {
  long int res = x;
  int i;

  if(x<0)
  {
    res = 0;
    return res;
  }
  
  for(i=x-1;i>0;i--)
  {
    res *= i;
  }
  return res;
}