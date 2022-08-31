#include <stdio.h>

typedef struct {
  char nome[22];
  char cpf[13];
  char dataNasc[12];
  char sexo[3];
  int erroNome;
  int erroCPF;
  int erroData;
  int erroSexo;
  int errou;
} dados_cliente;

dados_cliente cadastrarCliente();
int validarNome(char validNome[22]);
int validarCPF(char validCPF[13]);
int validarSexo(char validSexo);
int validarNascimento(char validNasc[12]);
void limparString(char string[]);
int tamString(char string[]);
void limparBuffer(void);

int main() {

  int n;

  // Iniciando quantos alunos serão cadastrados
  do{
    printf("Digite quantos clientes quer cadastrar: ");
    scanf("%d", &n);
    getchar();
  }while(n<=0);
  
  dados_cliente cliente[n];

  // Preenchendo dados
  for(int i=0;i<n;i++)
  {
    printf("Insira os dados do cliente %d:\n", i+1);
    cliente[i] = cadastrarCliente();
    printf("\n");
  }
  

  // Print dos dados de cada cliente
  for(int i=0;i<n;i++){
    printf("Cliente %d: \n", i+1);
    printf("\n");
    if (cliente[i].errou == 1) {
    if (cliente[i].erroNome == 1)
      printf("Erro na validação de nome\n");
    if (cliente[i].erroCPF == 1)
      printf("Erro na validação de CPF\n");
    if (cliente[i].erroData == 1)
      printf("Erro na validação de data de nascimento\n");
    if (cliente[i].erroSexo == 1)
      printf("Erro na validação de sexo\n");
    } else {
      printf("\nCadastro Realizado com Sucesso\n");
      printf("\nNome do Cliente: %s\n", cliente[i].nome);
      printf("CPF do Cliente: %s\n", cliente[i].cpf);
      printf("Data de nascimento do Cliente: %s\n", cliente[i].dataNasc);
      printf("Sexo do Cliente: %c\n", cliente[i].sexo[0]);
    }
    printf("\n");
  }
  

  return 0;
}

dados_cliente cadastrarCliente() {

  dados_cliente clienteCAD;

  clienteCAD.erroNome = 0;
  clienteCAD.erroCPF = 0;
  clienteCAD.erroData = 0;
  clienteCAD.erroSexo = 0;

  int tam;

  printf("Digite o nome: ");
  fgets(clienteCAD.nome, 22, stdin);
  limparString(clienteCAD.nome);
  tam = tamString(clienteCAD.nome);
  if(tam>20)
  {
    clienteCAD.erroNome = 1;
    limparBuffer();
  }
  else if(tam == 0)
    clienteCAD.erroNome = 1;

  printf("Digite o CPF: ");
  fgets(clienteCAD.cpf, 13, stdin);
  limparString(clienteCAD.cpf);
  tam = tamString(clienteCAD.cpf);
  if(tam>11)
    limparBuffer();
  if(tam>11 || tam<11)
    clienteCAD.erroCPF = 1;
  
  printf("Digite a Data de Nascimento: ");
  fgets(clienteCAD.dataNasc, 12, stdin);
  limparString(clienteCAD.dataNasc);
  tam = tamString(clienteCAD.dataNasc);
  if(tam>10)
    limparBuffer();
  if(tam>10 || tam<5)
    clienteCAD.erroData = 1;

  printf("Digite o sexo: ");
  fgets(clienteCAD.sexo, 3, stdin);
  limparString(clienteCAD.sexo);
  tam = tamString(clienteCAD.sexo);
  if(tam>1)
  {
    clienteCAD.erroSexo = 1;
    limparBuffer();
  }
    
  // Validações
  if(clienteCAD.erroNome == 0)
    clienteCAD.erroNome = validarNome(clienteCAD.nome);
  if(clienteCAD.erroCPF == 0)
    clienteCAD.erroCPF = validarCPF(clienteCAD.cpf);
  if(clienteCAD.erroSexo == 0)
    clienteCAD.erroSexo = validarSexo(clienteCAD.sexo[0]);
  if(clienteCAD.erroData == 0)
    clienteCAD.erroData = validarNascimento(clienteCAD.dataNasc);

  if (clienteCAD.erroNome == 1 || clienteCAD.erroCPF == 1 ||
      clienteCAD.erroSexo == 1 || clienteCAD.erroData)
    clienteCAD.errou = 1;
  else
    clienteCAD.errou = 0;

  return clienteCAD;
}

int validarNome(char validNome[22]) {
  int str_size = 1;
  
  for(int i=0;validNome[i]!='\0';i++)
    str_size++;

  
  if (str_size > 20)
    return 1;
  else
    return 0;
}

int validarCPF(char validCPF[13]) {
  int i, soma1 = 0, soma2 = 0;
  int aux = 0;

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

int validarNascimento(char validNasc[12]) {
  int dia, mes, ano, i;
  int identificador = 0;
  int aux, ano_atual = 2022;
  int str_count = 0;
  
  // Conversão de Dias e Mêses em inteiros
  for(i=0;validNasc[i]!='\0';i++)
  { 
    if(validNasc[i] == '/')
    {
      if(identificador == 2)
        return 1;
      else if(str_count == 0 || str_count > 2)
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

void limparBuffer(void){
  char c = 'm';
  do{
    c = getchar();
  }while (c != '\n');
}

int tamString(char string[]){
  int i=0;

  while(string[i]!='\0')
    i++;
  
  return i;
}