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

//****************** Função de cadastrar uma nova pessoa(aluno ou professor), com validações para cada entrada
int insert_Pessoa(ficha_pessoa pessoa[], ficha_pessoa pessoa_repete[], int qtd, int qtd_repete){
  
  limparTela();

  //Todas as entradas são validadas em suas respectivas funções
  lerNome(pessoa, qtd);
  lerCPF(pessoa, pessoa_repete, qtd, qtd_repete);
  pessoa[qtd].matricula = AddMatricula();
  lerDataNasc(pessoa, qtd);
  lerSexo(pessoa, qtd);

  // Confirmando um novo cadastro
  pessoa[qtd].cadastrado = true;
  qtd++;
  printf("\nCadastro Realizado com Sucesso\n");
  
  return qtd;
}

//****************** Função que modifica o cadastro de uma pessoa, recebe um segundo vetor de struct para checar repetições em alunos e professores
void update_Pessoa(ficha_pessoa pessoa[], int qtd){
  int op, op2, i;

  // Escolhendo uma pessoa cadastrada
  do{
    limparTela();
    listar_pessoas(pessoa, qtd);
    printf("Digite o #numero da pessoa para atualizar os dados:\n");
    printf("(Digite 0 para retornar ao menu anterior)\n\n");
    scanf("%d", &op);
    getchar();
    
    if(op<0 || op>qtd)
      printf("\n***ENTRADA INVALIDA***\n");
  }while(op<0 || op>qtd);

  // Continua o código caso escolha uma pessoa que tenha aparecido no menu
  if(op!=0){
    do{
      limparTela();
      imprimir_linhas();
      printf("\nDigite o que deseja alterar:\n");
      printf("1. Nome\n2. CPF\n3. Matricula \n4. Data de Nascimento\n5. Sexo\n");
      printf("(Digite 0 para retornar ao menu de cadastro)\n\n");
      
      scanf("%d", &op2);
      getchar();

      if(op2!=0){
        // Encontrando o índice correto para alterar os dados
        i = 0;trueIndexPessoa(op, pessoa);
        // Realizando as alterações diferentes para cada entrada no menu
        switch(op2){
          case 1: lerNome(pessoa, i); break;
          case 2: lerCPF(pessoa, i); break;
          case 3: pessoa[i].matricula = AddMatricula(); break;
          case 4: lerDataNasc(pessoa, i); break;
          case 5: lerSexo(pessoa, i); break;
          default: printf("***ENTRADA INVALIDA***\n\n");
        }
      }
    }while(op2>5 || op2<=0);

    printf("\n***Cadastro Alterado***\n");
  }
}

//****************** Função que printa os aniversariantes do mês, tendo como referencia uma entrada do usuário que indicará o mês a ser buscado
void aniversariantes (ficha_pessoa alunos[], ficha_pessoa professores[], int qtd_alunos, int qtd_prof){
  int i, count, count2, mes, mesPessoa;
  
  limparTela();

  // Escolhendo o mês a ser comparado com os outros
  do{
    printf("Digite o mês atual: ");
    scanf("%d",&mes);
    getchar();
    if(mes<1 || mes>12)
      printf("\n***ENTRADA INVALIDA***\n");
  }while(mes<1 || mes>12);

  // O programa printa todas as pessoas que tenham data de nascimento no mesmo mês da entrada anterior
  // Printando os alunos
  printf("\n***ALUNOS***\n\n");
  for(i=0, count=0, count2=0;count<qtd_alunos;i++){
    if(alunos[i].cadastrado==true){
      mesPessoa = mesInt(alunos[i].dataNasc);
      if(mesPessoa==mes){
        printf("******#%d\n", count2+1);
        printf("\nNome: %s\n", alunos[i].nome);
        printf("\nCPF: %s\n", alunos[i].cpf);
        printf("\nMatricula: %d\n", alunos[i].matricula);
        printf("\nData de Nascimento: %s\n", alunos[i].dataNasc);
        printf("\nSexo: %c\n\n", alunos[i].sexo[0]);
        count2++;
      }
      count++;
    }
  }
  if(count2==0)
    printf("\n***NAO HA ALUNOS QUE FAZEM ANIVERSARIO ESTE MES***\n");

  // Printando os professores
  printf("\n***PROFESSORES***\n\n");
  for(i=0, count=0, count2=0;count<qtd_prof;i++){
    if(professores[i].cadastrado==true){
      mesPessoa = mesInt(professores[i].dataNasc);
      if(mesPessoa==mes){
        printf("******#%d\n", count2+1);
        printf("\nNome: %s\n", professores[i].nome);
        printf("\nCPF: %s\n", professores[i].cpf);
        printf("\nMatricula: %d\n", professores[i].matricula);
        printf("\nData de Nascimento: %s\n", professores[i].dataNasc);
        printf("\nSexo: %c\n\n", professores[i].sexo[0]);
        count2++;
      }
      count++;
    }
  }
  if(count2==0)
    printf("\n***NAO HA PROFESSORES QUE FAZEM ANIVERSARIO ESTE MES***\n");
    
}

//****************** Checa se há algum CPF repetido entre professores e alunos
int CPF_Repetido(ficha_pessoa pessoa[], ficha_pessoa pessoa_repete[], int qtd, int qtd_repete){
  int i, count, repetido=false;

  for(i=0, count=0;count<qtd;i++)
    if(pessoa[i].cadastrado==true){
      if(strcmp(pessoa[qtd].cpf, pessoa[i].cpf)==0){
        repetido=2;
        break;
      }
      count++;
    }

  if(repetido==false)
    for(i=0, count=0;count<qtd_repete;i++)
      if(pessoa_repete[i].cadastrado==true){
        if(strcmp(pessoa[qtd].cpf, pessoa_repete[i].cpf)==0){
          repetido=2;
          break;
        }
        count++;
      }

  return repetido;
}