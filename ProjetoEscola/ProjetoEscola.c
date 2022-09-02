/*
*****Projeto Escola*****
Funcionalidades feitas:
Cadastro de Alunos (Matricula, Nome, Data de Nascimento, Sexo, CPF) []
Cadastro de Professores (Matricula, Nome, Data de Nascimento, Sexo, CPF) []
Cadastro de Disciplinas (Nome, Código, Semestre, Professor) []
Inserir/Excluir aluno em uma disciplina []

Relatórios:
  Listar Alunos []
  Listar Professores []
  Listar Disciplinas(sem informações de alunos) []
  Listar UMA disciplina(dados da disciplina e alunos matriculados) []
  Listar Alunos por Sexo []
  Listar Alunos por Nome []
  Listar Alunos por data de nascimento []
  Listar Professores por Sexo []
  Listar Professores por Nome []
  Listar Professores por data de nascimento []
  Aniversariantes do mês []
  Lista de pessoas(Professores e Alunos) a partir de uma string de busca de no minimo 3 caracteres []
  Lista de Alunos matriculados em menos de 3 disciplinas []
  Lista de Disciplinas, com nome do professor, que extrapolam 40 vagas []
*/

#include <stdio.h>
#define vet_size 10

typedef struct{
char matricula[12];
char nome[32];
char sexo[3];
char dataNasc[12];
char cpf[13];
int erroNome;
int erroCPF;
int erroData;
int erroSexo;
int errou;
}ficha_pessoa;

typedef struct{
char nome[32];
char codigo[8];
char semestre[8];
char nome_prof[32];
}ficha_disciplina;

//Menus e cadastros

// Alunos
int menu_Alunos(ficha_pessoa alunos[], int qtd_alunos);
int cadastro_Alunos(ficha_pessoa alunos[], int qtd_alunos);
int insert_Aluno(ficha_pessoa alunos[], int qtd_alunos);
void listar_Alunos(ficha_pessoa alunos[], int qtd_alunos);

// Professores
void menu_Professores();
void cadastro_Professores();

// Disciplinas
void menu_Disciplinas();
void cadastro_Disciplinas();

// Auxiliares
void limparString(char string[]);
void limparBuffer();
void imprimir_linhas();
int tamString(char string[]);

// Validações
int validarNome(char validNome[]);
int validarCPF(char validCPF[]);
int validarSexo(char validSexo);
int validarNascimento(char validNasc[]);

int main(){
  // Criando um sistema de menu, levando o usuário para setores do sistema, facilitando navegação
  int menu_main;

  ficha_pessoa alunos[vet_size];
  int qtd_alunos = 0;
  
  ficha_pessoa professores[vet_size];
  int qtd_prof = 0;
  
  ficha_disciplina disciplinas[vet_size];
  int qtd_disciplina = 0;
  
  do{
    imprimir_linhas();
    printf("\nMENU PRINCIPAL\n\n");
    printf("1. Alunos\n2. Professores\n3. Disciplinas\n4. Buscar Pessoas\n5. Aniversariantes do Mês\n");
    printf("(Digite 0 para fechar o programa)\n\n");
    
    scanf("%d", &menu_main);
    getchar();
    
    switch(menu_main){
      case 0: break;
      case 1: qtd_alunos = menu_Alunos(alunos, qtd_alunos); break;
      case 2: menu_Professores(); break;
      case 3: menu_Disciplinas(); break;
      case 4: break;
      case 5: break;
      default: if(menu_main!=0){
        printf("***ENTRADA INVALIDA***\n\n");
      }
    }
  }while(menu_main!=0);
  
  printf("\n\n******ENCERRANDO PROGRAMA******\n\n");
  return 0;
}

int menu_Alunos(ficha_pessoa alunos[], int qtd_alunos){
  int menu_alunos;

  do{
    imprimir_linhas();
    printf("\nMENU ALUNOS:\n");
    printf("1. Cadastrar Aluno\n2. Listar Alunos\n3. Listar Alunos por Sexo\n4. Listar Alunos por Nome\n5. Listar Alunos por Data de Nascimento\n6. Alunos Matriculados em Menos de 3 Disciplinas\n");
    printf("(Digite 0 para retornar ao menu anterior)\n\n");
    
    scanf("%d", &menu_alunos);
    getchar();

    switch(menu_alunos){
      case 0: break;
      case 1: qtd_alunos = cadastro_Alunos(alunos, qtd_alunos); break;
      case 2: listar_Alunos(alunos, qtd_alunos); break;
      case 3: break;
      case 4: break;
      case 5: break;
      case 6: break;
      default: if(menu_alunos!=0){
        printf("***ENTRADA INVALIDA***\n\n");
      }
    }
  }while(menu_alunos!=0);

  return qtd_alunos;
}

