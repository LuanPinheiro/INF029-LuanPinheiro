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

//****************** Menu dos alunos, redireciona para todas as funções de cadastro e relatório de alunos
int menu_Alunos(ficha_pessoa alunos[], ficha_pessoa professores[], ficha_disciplina disciplinas[], int qtd_alunos, int qtd_prof, int qtd_disciplina){
  int menu_alunos;

  do{
    limparTela();
    imprimir_linhas();
    printf("\nMENU ALUNOS\n\n");
    printf("1. Cadastro de Aluno\n2. Listar Alunos\n3. Listar Alunos por Sexo\n4. Listar Alunos por Nome\n5. Listar Alunos por Data de Nascimento\n6. Alunos Matriculados em Menos de 3 Disciplinas\n");
    printf("(Digite 0 para retornar ao menu anterior)\n\n");
    
    scanf("%d", &menu_alunos);
    getchar();

    switch(menu_alunos){
      case 0: break;
      
      case 1: qtd_alunos = cadastro_Alunos(alunos, professores, disciplinas, qtd_alunos, qtd_prof, qtd_disciplina); break;
      
      case 2: if(qtd_alunos>0)
        listar_pessoas(alunos, qtd_alunos);
        else
          printf("***NAO HA ALUNOS CADASTRADOS***\n\n"); break;
      
      case 3: if(qtd_alunos>0)
        listar_pessoas_sexo(alunos, qtd_alunos);
        else
          printf("***NAO HA ALUNOS CADASTRADOS***\n\n"); break;
      
      case 4: if(qtd_alunos>0)
        listarNome(alunos, qtd_alunos);
        else
          printf("***NAO HA ALUNOS CADASTRADOS***\n\n"); break;
      
      case 5: if(qtd_alunos>0)
        listarData(alunos, qtd_alunos);
        else
          printf("***NAO HA ALUNOS CADASTRADOS***\n\n"); break;
      
      case 6: if(qtd_alunos>0 && qtd_disciplina>0)
        listarcad3(alunos, disciplinas, qtd_alunos, qtd_disciplina);
        else{
          if(qtd_disciplina==0)
            printf("***NAO HA DISCIPLINAS CADASTRADAS***\n\n");
          if(qtd_alunos==0)
            printf("***NAO HA ALUNOS CADASTRADOS***\n\n");
        } break;
      
      default: printf("***ENTRADA INVALIDA***\n\n");
    }
  }while(menu_alunos!=0);

  return qtd_alunos;
}

//****************** Menu que direciona para as funções de cadastro de alunos
int cadastro_Alunos(ficha_pessoa alunos[], ficha_pessoa professores[], ficha_disciplina disciplinas[], int qtd_alunos, int qtd_prof, int qtd_disciplina){
  int menu_cadAluno;

  do{
    limparTela();
    imprimir_linhas();
    printf("\nCADASTRO DE ALUNOS\n\n");
    printf("1. Cadastrar Novo Aluno\n2. Excluir Aluno\n3. Atualizar Cadastro de Aluno\n");
    printf("(Digite 0 para retornar ao menu anterior)\n\n");
    
    scanf("%d", &menu_cadAluno);
    getchar();

    switch(menu_cadAluno){
      case 0: break;
      
      case 1: qtd_alunos = insert_Pessoa(alunos, professores, qtd_alunos, qtd_prof); break;
      
      case 2: if(qtd_alunos>0)
        qtd_alunos = exclude_Aluno(alunos, disciplinas, qtd_alunos, qtd_disciplina);
        else
          printf("***NAO HA ALUNOS CADASTRADOS***\n\n"); break;
      
      case 3: if(qtd_alunos>0)
        update_Pessoa(alunos, qtd_alunos);
        else
          printf("***NAO HA ALUNOS CADASTRADOS***\n\n"); break;
      
      default: printf("***ENTRADA INVALIDA***\n\n");
    }
  }while(menu_cadAluno!=0);
  
  return qtd_alunos;
}

//****************** Função que faz exclusão lógica de um aluno, através da modificação de uma variavel que funciona como uma flag se o aluno está cadastrado ou não. E diminui o contador de alunos cadastrados
int exclude_Aluno(ficha_pessoa alunos[], ficha_disciplina disciplinas[], int qtd_alunos, int qtd_disciplina){
  int op, i;

  do{
    limparTela();
    listar_pessoas(alunos, qtd_alunos);
    printf("(Digite 0 para voltar)\n");
    printf("Digite o #numero da pessoa que quer excluir: ");
    scanf("%d", &op);
    getchar();
    
    if(op<0 || op>qtd_alunos)
      printf("\n***ENTRADA INVALIDA***\n");
  }while(op<0 || op>qtd_alunos);

  if(op==0){
    printf("\n***VOLTANDO***\n");
  }
  else{
    i = trueIndexPessoa(op, alunos);

    for(int j=0, count=0;count<qtd_disciplina;j++)
      if(disciplinas[j].cadastrado==true){
        for(int k=0, count2=0;count2<disciplinas[j].qtdMat;k++)
          if(disciplinas[j].alunosMatriculados[k]!=-1){
            if(disciplinas[j].alunosMatriculados[k]==i){
              disciplinas[j].alunosMatriculados[k]=-1;
              disciplinas[j].qtdMat--;
            }
              
            count2++;
          }
        count++;
      }
    
    alunos[i].cadastrado=false;
    qtd_alunos--;

    printf("\n***ALUNO #%d EXCLUIDO***\n", op);
  }

  return qtd_alunos;
}