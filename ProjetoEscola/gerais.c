#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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

//****************** Função de cadastrar uma nova pessoa(aluno ou professor), com validações para cada entrada
int insert_Pessoa(ficha_pessoa pessoa[], ficha_pessoa pessoa_repete[], int qtd, int qtd_repete){
  
  limparTela();

  //Todas as entradas são validadas em suas respectivas funções
  lerNome(pessoa, qtd);
  lerCPF(pessoa, pessoa_repete, qtd, qtd_repete, qtd);
  lerMatricula(pessoa, pessoa_repete, qtd, qtd_repete, qtd);
  lerDataNasc(pessoa, qtd);
  lerSexo(pessoa, qtd);

  // Confirmando um novo cadastro
  pessoa[qtd].cadastrado = true;
  qtd++;
  printf("\nCadastro Realizado com Sucesso\n");
  
  return qtd;
}

//****************** Função que faz exclusão lógica de uma pessoa, através da modificação de uma variavel que funciona como uma flag se a pessoa está cadastrado ou não. E diminui o contador de pessoas cadastradas
int exclude_Pessoa(ficha_pessoa pessoa[], int qtd){
  int op;
  int i=0, count=0;

  do{
    limparTela();
    listar_pessoas(pessoa, qtd);
    printf("(Digite 0 para voltar)\n");
    printf("Digite o #numero da pessoa que quer excluir: ");
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
      if(pessoa[i].cadastrado==true)
        count++;
      i++;
    }
    pessoa[i-1].cadastrado=false;
    qtd--;

    printf("\n***PESSOA #%d EXCLUIDA***\n", op);
  }

  return qtd;
}

//****************** Função que modifica o cadastro de uma pessoa, recebe um segundo vetor de struct para checar repetições em alunos e professores
void update_Pessoa(ficha_pessoa pessoa[], ficha_pessoa pessoa_repete[], int qtd, int qtd_repete){
  int op, op2, i, count;

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

  if(op!=0){
    do{
      limparTela();
      imprimir_linhas();
      printf("\nDigite o que deseja alterar:\n");
      printf("1. Nome\n2. CPF\n3. Matricula \n4. Data de Nascimento\n5. Sexo\n");
      printf("(Digite 0 para retornar ao menu anterior)\n\n");
      
      scanf("%d", &op2);
      getchar();

      if(op2!=0){
        // Encontrando o índice correto para alterar os dados
        i = 0;
        count = 0;
        while(count!=op){
          if(pessoa[i].cadastrado==true)
            count++;
          i++;
        }
        // Realizando as alterações diferentes para cada entrada no menu
        switch(op2){
          case 1: lerNome(pessoa, i-1); break;
          case 2: lerCPF(pessoa, pessoa_repete, qtd, qtd_repete, i-1); break;
          case 3: lerMatricula(pessoa, pessoa_repete, qtd, qtd_repete, i-1); break;
          case 4: lerDataNasc(pessoa, i-1); break;
          case 5: lerSexo(pessoa, i-1); break;
          default: printf("***ENTRADA INVALIDA***\n\n");
        }
      }
    }while(op2>5 || op2<=0);

    printf("\n***Cadastro Alterado***\n");
  }
}

//****************** Função que lista pessoas na ordem que foram cadastradas
void listar_pessoas(ficha_pessoa pessoas[], int qtd){
  int count;
  for(int i=0, count=0;count<qtd;i++)
    if(pessoas[i].cadastrado==true){
      printf("******#%d\n", count+1);
      printf("\nNome: %s\n", pessoas[i].nome);
      printf("\nCPF: %s\n", pessoas[i].cpf);
      printf("\nMatricula: %s\n", pessoas[i].matricula);
      printf("\nData de Nascimento: %s\n", pessoas[i].dataNasc);
      printf("\nSexo: %c\n\n", pessoas[i].sexo[0]);
  
      count++;
    }
}

//****************** SE DER TEMPO IMPLEMENTAR ESSE FUNÇÃO CORRIGIDA- Checa se há alguma string na struct aluno ou professor, dado um código de qual informação avaliar e o indice na struct a ser checada, retorna 2 caso encontre erro
int pessoaRepetida(ficha_pessoa pessoa[], ficha_pessoa pessoa_repete[], int cod, int qtd, int qtd_repete, int index){
  int i=0, j=0, repetido;

  // cod 0: CPF / 1: Matricula
  if(cod==0){
    // Checando se há CPF igual entre o mesmo tipo. ex: prof-prof, aluno-aluno
    for(i=0, repetido=2;i<qtd;i++)
      for(j=0;pessoa[i].cpf[j]!='\0';j++)
        if(pessoa[index].cpf[j]!=pessoa[i].cpf[j]){
          repetido = 0;
          break;
        }
    // Checando se há CPF igual entre tipos diferentes. ex: prof-aluno, aluno-prof
    if(repetido==0 && qtd_repete>0)
      for(i=0, repetido=2;i<qtd_repete;i++)
        for(j=0;pessoa_repete[i].cpf[j]!='\0';j++)
          if(pessoa[index].cpf[j]!=pessoa_repete[i].cpf[j]){
            repetido = 0;
            break;
          }
  } 
  else if(cod==1){
    // Checando se há Matricula igual entre o mesmo tipo. ex: prof-prof, aluno-aluno
    for(i=0, repetido=2;i<qtd;i++)
      for(j=0;pessoa[i].matricula[j]!='\0';j++)
        if(pessoa[index].matricula[j]!=pessoa[i].matricula[j]){
          repetido = 0;
          break;
        }
    // Checando se há Matricula igual entre tipos diferentes. ex: prof-aluno, aluno-prof
    if(repetido==0 && qtd_repete>0)
      for(i=0, repetido=2;i<qtd_repete;i++)
        for(j=0;pessoa_repete[i].matricula[j]!='\0';j++)
          if(pessoa[index].matricula[j]!=pessoa_repete[i].matricula[j]){
            repetido = 0;
            break;
          }
  }

  return repetido;
}