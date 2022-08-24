#include <stdio.h>
#include <string.h>>

typedef struct {
  char nome[20];
  char cpf[11];
  int dataNasc[3];
  char sexo;
  int erroNome;
  int erroCPF;
  int erroData;
  int erroSexo;
  int errou;
} dados_cliente;

dados_cliente cadastrarCliente();
int validarNome(char validNome[20]);
int validarCPF(char validCPF[11]);
int validarSexo(char validSexo);
int validarNascimento(int dia, int mes, int ano);

int main() {

  dados_cliente cliente;

  cliente = cadastrarCliente();
  
  if (cliente.errou == 1) {
    if (cliente.erroNome == 1)
      printf("\nErro na validação de nome\n");
    if (cliente.erroCPF == 1)
      printf("Erro na validação de CPF\n");
    if (cliente.erroData == 1)
      printf("Erro na validação de data de nascimento\n");
    if (cliente.erroSexo == 1)
      printf("Erro na validação de sexo\n");
  } else {
    printf("\nCadastro Realizado com Sucesso\n");
    printf("\nNome do Cliente: %s\n", cliente.nome);
    printf("CPF do Cliente: %s\n", cliente.cpf);
    printf("Data de nascimento do Cliente: %d/%d/%d\n", cliente.dataNasc[0],
           cliente.dataNasc[1], cliente.dataNasc[2]);
    printf("Sexo do Cliente: %c\n", cliente.sexo);
  }

  return 0;
}

dados_cliente cadastrarCliente() {

  dados_cliente clienteCAD;

  scanf("%s", clienteCAD.nome);
  scanf("%s", clienteCAD.cpf);
  scanf("%d", &clienteCAD.dataNasc[0]);
  scanf("%d", &clienteCAD.dataNasc[1]);
  scanf("%d", &clienteCAD.dataNasc[2]);
  scanf("%s", &clienteCAD.sexo);

  // Validações
  clienteCAD.erroNome = validarNome(clienteCAD.nome);
  clienteCAD.erroCPF = validarCPF(clienteCAD.cpf);
  clienteCAD.erroSexo = validarSexo(clienteCAD.sexo);
  clienteCAD.erroData = validarNascimento(clienteCAD.dataNasc[0], clienteCAD.dataNasc[1], clienteCAD.dataNasc[2]);

  if (clienteCAD.erroNome == 1 || clienteCAD.erroCPF == 1 ||
      clienteCAD.erroSexo == 1 || clienteCAD.erroData)
    clienteCAD.errou = 1;
  else
    clienteCAD.errou = 0;

  return clienteCAD;
}

int validarNome(char validNome[20]) {
  if (strlen(validNome) > 20)
    return 1;
  else
    return 0;
}

int validarCPF(char validCPF[11]) {
  int i;
  for (i = 0; validCPF[i] != '\0'; i++)
    if (i > 10)
      return 1;

  if (i < 10)
    return 1;

  return 0;
}

int validarSexo(char validSexo) {
  char valid[] = {'f', 'F', 'm', 'M', 'o', 'O'};
  int i = 0;

  for (i = 0; i < strlen(valid); i++)
    if (validSexo == valid[i])
      return 0;

  return 1;
}

int validarNascimento(int dia, int mes, int ano){
  if(dia > 31 || dia <= 0 || mes <=0 || mes > 12 || ano <= 0)
    return 1;
  else
  {
    if(mes != 2)
    {
      if(mes == 4 || mes == 6 || mes == 9 || mes == 11)
        if(dia > 30)
          return 1;
    }
    else
    {
      if(ano % 4 == 0 && ano % 100 !=0)
      {
        if(dia > 29)
          return 1;
      }
      else
        if(dia > 28)
          return 1;
    }
  }

  return 0;
}