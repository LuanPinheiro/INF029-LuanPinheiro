#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define vet_size 1000

typedef struct{
  int matricula;
  char nome[52];
  char sexo[3];
  char dataNasc[12];
  char cpf[13];
  int cadastrado;
}ficha_pessoa;

typedef struct{
  char nome[52];
  char codigo[8];
  char semestre[8];
  char nome_p[52];
  int alunosMatriculados[vet_size];
  int qtdMat;
  int cadastrado;
}ficha_disciplina;

//****************** Se houver letras minusculas transformará em maiuscula para padronização do modelo das strings
void transformMaiusculo(char string[]){
  for(int i=0;string[i]!='\0';i++)
    if(string[i]>=97 && string[i]<=122)
      string[i] -= 32;
}

//****************** Pede um input de enter do usuário para limpar a tela
void limparTela(){
  printf("\nAPERTE ENTER PARA CONTINUAR\n");
  getchar();
  system("clear");
}

void imprimir_linhas(){
  printf("********************\n");
}

//****************** Usada para retirar o '\n' após inserir uma string[] via fgets()
void limparString(char string[]){
  for(int i=0;string[i]!='\0';i++)
      if(string[i]=='\n')
        string[i] = '\0';
}

//****************** Usada para limpar o buffer de entrada, em caso do usuario inserir uma string[n], e o usuário digitar uma string de tamanho > n
void limparBuffer(){
  char c = 'm';
  do{
    c = getchar();
  }while (c != '\n');
}

//****************** Retorna o tamanho de uma string[]
int tamString(char string[]){
  int i=0;

  while(string[i]!='\0')
    i++;
  
  return i;
}

//****************** Para leituras de menu com vetores sem shift após exclusão, retorna a posição real no vetor para alteração dos dados
int trueIndexPessoa(int input, ficha_pessoa pessoa[]){
  int count=0, i=0;
  
  while(count!=input){
    if(pessoa[i].cadastrado==true)
      count++;
    i++;
  }
  i--;
    
  return i;
}

//****************** Para leituras de menu com vetores sem shift após exclusão, retorna a posição real no vetor para alteração dos dados
int trueIndexDisciplina(int input, ficha_disciplina disciplinas[]){
  int count=0, i=0;
  
  while(count!=input){
    if(disciplinas[i].cadastrado==true)
      count++;
    i++;
  }
  i--;
    
  return i;
}

//****************** Busca se o aluno está matriculado na disciplina, retorna true se achar o aluno na matricula
int checkMatriculado(ficha_disciplina disciplinas[], ficha_pessoa alunos[], int index_disc, int index_alunos){
  for(int i=0, count=0;count<disciplinas[index_disc].qtdMat;i++){
    if(disciplinas[index_disc].alunosMatriculados[i]!=-1){
      if(disciplinas[index_disc].alunosMatriculados[i]==index_alunos){
        return true;
        break;
      }
      count++;
    }
  }


  return false;
}

//****************** Função que retorna o mês em inteiro dada a string de data
int mesInt (char validNasc[]){
  int identificador=0;
  int mes, str_count=0;
  
  for(int i=0;validNasc[i]!='\0';i++){ 
    if(validNasc[i] == '/'){
      if(identificador == 2)
        return false;
      else if(str_count == 0 || str_count > 2)
        return false;
      else if(identificador == 0)
          identificador++;
        else if(str_count == 2){
            if(identificador == 1){
              mes = ((validNasc[i-2] - 48) * 10) + (validNasc[i-1] - 48);
              return mes;
            }
        }
        else if (identificador == 1){
          mes = validNasc[i-1] - 48;
          return mes;
        }
      str_count = 0;
    }
    else
      str_count++;
  }

  return false;
}

//****************** Função que retorna o dia em inteiro dada a string de data
int diaInt(char validNasc[]){
  int dia, str_count=0;
  
  for(int i=0;validNasc[i]!='\0';i++){ 
    if(validNasc[i] == '/')
      if(str_count == 2){
        dia = ((validNasc[i-2] - 48) * 10) + (validNasc[i-1] - 48);
        break;
      }
      else{
        dia = validNasc[i-1] - 48;
        break;
      }
    else
      str_count++;
  }

  return dia;
}

//****************** Função que retorna o ano em inteiro dada a string de data
int anoInt(char validNasc[]){
  int ano, tam;
  
  tam = strlen(validNasc);
  tam--;
  ano = ((validNasc[tam-3]-48)*1000) + ((validNasc[tam-2]-48)*100) + ((validNasc[tam-1]-48)*10) + (validNasc[tam]-48);

  return ano;
}

void instrucoes(){
  limparTela();
  printf("ENTRADAS E EXEMPLOS:\n\n");
  
  printf("Nome:\n");
  printf("-> De ate 50 caracteres\n-> Apenas letras e espacos(nao pode haver espaco na primeira posicao)\n-> Todas as letras se tornarao maiusculas apos a entrada\n-> EXEMPLO: Luan Pinheiro\n\n");

  printf("Data de Nascimento:\n");
  printf("-> De ate 10 caracteres\n-> Apenas numeros e barra('/')\n-> Formatos aceitos: d/m/aaaa; dd/m/aaaa; d/mm/aaaa; dd/mm/aaaa; com ano maior que 1900 e menor que 2022\n-> EXEMPLO: 05/05/2001\n\n");

  printf("Sexo:\n");
  printf("-> De apenas 1 caractere\n-> Apenas f/m/o\n-> Apos a entrada o caracter se tornara maiusculo\n-> EXEMPLO: M\n\n");

  printf("CPF:\n");
  printf("-> De ate 11 caracteres\n-> Apenas numeros\n-> Deve seguir as regras reais de validacao de um CPF, portanto indique um CPF valido e UNICO\n-> EXEMPLO: 86409822529\n\n");

  printf("Codigo:\n");
  printf("-> De ate 6 caracteres\n-> Apenas letras nos 3 primeiros caracteres e apenas numeros nos 3 ultimos caracteres\n-> Todas as letras se tornarao maiusculas apos a entrada\n-> EXEMPLO: INF029\n\n");

  printf("Semestre:\n");
  printf("-> De ate 6 caracteres\n-> Apenas numeros e ponto('.')\n-> 4 numeros, 1 ponto e 1 ultimo numero\n-> EXEMPLO: 2022.2\n\n");
}

int AddMatricula(){
  static int matriculaAtual = 10000;
  matriculaAtual++;
  return matriculaAtual;
}