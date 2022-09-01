/* *****Projeto Escola*****
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

typedef struct{
char matricula[12];
char nome [32];
char sexo[3];
char dataNasc[12];
char cpf[13];
}ficha_pessoa;

void menu_Alunos();
void cadastro_Alunos();

void menu_Professores();
void cadastro_Professores();

void menu_Disciplinas();
void cadastro_Disciplinas();

void imprimir_linhas();

int main(){
  // criando um sistema de menu, levando o usuário para setores do sistema, facilitando navegação
  int menu_main;

  do{
    imprimir_linhas();
    printf("\nMENU PRINCIPAL\n\n");
    printf("1. Alunos\n2. Professores\n3. Disciplinas\n4. Buscar Pessoas\n5. Aniversariantes do Mês\n");
    printf("(Digite 0 para fechar o programa)\n\n");
    
    scanf("%d", &menu_main);
    getchar();
    
    switch(menu_main){
      case 0: break;
      case 1: menu_Alunos(); break;
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

void menu_Alunos(){
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
      case 1: cadastro_Alunos(); break;
      case 2: break;
      case 3: break;
      case 4: break;
      case 5: break;
      case 6: break;
      default: if(menu_alunos!=0){
        printf("***ENTRADA INVALIDA***\n\n");
      }
    }
  }while(menu_alunos!=0);
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

void cadastro_Alunos(){
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
      case 1: break;
      case 2: break;
      case 3: break;
      default: if(menu_cadAluno!=0){
        printf("***ENTRADA INVALIDA***\n\n");
      }
    }
  }while(menu_cadAluno!=0);
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

void imprimir_linhas(){
  printf("********************\n");
}