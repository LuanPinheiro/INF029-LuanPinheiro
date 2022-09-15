/*
*****Projeto Escola*****
Funcionalidades feitas:
Cadastro de Alunos (Matricula, Nome, Data de Nascimento, Sexo, CPF) [X]
Cadastro de Professores (Matricula, Nome, Data de Nascimento, Sexo, CPF) [X]
Cadastro de Disciplinas (Nome, Código, Semestre, Professor) []
Inserir/Excluir aluno em uma disciplina []

Relatórios:
  Listar Alunos [X]
  Listar Professores [X]
  Listar Disciplinas(sem informações de alunos) [X]
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

#include "alunos.h"
#include "professores.h"
#include "disciplinas.h"
#include "validacoes.h"
#include "gerais.h"
#include "auxiliares.h"
#include "leituras.h"

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
      case 1: qtd_alunos = menu_Alunos(alunos, professores, qtd_alunos, qtd_prof); break;
      case 2: qtd_prof = menu_Professores(professores, alunos, qtd_prof, qtd_alunos); break;
      case 3: qtd_disciplina = menu_Disciplinas(disciplinas, alunos, professores, qtd_disciplina, qtd_alunos, qtd_prof); break;
      case 4: break;
      case 5: break;
      default: printf("***ENTRADA INVALIDA***\n\n");
    }
  }while(menu_main!=0);
  
  printf("\n\n******ENCERRANDO PROGRAMA******\n\n");
  return 0;
}