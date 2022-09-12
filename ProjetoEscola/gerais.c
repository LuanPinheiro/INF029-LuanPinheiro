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

//****************** Função de cadastrar uma nova pessoa(aluno ou professor), com validações para cada entrada
int insert_Pessoa(ficha_pessoa pessoa[], ficha_pessoa pessoa_repete[], int qtd, int qtd_repete){
  
  limparTela();
  pessoa[qtd].erroNome = false;
  pessoa[qtd].erroCPF = false;
  pessoa[qtd].erroData = false;
  pessoa[qtd].erroSexo = false;
  pessoa[qtd].erroMat = false;

  int tam;

  //Todas as entradas já são validadas por tamanho antes de fazer as validações mais complexas
  lerNome(pessoa, qtd);
  lerCPF(pessoa, pessoa_repete, qtd, qtd_repete);
    

  printf("Digite a Matricula: ");
  fgets(pessoa[qtd].matricula, 12, stdin);
  limparString(pessoa[qtd].matricula);
  tam = tamString(pessoa[qtd].matricula);
  if(tam!=10){
    pessoa[qtd].erroMat = true;
    if(tam>10)
      limparBuffer();
  }
  else if(qtd>0)
    pessoa[qtd].erroMat = pessoaRepetida(pessoa, pessoa_repete, 1, qtd, qtd_repete);
  
  printf("Digite a Data de Nascimento: ");
  fgets(pessoa[qtd].dataNasc, 12, stdin);
  limparString(pessoa[qtd].dataNasc);
  tam = tamString(pessoa[qtd].dataNasc);
  if(tam>10)
    limparBuffer();
  if(tam>10 || tam<5)
    pessoa[qtd].erroData = true;

  printf("Digite o sexo: ");
  fgets(pessoa[qtd].sexo, 3, stdin);
  limparString(pessoa[qtd].sexo);
  tam = tamString(pessoa[qtd].sexo);
  if(tam!=1){
    pessoa[qtd].erroSexo = true;
    if(tam>1)
      limparBuffer();
  }

  
  // Validações
  if(pessoa[qtd].erroNome == false)
    pessoa[qtd].erroNome = validarNome(pessoa[qtd].nome);
  if(pessoa[qtd].erroCPF == false)
    pessoa[qtd].erroCPF = validarCPF(pessoa[qtd].cpf);
  if(pessoa[qtd].erroSexo == false)
    pessoa[qtd].erroSexo = validarSexo(pessoa[qtd].sexo[0]);
  if(pessoa[qtd].erroData == false)
    pessoa[qtd].erroData = validarNascimento(pessoa[qtd].dataNasc);
  if(pessoa[qtd].erroMat == false)
    pessoa[qtd].erroMat = validarMatricula(pessoa[qtd].matricula);

  if(pessoa[qtd].erroNome == true || pessoa[qtd].erroCPF != false || pessoa[qtd].erroSexo == true || pessoa[qtd].erroData == true || pessoa[qtd].erroMat != false)
    pessoa[qtd].cadastrado = false;
  else
    pessoa[qtd].cadastrado = true;

  if(pessoa[qtd].cadastrado == true){
    printf("\nCadastro Realizado com Sucesso\n");
    qtd++;
  } else{
    if(pessoa[qtd].erroNome == true)
      printf("Erro na validação de nome\n");
    
    if(pessoa[qtd].erroCPF == 1)
      printf("Erro na validação de CPF\n");
    else if(pessoa[qtd].erroCPF == 2)
      printf("Erro na validação de CPF - CPF REPETIDO\n");
    
    if(pessoa[qtd].erroMat == 1)
      printf("Erro na validação de matricula\n");
    else if(pessoa[qtd].erroMat == 2)
      printf("Erro na validação de matricula - MATRICULA REPETIDA\n");
    
    if(pessoa[qtd].erroData == true)
      printf("Erro na validação de data de nascimento\n");
    
    if(pessoa[qtd].erroSexo == true)
      printf("Erro na validação de sexo\n");
  }
  
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
    printf("Digite o #numero pessoa que quer excluir: ");
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
  int op, op2, tam, i=0, count=0;
  char aux[52];
  
  pessoa[qtd].erroNome = false;
  pessoa[qtd].erroCPF = false;
  pessoa[qtd].erroData = false;
  pessoa[qtd].erroSexo = false;
  pessoa[qtd].erroMat = false;

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
  
      switch(op2){
        case 0: break;
        case 1: printf("Digite o nome: ");
                fgets(aux, 52, stdin);
                limparString(aux);
                tam = tamString(aux);
                if(tam>50){
                  pessoa[qtd].erroNome = true;
                  limparBuffer();
                } else if(tam<3)
                  pessoa[qtd].erroNome = true;
                else
                  transformMaiusculo(aux);
                if(pessoa[qtd].erroNome == false)
                  pessoa[qtd].erroNome = validarNome(aux); break;
        case 2: printf("Digite o CPF: ");
                fgets(aux, 13, stdin);
                limparString(aux);
                tam = tamString(aux);
                if(tam!=11){
                  pessoa[qtd].erroCPF = true;
                  if(tam>11)
                  limparBuffer();
                }
                else
                  pessoa[qtd].erroCPF = pessoaRepetida(pessoa, pessoa_repete, 0, qtd, qtd_repete);
                if(pessoa[qtd].erroCPF == false)
                  pessoa[qtd].erroCPF = validarCPF(aux); break;
        case 3: break;
        case 4: break;
        case 5: break;
        default: printf("***ENTRADA INVALIDA***\n\n");
      }
    }while(op2>5 || op2<0);

    if(op2!=0){
      if(pessoa[qtd].erroNome == true || pessoa[qtd].erroCPF != false || pessoa[qtd].erroSexo == true || pessoa[qtd].erroData == true || pessoa[qtd].erroMat != false)
        pessoa[qtd].cadastrado = false;
      else
        pessoa[qtd].cadastrado = true;
      
      if(pessoa[qtd].cadastrado == true){
        printf("\nCadastro Modificado com Sucesso\n");
        while(count!=op){
          if(pessoa[i].cadastrado==true)
            count++;
          i++;
        }
        switch(op2){
          case 1: strcpy(pessoa[i-1].nome, aux); break;
          case 2: strcpy(pessoa[i-1].cpf, aux); break;
          case 3: strcpy(pessoa[i-1].matricula, aux); break;
          case 4: strcpy(pessoa[i-1].dataNasc, aux); break;
          case 5: strcpy(pessoa[i-1].sexo, aux); break;
          default: break;
        }
      }
      else{
        if(pessoa[qtd].erroNome == true)
          printf("Erro na validação de nome\n");
        else if(pessoa[qtd].erroCPF == 1)
            printf("Erro na validação de CPF\n");
        else if(pessoa[qtd].erroCPF == 2)
          printf("Erro na validação de CPF - CPF REPETIDO\n");
        else if(pessoa[qtd].erroMat == 1)
          printf("Erro na validação de matricula\n");
        else if(pessoa[qtd].erroMat == 2)
          printf("Erro na validação de matricula - MATRICULA REPETIDA\n");
        else if(pessoa[qtd].erroData == true)
          printf("Erro na validação de data de nascimento\n");
        else if(pessoa[qtd].erroSexo == true)
          printf("Erro na validação de sexo\n");
      }
    }
  }
}

