#include <stdio.h>

int main() {
	
	int num;
  int div;
  int primo;
  int soma = 0;
  int i;

  for(i=0;i<10;i++)
  {
    scanf("%d", &num);
    primo = 1;
    for(div=num-1;div>1;div--)
    {
      if(num%div==0)
      {
        printf("Nao eh primo\n");
        primo = 0;
        break;
      }
    }
    if (primo == 1)
    {
      printf("Eh primo\n");
      soma += num;
    }
  }
	printf("Soma dos primos: %d", soma);
	return 0;
}