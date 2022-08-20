#include <stdio.h>

int main() {
	
	int num;
  int i;

  scanf("%d", &num);

  for(i=num-1;i>0;i--)
  {
    num *= i;
  }

  printf("fatorial: %d", num);
	return 0;
}