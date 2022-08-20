#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  int i;
  int x;

  struct pessoa {
    char nome[16];
    int idade;
    char sexo;
    long int cpf;
  };

  struct pessoa pessoas[5];

  for (i = 0; i < 5; i++) 
  {
    printf("Digite o nome da pessoa: ");
    scanf("%s", pessoas[i].nome);

    printf("Digite a idade: ");
    scanf("%d", &pessoas[i].idade);

    printf("Digite o sexo (F ou M): ");
    scanf("%s", &pessoas[i].sexo);

    printf("Digite o CPF: ");
    scanf("%ld", &pessoas[i].cpf);
  }

  for (i = 0; i < 5; i++) 
  {
    printf("Pessoa %d\n", i+1);
    
    printf("Nome: %s\n", pessoas[i].nome);
    printf("Idade: %d\n", pessoas[i].idade);
    printf("Sexo: %c\n", pessoas[i].sexo);
    printf("CPF: %ld\n\n", pessoas[i].cpf);
  }

  return 0;
}