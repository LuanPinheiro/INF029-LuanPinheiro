#include <stdio.h>

int main() {
	
	int a;
  int b;

  scanf("%d%d", &a,&b);

  a = a + b;
  b = a - b;
  a = a - b;
  
  printf("valor da primeira variavel: %d\n valor da segunda variavel: %d", a, b);
	
	return 0;
}