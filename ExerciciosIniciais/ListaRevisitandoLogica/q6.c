#include <stdio.h>

int main() {
	
	int idade = 1;

  while (idade >= 0)
  {
    scanf("%d", &idade);  
    if (idade >= 18)
      printf("Maior de Idade\n");
    else if(idade >= 0)
    printf("Menor de Idade\n");
  }
  
  printf("Idade invalida");
	
	return 0;
}