//****************** Função que lista pessoas na ordem que foram cadastradas
void listar_pessoas(ficha_pessoa pessoas[], int qtd){
  int count;
  for(int i=0, count=0;count<qtd;i++)
    if(pessoas[i].cadastrado==true){
      printf("\n\n******#%d\n", count+1);
      printf("\nNome: %s\n", pessoas[i].nome);
      printf("\nCPF: %s\n", pessoas[i].cpf);
      printf("\nMatricula: %s\n", pessoas[i].matricula);
      printf("\nData de Nascimento: %s\n", pessoas[i].dataNasc);
      printf("\nSexo: %c\n", pessoas[i].sexo[0]);
  
      count++;
    }
}

//****************** Função de leitura de nome, recebe o vetor de struct e a posição que deve modificar o nome, se não encontrar erro faz a string ficar com caracteres em caixa alta
void lerNome(ficha_pessoa pessoa[], int qtd){
  int tam;
  
  printf("Digite o nome: ");
  fgets(pessoa[qtd].nome, 52, stdin);
  limparString(pessoa[qtd].nome);
  tam = tamString(pessoa[qtd].nome);
  if(tam>50){
    pessoa[qtd].erroNome = true;
    limparBuffer();
  } else if(tam<3)
    pessoa[qtd].erroNome = true;
  else
    transformMaiusculo(pessoa[qtd].nome);
}

//****************** Função de leitura de CPF, recebe o vetor de struct e a posição que deve modificar o CPF
void lerCPF(ficha_pessoa pessoa[], ficha_pessoa pessoa_repete[], int qtd, int qtd_repete){
  int tam;
  
  printf("Digite o CPF: ");
  fgets(pessoa[qtd].cpf, 13, stdin);
  limparString(pessoa[qtd].cpf);
  tam = tamString(pessoa[qtd].cpf);
  if(tam!=11){
    pessoa[qtd].erroCPF = true;
    if(tam>11)
    limparBuffer();
  }
  else if(qtd>0){
    pessoa[qtd].erroCPF = pessoaRepetida(pessoa, pessoa_repete, 0, qtd, qtd_repete);
  }
}