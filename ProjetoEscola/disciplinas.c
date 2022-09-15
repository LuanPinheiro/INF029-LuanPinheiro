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

//****************** Menu das disciplinas, redireciona para todas as funções de cadastro e relatório de disciplinas
int menu_Disciplinas(ficha_disciplina disciplinas[], ficha_pessoa alunos[], ficha_pessoa professores[], int qtd_disciplina, int qtd_alunos, int qtd_prof){
  int menu_disciplina;

  do{
    limparTela();
    imprimir_linhas();
    printf("\nMENU DISCIPLINAS\n\n");
    printf("1. Cadastrar Disciplina\n2. Listar Disciplinas\n3. Listar 1 Disciplina\n4. Disciplinas com mais de 40 matriculas\n5. Inserir Aluno em uma Disciplina\n6. Excluir Aluno em uma Disciplina\n");
    printf("(Digite 0 para retornar ao menu anterior)\n\n");
    
    scanf("%d", &menu_disciplina);
    getchar();

    switch(menu_disciplina){
      case 0: break;
      case 1: qtd_disciplina = cadastro_Disciplinas(disciplinas, professores, qtd_disciplina, qtd_prof); break;
      case 2: if(qtd_disciplina>0)
        listar_disciplinas(disciplinas, qtd_disciplina);
        else
          printf("***NAO HA DISCIPLINAS CADASTRADAS***\n\n"); break;
      case 3: break;
      case 4: break;
      case 5: break;
      case 6: break;
      default: printf("***ENTRADA INVALIDA***\n\n"); break;
    }
  }while(menu_disciplina!=0);

  return qtd_disciplina;
}

//****************** Menu que direciona para as funções de cadastro de disciplinas
int cadastro_Disciplinas(ficha_disciplina disciplinas[], ficha_pessoa professores[], int qtd_disciplina, int qtd_prof){
  int menu_cadDisciplina;

  do{
    limparTela();
    imprimir_linhas();
    printf("\nCADASTRO DE DISCIPLINAS\n\n");
    printf("1. Cadastrar Nova Disciplina\n2. Excluir Disciplina\n3. Atualizar Cadastro de Disciplina\n");
    printf("(Digite 0 para retornar ao menu anterior)\n\n");
    
    scanf("%d", &menu_cadDisciplina);
    getchar();

    switch(menu_cadDisciplina){
      case 0: break;
      case 1: if(qtd_prof>0)
        qtd_disciplina = insert_Disciplina(disciplinas, professores, qtd_disciplina, qtd_prof);
        else
          printf("***NAO HA PROFESSORES CADASTRADOS***\n\n"); break;
      case 2: if(qtd_disciplina>0)
        qtd_disciplina = exclude_Disciplina(disciplinas, qtd_disciplina);
        else
          printf("***NAO HA DISCIPLINAS CADASTRADAS***\n\n"); break;
      case 3: break;
      default:  printf("***ENTRADA INVALIDA***\n\n");
      }
  }while(menu_cadDisciplina!=0);

  return qtd_disciplina;
}

//****************** Função de cadastrar uma nova disciplina, com validações para cada entrada
int insert_Disciplina(ficha_disciplina disciplinas[], ficha_pessoa professores[], int qtd_disciplina, int qtd_prof){
  
  limparTela();
  
  // Todas as entradas já são validadas em suas respectivas funções
  lerNomeDisc(disciplinas, qtd_disciplina);
  lerCodigoDisc(disciplinas, qtd_disciplina);
  lerSemestreDisc(disciplinas, qtd_disciplina);
  ProfessorDisc(disciplinas, professores, qtd_disciplina, qtd_prof);

  // Confirmando um novo cadastro
  disciplinas[qtd_disciplina].cadastrado = true;
  qtd_disciplina++;
  printf("\nCadastro Realizado com Sucesso\n");
  
  
  return qtd_disciplina;
}

//****************** Função que adiciona um professor a disciplina, aparece a lista de professores e o usuário deve escolher um professor válido
void ProfessorDisc(ficha_disciplina disciplinas[], ficha_pessoa professores[], int index, int qtd_prof){
  int op, i=0, count=0;

  // Printa os professores cadastrados
  printf("\n\n");
  listar_pessoas(professores, qtd_prof);

  // Escolhendo um professor válido
  do{
    printf("Digite o #numero do professor para a disciplina %s: ", disciplinas[index].codigo);
    scanf("%d", &op);
    getchar();
    
    if(op<1 || op>qtd_prof)
      printf("\n***ENTRADA INVALIDA***\n");
  }while(op<1 || op>qtd_prof);
  
  // Achando o índice correto para passar o nome
  while(count!=op){
      if(professores[i].cadastrado==true)
        count++;
      i++;
    }
  
  // Passando o nome do professor para a struct de disciplinas
  strcpy(disciplinas[index].nome_p, professores[i-1].nome);
}

//****************** Função que faz exclusão lógica de uma pessoa, através da modificação de uma variavel que funciona como uma flag se a pessoa está cadastrado ou não. E diminui o contador de pessoas cadastradas
int exclude_Disciplina(ficha_disciplina disciplinas[], int qtd){
  int op;
  int i=0, count=0;

  do{
    limparTela();
    listar_disciplinas(disciplinas, qtd);
    printf("(Digite 0 para voltar)\n");
    printf("Digite o #numero da disciplina que quer excluir: ");
    scanf("%d", &op);
    getchar();
    
    if(op<0 || op>qtd)
      printf("\n***ENTRADA INVALIDA***\n");
  }while(op<0 || op>qtd);

  if(op==0){
    printf("\n***VOLTANDO***\n");
  }
  else{
    while(count!=op){
      if(disciplinas[i].cadastrado==true)
        count++;
      i++;
    }
    disciplinas[i-1].cadastrado=false;
    qtd--;

    printf("\n***DISCIPLINA #%d EXCLUIDA***\n", op);
  }

  return qtd;
}

//****************** SE DER TEMPO IMPLEMENTAR ESSA FUNÇÃO CORRIGIDA - Checa se há algum código de disciplina repetido em outra disciplina já cadastrada, retorna 2 caso encontre alguma igual
/*int codigoRepetido(ficha_disciplina disciplina[], int index){
  int repetido = false;

  transformMaiusculo(disciplina[index].codigo);
  
  for(int i=0;i<index;i++){
    for(int j=0;disciplina[i].codigo[j]!='\0';j++){
      if(disciplina[index].codigo[j]!=disciplina[i].codigo[j]){
        repetido = false;
        break;
      }
    }
    repetido = 2;
  }

  return repetido;
}*/

//****************** Lista as disciplinas na ordem q foram cadastradas
void listar_disciplinas(ficha_disciplina disciplinas[], int qtd){
  int count;
  for(int i=0, count=0;count<qtd;i++)
    if(disciplinas[i].cadastrado==true)
    {
      printf("\n\n******#%d\n", count+1);
      printf("\nNome da disciplina: %s\n", disciplinas[i].nome);
      printf("\nCodigo da disciplina: %s\n", disciplinas[i].codigo);
      printf("\nSemestre: %s\n", disciplinas[i].semestre);
      printf("\nNome do Professor: %s\n\n", disciplinas[i].nome_p);

      count++;
    }
}