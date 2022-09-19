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
  int qtdMat;
  int cadastrado;
}ficha_disciplina;

// Menu dos professores, redireciona para todas as funções de cadastro e relatório de professores
int menu_Professores(ficha_pessoa professores[], int qtd_prof){
  int menu_prof;

  do{
    limparTela();
    imprimir_linhas();
    printf("\nMENU PROFESSORES\n\n");
    printf("1. Cadastro de Professor\n2. Listar Professores\n3. Listar Professores por Sexo\n4. Listar Professores por Nome\n5. Listar Professores por Data de Nascimento\n");
    printf("(Digite 0 para retornar ao menu anterior)\n\n");
    
    scanf("%d", &menu_prof);
    getchar();

    switch(menu_prof){
      case 0: break;
      case 1: qtd_prof = cadastro_Professores(professores, qtd_prof); break;
      case 2: if(qtd_prof>0)
        listar_pessoas(professores, qtd_prof);
        else
          printf("***NAO HA PROFESSORES CADASTRADOS***\n\n"); break;
      case 3: if(qtd_prof>0)
        listar_pessoas_sexo(professores, qtd_prof);
        else
          printf("***NAO HA PROFESSORES CADASTRADOS***\n\n"); break;
      case 4: break;
      case 5: break;
      default: printf("***ENTRADA INVALIDA***\n\n");
    }
  }while(menu_prof!=0);

  return qtd_prof;
}

// Menu que direciona para as funções de cadastro de professores
int cadastro_Professores(ficha_pessoa professores[], int qtd_prof){
  int menu_cadProf;

  do{
    limparTela();
    imprimir_linhas();
    printf("\nCADASTRO DE PROFESSORES\n\n");
    printf("1. Cadastrar Novo Professor\n2. Excluir Professor\n3. Atualizar Cadastro de Professor\n");
    printf("(Digite 0 para retornar ao menu anterior)\n\n");
    
    scanf("%d", &menu_cadProf);
    getchar();

    switch(menu_cadProf){
      case 0: break;
      case 1: qtd_prof = insert_Pessoa(professores, qtd_prof); break;
      case 2: if(qtd_prof>0)
        qtd_prof = exclude_Pessoa(professores, qtd_prof);
        else
          printf("***NAO HA PROFESSORES CADASTRADOS***\n\n"); break;
      case 3: if(qtd_prof>0)
        update_Pessoa(professores, qtd_prof);
        else
          printf("***NAO HA PROFESSORES CADASTRADOS***\n\n"); break;
      default: printf("***ENTRADA INVALIDA***\n\n");
    }
  }while(menu_cadProf!=0);

  return qtd_prof;
}