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
int insert_Pessoa(ficha_pessoa pessoa[], int qtd){
  
  limparTela();

  //Todas as entradas são validadas em suas respectivas funções
  lerNome(pessoa, qtd);
  lerCPF(pessoa, qtd);
  pessoa[qtd].matricula = AddMatricula();
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
  //******************************************************************************************************************************************************************************************SERÁ NECESSÁRIO DIVIDIR ESSA FUNÇÃO ENTRE DUAS DIFERENTES:PROFESSORES E ALUNOS, POIS NA EXCLUSÃO HÁ DETALHES DISTINTOS, PRINCIPALMENTE NA RELAÇÃO ENTRE OS DADOS E AS DISCIPLINAS //******************************************************************************************************************************************************************************************AO EXCLUIR UM ALUNO, TERÁ QUE SAIR TAMBÉM OS DADOS DELE DAS DISCIPLINAS: SEU INDICE NOS MATRICULADOS. E NOS PROFESSORES: SAIR SEU NOME DAS DISCIPLINAS EM QUE ESTÁ MATRICULADO
  int op, i;

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
    i = trueIndexPessoa(op, pessoa);
    pessoa[i].cadastrado=false;
    qtd--;

    printf("\n***PESSOA #%d EXCLUIDA***\n", op);
  }

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

//****************** SE DER TEMPO IMPLEMENTAR ESSE FUNÇÃO CORRIGIDA- Checa se há alguma string na struct aluno ou professor, dado um código de qual informação avaliar e o indice na struct a ser checada, retorna 2 caso encontre erro
/*int pessoaRepetida(ficha_pessoa pessoa[], ficha_pessoa pessoa_repete[], int cod, int qtd, int qtd_repete, int index){
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
}*/