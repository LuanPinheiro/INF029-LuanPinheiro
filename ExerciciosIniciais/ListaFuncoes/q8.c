#include <stdio.h>
#include <string.h>

typedef struct {
  char nome[20];
  long int cpf;
  int dataNasc[3];
  char sexo;
} dados_cliente;

void cadastrarCliente(dados_cliente cliente);

int main() {

  dados_cliente cliente;

  cadastrarCliente(cliente);

  printf("\nNome do Cliente: %s\n", cliente.nome);
  printf("CPF do Cliente: %ld\n", cliente.cpf);
  printf("Data de nascimento do Cliente: %d/%d/%d\n", cliente.dataNasc[0], cliente.dataNasc[1], cliente.dataNasc[2]);
  printf("Sexo do Cliente: %c\n", cliente.sexo);

  return 0;
}

void cadastrarCliente(dados_cliente cliente) {

  scanf("%s", cliente.nome);
  scanf("%ld", &cliente.cpf);
  scanf("%d", &cliente.dataNasc[0]);
  scanf("%d", &cliente.dataNasc[1]);
  scanf("%d", &cliente.dataNasc[2]);
  scanf("%s", &cliente.sexo);
}