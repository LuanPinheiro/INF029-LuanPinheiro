#include <stdio.h>

typedef struct {
  char nome[60];
  char cpf[13];
  char dataNasc[20];
  char sexo;
  int erroNome;
  int erroCPF;
  int erroData;
  int erroSexo;
  int errou;
} dados_cliente;

dados_cliente cadastrarCliente();
int validarNome(char validNome[60]);
int validarCPF(char validCPF[13]);
int validarSexo(char validSexo);
int validarNascimento(char validNasc[]);
void limparString(char string[]);

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
    printf("Data de nascimento do Cliente: %s\n", cliente.dataNasc);
    printf("Sexo do Cliente: %c\n", cliente.sexo);
  }

  return 0;
}

dados_cliente cadastrarCliente() {

  dados_cliente clienteCAD;

  printf("Digite o nome: ");
  fgets(clienteCAD.nome, 60, stdin);
  limparString(clienteCAD.nome);

  printf("Digite o CPF: ");
  fgets(clienteCAD.cpf, 13, stdin);
  limparString(clienteCAD.cpf);

  printf("Digite a Data de Nascimento: ");
  fgets(clienteCAD.dataNasc, 20, stdin);
  limparString(clienteCAD.dataNasc);

  printf("Digite o sexo: ");
  clienteCAD.sexo = getchar();
  getchar();

  // Validações
  clienteCAD.erroNome = validarNome(clienteCAD.nome);
  clienteCAD.erroCPF = validarCPF(clienteCAD.cpf);
  clienteCAD.erroSexo = validarSexo(clienteCAD.sexo);
  clienteCAD.erroData = validarNascimento(clienteCAD.dataNasc);

  if (clienteCAD.erroNome == 1 || clienteCAD.erroCPF == 1 ||
      clienteCAD.erroSexo == 1 || clienteCAD.erroData)
    clienteCAD.errou = 1;
  else
    clienteCAD.errou = 0;

  return clienteCAD;
}

int validarNome(char validNome[60]) {
  int str_size = 0;
  
  for(int i=0;i!='\0';i++)
    str_size++;
  
  if (str_size > 20)
    return 1;
  else
    return 0;
}

int validarCPF(char validCPF[13]) {
  int i, soma1 = 0, soma2 = 0;
  int aux = 0;

  //Checando se o CPF tem 11 digitos
  for (i=0; validCPF[i]!='\0'; i++)
    if (i > 11)
      return 1;
  if (i < 11)
    return 1;

  //Checando se o CPF tem caracteres diferentes de numeros
  for (i=0; validCPF[i]!='\0'; i++)
    if ((validCPF[i] - 48) < 0 || (validCPF[i] - 48) > 9)
      return 1;
  
  //Checando se o CPF tem todos os numeros iguais, aux servindo de check, se achar numero diferente sai do for
  for(i=1;i!='\0';i++)
    if (validCPF[i] != validCPF[0])
    {
      aux = 1;
      break;
    }
  if (aux == 0)
    return 1;

  //Checando a validação do primeiro digito verificador, multiplicando os 9 primeiros numeros, decrescentemente por 10
  for(i=0, aux=10; i<9; i++, aux--)
    soma1 += (validCPF[i]-48) * aux;
  
  soma1 = (soma1 * 10) % 11;
  
  if(soma1 != (validCPF[9] - 48))
    return 1;

  //Checando a validação do segundo digito verificador, multiplicando os 10 numeros, decrescentemente por 11
  for(i=0, aux=11; i<10; i++, aux--)
    soma2 += (validCPF[i]-48) * aux;
  
  soma2 = (soma2 * 10) % 11;
  
  if(soma2 != (validCPF[10] - 48))
    return 1;

  return 0;
}

int validarSexo(char validSexo) {
  char valid[] = {'f', 'F', 'm', 'M', 'o', 'O'};
  int i = 0;
  
  for (i = 0; valid[i] != '\0'; i++)
    if (validSexo == valid[i])
      return 0;

  return 1;
}

int validarNascimento(char validNasc[]) {
  int dia, mes, ano, i;
  int identificador = 0;
  int aux, ano_atual = 2022;
  int str_count = 0;

  // Checando se a string de data é muito grande
  for(i=0;validNasc[i]!='\0';i++)
    str_count++;

  if(str_count>10)
    return 1;
  
  str_count = 0;
  
  // Conversão de Dias e Mêses em inteiros
  for(i=0;validNasc[i]!='\0';i++)
  { 
    if(validNasc[i] == '/')
    {
      if(str_count == 0 || str_count > 2)
        return 1;
      else 
        if(str_count == 2)
        {
          if(identificador == 0)
          {
            dia = ((validNasc[i-2] - 48) * 10) + (validNasc[i-1] - 48);
            identificador++;
          }
          else 
            if(identificador == 1)
            {
              mes = ((validNasc[i-2] - 48) * 10) + (validNasc[i-1] - 48);
              identificador++;
            }
        }
        else
          if (identificador == 0)
          {
            dia = validNasc[i-1] - 48;
            identificador++;
          }
          else 
            if (identificador == 1)
            {
              mes = validNasc[i-1] - 48;
              identificador++;
            }
      str_count = 0;
    }
    else
      str_count++;
  }
  
  //Conversão de Ano em Int
  for (ano = 0; str_count > 0; str_count--)
  {
    aux = validNasc[i - str_count] - 48;

    for (int x=0; x<str_count-1; x++)
      aux *= 10;

    ano += aux;
  }

  //Validação de Ano
  if(ano <= 0 || ano > ano_atual)
    return 1;

  //Validação de dias e meses
  if (dia > 31 || dia <= 0 || mes <= 0 || mes > 12 || ano <= 0)
    return 1;
  else 
  {
    if (mes != 2) {
      if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
        if (dia > 30)
          return 1;
    } 
    else 
    {
      if (ano % 4 == 0 && ano % 100 != 0) {
        if (dia > 29)
          return 1;
      } 
      else if (dia > 28)
        return 1;
    }
  }

  return 0;
}

void limparString(char string[]){
  for(int i=0;string[i] != '\0';i++)
      if(string[i] == '\n')
        string[i] = '\0';
}