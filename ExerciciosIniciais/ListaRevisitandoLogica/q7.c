#include <stdio.h>

int main() {
	
	int num;
  int div;

  scanf("%d", &num);

  for(div=num-1;div>1;div--)
  {
    if(num%div==0)
    {
      printf("Nao eh primo");
      return 0;
    }
  }
  
	printf("Eh primo");
	return 0;
}