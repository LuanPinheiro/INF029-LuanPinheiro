#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	
	int n;
	int i;
	int media = 0;

  struct pessoa
  {
    char nome[16];
    int idades;
  };
  
	scanf("%d",&n);
	
	struct pessoa pessoas[n];
	
	for(i=0;i<n;i++)
	{
    getchar();
    fgets(pessoas[i].nome, 16, stdin);
		scanf("%d", &pessoas[i].idades);
		media += pessoas[i].idades;
	}
	
	media /= n;

  printf("Media das idades: %d\n", media);
  
	for(i=0;i<n;i++)
	{
		if (pessoas[i].idades > media)
		{
			printf("%s com idade %d. maior que a media\n", pessoas[i].nome, pessoas[i].idades);
		}
	}
	
	return 0;
}