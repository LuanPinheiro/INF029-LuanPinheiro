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

//****************** Menu das disciplinas, redireciona para todas as funções de cadastro e relatório de disciplinas
int menu_Disciplinas(ficha_disciplina disciplinas[], int qtd_disciplina){
  int menu_disciplina;

  do{
    limparTela();
    imprimir_linhas();
    printf("\nMENU DISCIPLINAS:\n");
    printf("1. Cadastrar Disciplina\n2. Listar Disciplinas\n3. Listar 1 Disciplina\n4. Disciplinas com mais de 40 matriculas\n5. Inserir Aluno em uma Disciplina\n6. Excluir Aluno em uma Disciplina\n");
    printf("(Digite 0 para retornar ao menu anterior)\n\n");
    
    scanf("%d", &menu_disciplina);
    getchar();

    switch(menu_disciplina){
      case 0: break;
      case 1: qtd_disciplina = cadastro_Disciplinas(disciplinas, qtd_disciplina); break;
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
int cadastro_Disciplinas(ficha_disciplina disciplinas[], int qtd_disciplina){
  int menu_cadDisciplina;

  do{
    limparTela();
    imprimir_linhas();
    printf("\nCADASTRO DE DISCIPLINAS:\n");
    printf("1. Cadastrar Nova Disciplina\n2. Excluir Disciplina\n3. Atualizar Cadastro de Disciplina\n");
    printf("(Digite 0 para retornar ao menu anterior)\n\n");
    
    scanf("%d", &menu_cadDisciplina);
    getchar();

    switch(menu_cadDisciplina){
      case 0: break;
      case 1: qtd_disciplina = insert_Disciplina(disciplinas, qtd_disciplina); break;
      case 2: break;
      case 3: break;
      default:  printf("***ENTRADA INVALIDA***\n\n");
      }
  }while(menu_cadDisciplina!=0);

  return qtd_disciplina;
}

//****************** Função de cadastrar uma nova disciplina, com validações para cada entrada
int insert_Disciplina(ficha_disciplina disciplinas[], int qtd_disciplina){
  
  limparTela();
  disciplinas[qtd_disciplina].erroNome = false;
  disciplinas[qtd_disciplina].erroCodigo = false;
  disciplinas[qtd_disciplina].erroSemestre = false;
  disciplinas[qtd_disciplina].erroNome_p = false;

  int tam;

  //Todas as entradas já são validadas por tamanho antes de fazer as validações mais complexas
  printf("Digite o nome da disciplina: ");
  fgets(disciplinas[qtd_disciplina].nome, 52, stdin);
  limparString(disciplinas[qtd_disciplina].nome);
  tam = tamString(disciplinas[qtd_disciplina].nome);
  if(tam>50){
    disciplinas[qtd_disciplina].erroNome = true;
    limparBuffer();
  } else if(tam<3)
    disciplinas[qtd_disciplina].erroNome = true;
  else
    transformMaiusculo(disciplinas[qtd_disciplina].nome);

  printf("Digite o codigo da disciplina: ");
  fgets(disciplinas[qtd_disciplina].codigo, 8, stdin);
  limparString(disciplinas[qtd_disciplina].codigo);
  tam = tamString(disciplinas[qtd_disciplina].codigo);
  if(tam>6)
    limparBuffer();
  if(tam!=6)
    disciplinas[qtd_disciplina].erroCodigo = true;
  disciplinas[qtd_disciplina].erroCodigo = codigoRepetido(disciplinas, qtd_disciplina);
  
  printf("Digite o semestre da disciplina: ");
  fgets(disciplinas[qtd_disciplina].semestre, 8, stdin);
  limparString(disciplinas[qtd_disciplina].semestre);
  tam = tamString(disciplinas[qtd_disciplina].semestre);
  if(tam>6)
    limparBuffer();
  if(tam!=6)
    disciplinas[qtd_disciplina].erroSemestre = true;

  printf("Digite o nome do professor da disciplina: ");
  fgets(disciplinas[qtd_disciplina].nome_p, 52, stdin);
  limparString(disciplinas[qtd_disciplina].nome_p);
  tam = tamString(disciplinas[qtd_disciplina].nome_p);
  if(tam>50){
    disciplinas[qtd_disciplina].erroNome_p = true;
    limparBuffer();
  } else if(tam<3)
    disciplinas[qtd_disciplina].erroNome_p = true;

  // Validações
  if(disciplinas[qtd_disciplina].erroNome == false)
    disciplinas[qtd_disciplina].erroNome = validarNome(disciplinas[qtd_disciplina].nome);
  if(disciplinas[qtd_disciplina].erroCodigo == false)
    disciplinas[qtd_disciplina].erroCodigo = validarCodigo(disciplinas[qtd_disciplina].codigo);
  if(disciplinas[qtd_disciplina].erroSemestre == false)
    disciplinas[qtd_disciplina].erroSemestre = validarSemestre(disciplinas[qtd_disciplina].semestre);
  //if(disciplinas[qtd_disciplina].erroNome_p == 0)
    //disciplinas[qtd_disciplina].erroNome_p = validarNascimento(disciplinas[qtd_disciplina].cpf);

  if (disciplinas[qtd_disciplina].erroNome == true || disciplinas[qtd_disciplina].erroCodigo != false || disciplinas[qtd_disciplina].erroSemestre == true || disciplinas[qtd_disciplina].erroNome_p)
    disciplinas[qtd_disciplina].errou = true;
  else
    disciplinas[qtd_disciplina].errou = false;

  if(disciplinas[qtd_disciplina].errou == false){
    printf("\nCadastro Realizado com Sucesso\n");
    qtd_disciplina++;
  } else{
    if (disciplinas[qtd_disciplina].erroNome == true)
      printf("Erro na validação de nome\n");
    
    if (disciplinas[qtd_disciplina].erroCodigo == true)
      printf("Erro na validação de Codigo\n");
    else if (disciplinas[qtd_disciplina].erroCodigo == 2)
      printf("Erro na validação de Codigo - CODIGO REPETIDO\n");
    
    if (disciplinas[qtd_disciplina].erroSemestre == true)
      printf("Erro na validação de Semestre\n");
    
    if (disciplinas[qtd_disciplina].erroNome_p == true)
      printf("Erro na validação de nome de professor\n");
  }
  
  return qtd_disciplina;
}

//****************** Checa se há algum código de disciplina repetido em outra disciplina já cadastrada, retorna 2 caso encontre alguma igual
int codigoRepetido(ficha_disciplina disciplina[], int index){
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
}

//****************** Lista as disciplinas na ordem q foram cadastradas
void listar_disciplinas(ficha_disciplina disciplinas[], int qtd){
  for(int i=0;i<qtd;i++){
    printf("\n\n******#%d\n", i);
    printf("\nNome da disciplina: %s\n", disciplinas[i].nome);
    printf("\nCodigo da disciplina: %s\n", disciplinas[i].codigo);
    printf("\nSemestre: %s\n", disciplinas[i].semestre);
    printf("\nNome do Professor: %s\n\n", disciplinas[i].nome_p);
  }
}