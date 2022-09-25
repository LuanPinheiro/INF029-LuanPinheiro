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

// Menu dos professores, redireciona para todas as funções de cadastro e relatório de professores
int menu_Professores(ficha_pessoa professores[], ficha_pessoa alunos[], ficha_disciplina disciplinas[], int qtd_prof, int qtd_alunos, int qtd_disciplina){
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
      
      case 1: qtd_prof = cadastro_Professores(professores, alunos, disciplinas, qtd_prof, qtd_alunos, qtd_disciplina); break;
      
      case 2: if(qtd_prof>0)
        listar_pessoas(professores, qtd_prof);
        else
          printf("***NAO HA PROFESSORES CADASTRADOS***\n\n"); break;
      
      case 3: if(qtd_prof>0)
        listar_pessoas_sexo(professores, qtd_prof);
        else
          printf("***NAO HA PROFESSORES CADASTRADOS***\n\n"); break;
      
      case 4: if(qtd_prof>0)
        listarNome(professores, qtd_prof);
        else
          printf("***NAO HA PROFESSORES CADASTRADOS***\n\n"); break;
      
      case 5: if(qtd_prof>0)
        listarData(professores, qtd_prof);
        else
          printf("***NAO HA PROFESSORES CADASTRADOS***\n\n"); break;
      
      default: printf("***ENTRADA INVALIDA***\n\n");
    }
  }while(menu_prof!=0);

  return qtd_prof;
}

// Menu que direciona para as funções de cadastro de professores
int cadastro_Professores(ficha_pessoa professores[], ficha_pessoa alunos[], ficha_disciplina disciplinas[], int qtd_prof, int qtd_alunos, int qtd_disciplina){
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
      
      case 1: qtd_prof = insert_Pessoa(professores, alunos, qtd_prof, qtd_alunos); break;
      
      case 2: if(qtd_prof>0)
        qtd_prof = exclude_Professor(professores, disciplinas, qtd_prof, qtd_disciplina);
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

//****************** Função que faz exclusão lógica de um professor, através da modificação de uma variavel que funciona como uma flag se o professor está cadastrado ou não. E diminui o contador de professores cadastrados, e retira seu nome das disciplinas em que esteja cadastrado
int exclude_Professor(ficha_pessoa professores[], ficha_disciplina disciplinas[], int qtd_prof, int qtd_disciplina){
  int op, i;

  do{
    limparTela();
    listar_pessoas(professores, qtd_prof);
    printf("(Digite 0 para voltar)\n");
    printf("Digite o #numero da pessoa que quer excluir: ");
    scanf("%d", &op);
    getchar();
    
    if(op<0 || op>qtd_prof)
      printf("\n***ENTRADA INVALIDA***\n");
  }while(op<0 || op>qtd_prof);

  if(op==0){
    printf("\n***VOLTANDO***\n");
  }
  else{
    i = trueIndexPessoa(op, professores);

    for(int j=0, count=0;count<qtd_disciplina;j++)
      if(disciplinas[j].cadastrado==true){
        if(strcmp(disciplinas[j].nome_p, professores[i].nome)==0)
          strcpy(disciplinas[j].nome_p, "(PROFESSOR EXCLUIDO)");
        count++;
      }
      
    professores[i].cadastrado=false;
    qtd_prof--;

    printf("\n***PROFESSOR #%d EXCLUIDO***\n", op);
  }

  return qtd_prof;
}