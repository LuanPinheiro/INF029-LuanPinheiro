#include <stdio.h>
#include <string.h>
#define tam 2

typedef struct {
  char nome[60];
  char cpf[13];
  char dataNasc[20];
  char sexo;
} dados_cliente;

void cadastrarCliente(dados_cliente cliente[]);
void LimparString(char string[]);

int main() {

  dados_cliente cliente[tam];

  cadastrarCliente(cliente);

  for(int i = 0; i<tam; i++)
  {
    printf("\nNome do Cliente: %s\n", cliente[i].nome);
    printf("CPF do Cliente: %s\n", cliente[i].cpf);
    printf("Data de nascimento do Cliente: %s\n", cliente[i].dataNasc);
    printf("Sexo do Cliente: %c\n", cliente[i].sexo);
  }
  

  return 0;
}

void cadastrarCliente(dados_cliente cliente[]) {

  for(int x = 0; x<tam ; x++)
  {
    printf("Nome: ");
    fgets(cliente[x].nome, 60, stdin);
    LimparString(cliente[x].nome);

    printf("CPF: ");
    fgets(cliente[x].cpf, 13, stdin);
    LimparString(cliente[x].cpf);
    
    printf("Data: ");
    fgets(cliente[x].dataNasc, 20, stdin);
    LimparString(cliente[x].dataNasc);
    
    printf("Sexo: ");
    cliente[x].sexo = getchar();
    getchar();
  }
  
}

void LimparString(char string[]){
  for(int i=0;string[i] != '\0';i++)
      if(string[i] == '\n')
        string[i] = '\0';
}