void menu_Professores(){
  int menu_prof;

  do{
    imprimir_linhas();
    printf("\nMENU PROFESSORES:\n");
    printf("1. Cadastrar Professor\n2. Listar Professores\n3. Listar Professores por Sexo\n4. Listar Professores por Nome\n5. Listar Professores por Data de Nascimento\n");
    printf("(Digite 0 para retornar ao menu anterior)\n\n");
    
    scanf("%d", &menu_prof);
    getchar();

    switch(menu_prof){
      case 0: break;
      case 1: cadastro_Professores(); break;
      case 2: break;
      case 3: break;
      case 4: break;
      case 5: break;
      default: if(menu_prof!=0){
        printf("***ENTRADA INVALIDA***\n\n");
      }
    }
  }while(menu_prof!=0);
}

void menu_Disciplinas(){
  int menu_disciplina;

  do{
    imprimir_linhas();
    printf("\nMENU DISCIPLINAS:\n");
    printf("1. Cadastrar Disciplina\n2. Listar Disciplinas\n3. Listar 1 Disciplina\n4. Disciplinas com mais de 40 matriculas\n5. Inserir Aluno em uma Disciplina\n6. Excluir Aluno em uma Disciplina\n");
    printf("(Digite 0 para retornar ao menu anterior)\n\n");
    
    scanf("%d", &menu_disciplina);
    getchar();

    switch(menu_disciplina){
      case 0: break;
      case 1: cadastro_Disciplinas(); break;
      case 2: break;
      case 3: break;
      case 4: break;
      case 5: break;
      case 6: break;
      default: if(menu_disciplina!=0){
        printf("***ENTRADA INVALIDA***\n\n");
      }
    }
  }while(menu_disciplina!=0);
}

int cadastro_Alunos(ficha_pessoa alunos[], int qtd_alunos){
  int menu_cadAluno;

  do{
    imprimir_linhas();
    printf("\nCADASTRO DE ALUNOS:\n");
    printf("1. Cadastrar Novo Aluno\n2. Excluir Aluno\n3. Atualizar Cadastro de Aluno\n");
    printf("(Digite 0 para retornar ao menu anterior)\n\n");
    
    scanf("%d", &menu_cadAluno);
    getchar();

    switch(menu_cadAluno){
      case 0: break;
      case 1: qtd_alunos = insert_Aluno(alunos, qtd_alunos); break;
      case 2: break;
      case 3: break;
      default: if(menu_cadAluno!=0){
        printf("***ENTRADA INVALIDA***\n\n");
      }
    }
  }while(menu_cadAluno!=0);
  
  return qtd_alunos;
}

void cadastro_Professores(){
  int menu_cadProf;

  do{
    imprimir_linhas();
    printf("\nCADASTRO DE PROFESSORES:\n");
    printf("1. Cadastrar Novo Professor\n2. Excluir Professor\n3. Atualizar Cadastro de Professor\n");
    printf("(Digite 0 para retornar ao menu anterior)\n\n");
    
    scanf("%d", &menu_cadProf);
    getchar();

    switch(menu_cadProf){
      case 0: break;
      case 1: break;
      case 2: break;
      case 3: break;
      default: if(menu_cadProf!=0){
        printf("***ENTRADA INVALIDA***\n\n");
      }
    }
  }while(menu_cadProf!=0);
}

void cadastro_Disciplinas(){
  int menu_cadDisciplina;

  do{
    imprimir_linhas();
    printf("\nCADASTRO DE DISCIPLINAS:\n");
    printf("1. Cadastrar Nova Disciplina\n2. Excluir Disciplina\n3. Atualizar Cadastro de Disciplina\n");
    printf("(Digite 0 para retornar ao menu anterior)\n\n");
    
    scanf("%d", &menu_cadDisciplina);
    getchar();

    switch(menu_cadDisciplina){
      case 0: break;
      case 1: break;
      case 2: break;
      case 3: break;
      default: if(menu_cadDisciplina!=0){
        printf("***ENTRADA INVALIDA***\n\n");
      }
    }
  }while(menu_cadDisciplina!=0);
}

