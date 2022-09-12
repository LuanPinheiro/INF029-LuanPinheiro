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
  int erroNome;
  int erroCPF;
  int erroData;
  int erroSexo;
  int erroMat;
}ficha_pessoa;

typedef struct{
  char nome[52];
  char codigo[8];
  char semestre[8];
  char nome_p[52];
  int alunosMatriculados[vet_size];
  int erroNome;
  int erroCodigo;
  int erroSemestre;
  int erroNome_p;
  int errou;
}ficha_disciplina;

//****************** Menu dos alunos, redireciona para todas as funções de cadastro e relatório de alunos
int menu_Alunos(ficha_pessoa alunos[], ficha_pessoa professores[], int qtd_alunos, int qtd_prof){
  int menu_alunos;

  do{
    limparTela();
    imprimir_linhas();
    printf("\nMENU ALUNOS:\n");
    printf("1. Cadastrar Aluno\n2. Listar Alunos\n3. Listar Alunos por Sexo\n4. Listar Alunos por Nome\n5. Listar Alunos por Data de Nascimento\n6. Alunos Matriculados em Menos de 3 Disciplinas\n");
    printf("(Digite 0 para retornar ao menu anterior)\n\n");
    
    scanf("%d", &menu_alunos);
    getchar();

    switch(menu_alunos){
      case 0: break;
      case 1: qtd_alunos = cadastro_Alunos(alunos, professores, qtd_alunos, qtd_prof); break;
      case 2: if(qtd_alunos>0)
        listar_pessoas(alunos, qtd_alunos);
        else
          printf("***NAO HA ALUNOS CADASTRADOS***\n\n"); break;
      case 3: break;
      case 4: break;
      case 5: break;
      case 6: break;
      default: printf("***ENTRADA INVALIDA***\n\n");
    }
  }while(menu_alunos!=0);

  return qtd_alunos;
}

//****************** Menu que direciona para as funções de cadastro de alunos
int cadastro_Alunos(ficha_pessoa alunos[], ficha_pessoa professores[], int qtd_alunos, int qtd_prof){
  int menu_cadAluno;

  do{
    limparTela();
    imprimir_linhas();
    printf("\nCADASTRO DE ALUNOS:\n");
    printf("1. Cadastrar Novo Aluno\n2. Excluir Aluno\n3. Atualizar Cadastro de Aluno\n");
    printf("(Digite 0 para retornar ao menu anterior)\n\n");
    
    scanf("%d", &menu_cadAluno);
    getchar();

    switch(menu_cadAluno){
      case 0: break;
      case 1: qtd_alunos = insert_Pessoa(alunos, professores, qtd_alunos, qtd_prof); break;
      case 2: if(qtd_alunos>0)
        qtd_alunos = exclude_Pessoa(alunos, qtd_alunos);
        else
          printf("***NAO HA ALUNOS CADASTRADOS***\n\n"); break;
      case 3: if(qtd_alunos>0)
        update_Pessoa(alunos, professores, qtd_alunos, qtd_prof);
        else
          printf("***NAO HA ALUNOS CADASTRADOS***\n\n"); break;
      default: printf("***ENTRADA INVALIDA***\n\n");
    }
  }while(menu_cadAluno!=0);
  
  return qtd_alunos;
}