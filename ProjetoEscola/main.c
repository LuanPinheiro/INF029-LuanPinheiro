/*
*****Projeto Escola*****
Funcionalidades feitas:
Cadastro de Alunos (Matricula, Nome, Data de Nascimento, Sexo, CPF) [X]
Cadastro de Professores (Matricula, Nome, Data de Nascimento, Sexo, CPF) [X]
Cadastro de Disciplinas (Nome, Código, Semestre, Professor) [X]
Inserir/Excluir aluno em uma disciplina [X]

Relatórios:
  Listar Alunos [X]
  Listar Professores [X]
  Listar Disciplinas(sem informações de alunos) [X]
  Listar UMA disciplina(dados da disciplina e alunos matriculados) [X]
  Listar Alunos por Sexo [X]
  Listar Alunos por Nome []
  Listar Alunos por data de nascimento []
  Listar Professores por Sexo [X]
  Listar Professores por Nome []
  Listar Professores por data de nascimento []
  Aniversariantes do mês [X]
  Lista de pessoas(Professores e Alunos) a partir de uma string de busca de no minimo 3 caracteres [X]
  Lista de Alunos matriculados em menos de 3 disciplinas [X]
  Lista de Disciplinas, com nome do professor, que extrapolam 40 vagas [X]
*/

// FAZER UMA FUNÇÃO QUE PRINTE OS FORMATOS ACEITOS POR CADA ENTRADA
// gcc main.c alunos.c auxiliares.c disciplinas.c gerais.c leituras.c listar.c professores.c validacoes.c -o projetoescola

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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

#include "alunos.h"
#include "professores.h"
#include "disciplinas.h"
#include "validacoes.h"
#include "gerais.h"
#include "auxiliares.h"
#include "leituras.h"
#include "listar.h"

int main(){
  // Criando um sistema de menu, levando o usuário para setores do sistema, facilitando navegação.
  // A base do sistema é navegar por submenus, podendo ir e voltar a todo momento, usando a quantidade de alunos, professores e disciplinas como referência de retorno para as funções
  int menu_main;
  
  ficha_pessoa alunos[vet_size];
  int qtd_alunos = 0;
  
  ficha_pessoa professores[vet_size];
  int qtd_prof = 0;
  
  ficha_disciplina disciplinas[vet_size];
  int qtd_disciplina = 0;

  //Para debug
  strcpy(alunos[0].nome, "LUAN");
  alunos[0].matricula = 10000;
  strcpy(alunos[0].cpf, "86409822529");
  strcpy(alunos[0].dataNasc, "5/5/2001");
  strcpy(alunos[0].sexo, "M");
  alunos[0].cadastrado = true;
  qtd_alunos++;

  strcpy(professores[0].nome, "RENATO");
  professores[0].matricula = 9999;
  strcpy(professores[0].cpf, "52998224725");
  strcpy(professores[0].dataNasc, "2/10/1985");
  strcpy(professores[0].sexo, "M");
  professores[0].cadastrado = true;
  qtd_prof++;

  do{
    limparTela();
    imprimir_linhas();
    printf("\nMENU PRINCIPAL\n\n");
    printf("1. Alunos\n2. Professores\n3. Disciplinas\n4. Buscar Pessoas\n5. Aniversariantes do Mês\n");
    printf("(Digite 0 para fechar o programa)\n\n");
    
    scanf("%d", &menu_main);
    getchar();
    
    switch(menu_main){
      case 0: break;
      case 1: qtd_alunos = menu_Alunos(alunos, disciplinas, qtd_alunos, qtd_disciplina); break;
      case 2: qtd_prof = menu_Professores(professores, qtd_prof); break;
      case 3: qtd_disciplina = menu_Disciplinas(disciplinas, alunos, professores, qtd_disciplina, qtd_alunos, qtd_prof); break;
      case 4: busca(alunos, professores, qtd_alunos, qtd_prof); break;
      case 5: aniversariantes(alunos, professores, qtd_alunos, qtd_prof); break;
      default: printf("***ENTRADA INVALIDA***\n\n");
    }
  }while(menu_main!=0);
  
  printf("\n\n******ENCERRANDO PROGRAMA******\n\n");
  return 0;
}