int insert_Aluno(ficha_pessoa alunos[], int qtd_alunos){
  
  alunos[qtd_alunos].erroNome = 0;
  alunos[qtd_alunos].erroCPF = 0;
  alunos[qtd_alunos].erroData = 0;
  alunos[qtd_alunos].erroSexo = 0;

  int tam;

  //Todas as entradas já são validadas por tamanho antes de fazer as validações mais complexas
  printf("Digite o nome: ");
  fgets(alunos[qtd_alunos].nome, 22, stdin);
  limparString(alunos[qtd_alunos].nome);
  tam = tamString(alunos[qtd_alunos].nome);
  if(tam>20)
  {
    alunos[qtd_alunos].erroNome = 1;
    limparBuffer();
  }
  else if(tam == 0)
    alunos[qtd_alunos].erroNome = 1;

  printf("Digite o CPF: ");
  fgets(alunos[qtd_alunos].cpf, 13, stdin);
  limparString(alunos[qtd_alunos].cpf);
  tam = tamString(alunos[qtd_alunos].cpf);
  if(tam>11)
    limparBuffer();
  if(tam>11 || tam<11)
    alunos[qtd_alunos].erroCPF = 1;
  
  printf("Digite a Data de Nascimento: ");
  fgets(alunos[qtd_alunos].dataNasc, 12, stdin);
  limparString(alunos[qtd_alunos].dataNasc);
  tam = tamString(alunos[qtd_alunos].dataNasc);
  if(tam>10)
    limparBuffer();
  if(tam>10 || tam<5)
    alunos[qtd_alunos].erroData = 1;

  printf("Digite o sexo: ");
  fgets(alunos[qtd_alunos].sexo, 3, stdin);
  limparString(alunos[qtd_alunos].sexo);
  tam = tamString(alunos[qtd_alunos].sexo);
  if(tam>1)
  {
    alunos[qtd_alunos].erroSexo = 1;
    limparBuffer();
  }

  // Validações
  if(alunos[qtd_alunos].erroNome == 0)
    alunos[qtd_alunos].erroNome = validarNome(alunos[qtd_alunos].nome);
  if(alunos[qtd_alunos].erroCPF == 0)
    alunos[qtd_alunos].erroCPF = validarCPF(alunos[qtd_alunos].cpf);
  if(alunos[qtd_alunos].erroSexo == 0)
    alunos[qtd_alunos].erroSexo = validarSexo(alunos[qtd_alunos].sexo[0]);
  if(alunos[qtd_alunos].erroData == 0)
    alunos[qtd_alunos].erroData = validarNascimento(alunos[qtd_alunos].dataNasc);

  if (alunos[qtd_alunos].erroNome == 1 || alunos[qtd_alunos].erroCPF == 1 || alunos[qtd_alunos].erroSexo == 1 || alunos[qtd_alunos].erroData)
    alunos[qtd_alunos].errou = 1;
  else
    alunos[qtd_alunos].errou = 0;

  if(alunos[qtd_alunos].errou == 0)
    qtd_alunos++;

  if (alunos[qtd_alunos].errou == 1) {
    if (alunos[qtd_alunos].erroNome == 1)
      printf("Erro na validação de nome\n");
    if (alunos[qtd_alunos].erroCPF == 1)
      printf("Erro na validação de CPF\n");
    if (alunos[qtd_alunos].erroData == 1)
      printf("Erro na validação de data de nascimento\n");
    if (alunos[qtd_alunos].erroSexo == 1)
      printf("Erro na validação de sexo\n");
  } else
    printf("\nCadastro Realizado com Sucesso\n");
  
  return qtd_alunos;
}


void listar_Alunos(ficha_pessoa alunos[], int qtd_alunos){
  for(int i=0;i<qtd_alunos;i++){
    printf("\n\nNome: %s\n", alunos[qtd_alunos].nome);
    printf("\nData de Nascimento: %s\n", alunos[qtd_alunos].dataNasc);
    printf("\nSexo: %c\n", alunos[qtd_alunos].sexo[0]);
    printf("\nCPF: %s\n\n", alunos[qtd_alunos].cpf);
  }
}
//****** FUNÇÕES DE VALIDAÇÃO ******

//****** Checa se há caracteres além de letras e espaços na string
int validarNome(char validNome[]) {
  for(int i=0;validNome[i]!='\0';i++)
    if(validNome[i]>122 || validNome[i]!=32 && validNome[i]<65)
      return 1;

  return 0;
}

//****** Valida CPF de acordo com as regras do Ministério da Fazenda
int validarCPF(char validCPF[]) {
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

//****** Checa se o caracter é uma das entradas de sexo válidas
int validarSexo(char validSexo) {
  char valid[] = {'f', 'F', 'm', 'M', 'o', 'O'};
  int i = 0;
  
  for (i = 0; valid[i] != '\0'; i++)
    if (validSexo == valid[i])
      return 0;

  return 1;
}

//****** Checa se é uma data válida, inclui validação de ano bissexto
int validarNascimento(char validNasc[]) {
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

//****************************************************************************************************

//****** FUNÇÕES AUXILIARES ******
void imprimir_linhas(){
  printf("********************\n");
}

// Usada para retirar o '\n' após inserir uma string[] via fgets()
void limparString(char string[]){
  for(int i=0;string[i] != '\0';i++)
      if(string[i] == '\n')
        string[i] = '\0';
}

// Usada para limpar o buffer de entrada, em caso do usuario inserir uma string[n], e o usuário digitar uma string de tamanho > n
void limparBuffer(){
  char c = 'm';
  do{
    c = getchar();
  }while (c != '\n');
}

// Retorna o tamanho de uma string[]
int tamString(char string[]){
  int i=0;

  while(string[i]!='\0')
    i++;
  
  return i;
}