#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define vet_size 1000

typedef struct{
  char matricula[12];
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