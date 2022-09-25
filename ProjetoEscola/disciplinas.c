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

//****************** Menu das disciplinas, redireciona para todas as funções de cadastro e relatório de disciplinas
int menu_Disciplinas(ficha_disciplina disciplinas[], ficha_pessoa alunos[], ficha_pessoa professores[], int qtd_disciplina, int qtd_alunos, int qtd_prof){
  int menu_disciplina;

  do{
    limparTela();
    imprimir_linhas();
    printf("\nMENU DISCIPLINAS\n\n");
    printf("1. Cadastro de Disciplinas\n2. Listar Disciplinas\n3. Inserir Aluno em Uma Disciplina\n4. Excluir Aluno em uma Disciplina\n5. Listar uma Disciplina\n6. Disciplinas com mais de 40 matriculas \n");
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
      
      case 3: if(qtd_alunos>0 && qtd_disciplina>0)
        insert_AlunoDisc(disciplinas, alunos, qtd_disciplina, qtd_alunos);
        else{
          if(qtd_alunos==0)
            printf("***NAO HA ALUNOS CADASTRADOS***\n\n");
          if(qtd_disciplina==0)
            printf("***NAO HA DISCIPLINAS CADASTRADAS***\n\n");
        } break;
      
      case 4: if(qtd_alunos>0 && qtd_disciplina>0)
        exclude_AlunoDisc(disciplinas, alunos, qtd_disciplina, qtd_alunos);
        else{
          if(qtd_alunos==0)
            printf("***NAO HA ALUNOS CADASTRADOS***\n\n");
          if(qtd_disciplina==0)
            printf("***NAO HA DISCIPLINAS CADASTRADAS***\n\n");
        } break;
      
      case 5: if(qtd_disciplina>0)
        listar1disc(disciplinas, alunos, qtd_disciplina, qtd_alunos);
        else
          printf("***NAO HA DISCIPLINAS CADASTRADAS***\n\n"); break;
      
      case 6: if(qtd_disciplina>0)
        listarDisc40(disciplinas, qtd_disciplina);
        else
          printf("***NAO HA DISCIPLINAS CADASTRADAS***\n\n"); break;
      
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
      
      case 3: if(qtd_disciplina>0)
        update_Disciplina(disciplinas, professores, qtd_disciplina, qtd_prof);
        else
          printf("***NAO HA DISCIPLINAS CADASTRADAS***\n\n"); break;
      
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
  disciplinas[qtd_disciplina].qtdMat = 0;
  qtd_disciplina++;
  printf("\nCadastro Realizado com Sucesso\n");
  
  return qtd_disciplina;
}

//****************** Função que adiciona um professor a disciplina, aparece a lista de professores e o usuário deve escolher um professor válido
void ProfessorDisc(ficha_disciplina disciplinas[], ficha_pessoa professores[], int index, int qtd_prof){
  int op, i;

  // Printa os professores cadastrados
  printf("\n\n");
  listar_pessoas(professores, qtd_prof);

  // Escolhendo um professor válido
  do{
    printf("Digite o #numero do professor para a disciplina %s:\n", disciplinas[index].codigo);
    scanf("%d", &op);
    getchar();
    
    if(op<1 || op>qtd_prof)
      printf("\n***ENTRADA INVALIDA***\n");
  }while(op<1 || op>qtd_prof);
  
  // Achando o índice correto para passar o nome
  i = trueIndexPessoa(op, professores);
  
  // Passando o nome do professor para a struct de disciplinas
  strcpy(disciplinas[index].nome_p, professores[i].nome);
}

//****************** Função que faz exclusão lógica de uma disciplina, através da modificação de uma variavel que funciona como uma flag se a disciplina está cadastrada ou não. E diminui o contador de disciplinas cadastradas
int exclude_Disciplina(ficha_disciplina disciplinas[], int qtd){
  int op, i;

  // Escolhendo uma disciplina válida
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

  // Retornando em caso de digitar 0
  if(op==0){
    printf("\n***VOLTANDO***\n");
  }
  else{
    // Encontrando o índice no vetor de struct de disciplinas, tendo como referência o que o usuário digitou no menu, e mudando a flag da disciplina para não cadastrada
    i = trueIndexDisciplina(op, disciplinas);
    disciplinas[i].cadastrado=false;
    qtd--;

    printf("\n***DISCIPLINA #%d EXCLUIDA***\n", op);
  }

  return qtd;
}

//****************** Função que modifica o cadastro de uma disciplina
void update_Disciplina(ficha_disciplina disciplinas[], ficha_pessoa professores[], int qtd_disciplina, int qtd_prof){
  int op, op2, i, count;

  // Escolhendo uma disciplina cadastrada
  do{
    limparTela();
    listar_disciplinas(disciplinas, qtd_disciplina);
    printf("Digite o #numero da disciplina para atualizar os dados:\n");
    printf("(Digite 0 para retornar ao menu anterior)\n\n");
    scanf("%d", &op);
    getchar();
    
    if(op<0 || op>qtd_disciplina)
      printf("\n***ENTRADA INVALIDA***\n");
  }while(op<0 || op>qtd_disciplina);

  // Continua o código caso escolha uma disciplina que tenha aparecido no menu
  if(op!=0){
    // Escolhe um dos dados da disciplina, para então alterar
    do{
      limparTela();
      imprimir_linhas();
      printf("\nDigite o que deseja alterar:\n");
      printf("1. Nome da Disciplina\n2. Codigo\n3. Semestre \n4. Nome do Professor\n");
      printf("(Digite 0 para retornar ao menu de cadastro)\n\n");
      
      scanf("%d", &op2);
      getchar();

      if(op2!=0){
        // Encontrando o índice correto para alterar os dados
        i = trueIndexDisciplina(op, disciplinas);
        // Realizando as alterações diferentes para cada entrada no menu
        switch(op2){
          case 1: lerNomeDisc(disciplinas, i); break;
          case 2: lerCodigoDisc(disciplinas, i); break;
          case 3: lerSemestreDisc(disciplinas, i); break;
          case 4: if(qtd_prof>0)
            ProfessorDisc(disciplinas, professores, qtd_disciplina, qtd_prof);
            else
              printf("***NAO HA PROFESSORES CADASTRADOS***\n\n"); break;
          default: printf("***ENTRADA INVALIDA***\n\n");
        }
      }
    }while(op2>5 || op2<=0);

    printf("\n***Cadastro Alterado***\n");
  }
}

//****************** Função que insere um aluno numa disciplina
void insert_AlunoDisc(ficha_disciplina disciplinas[], ficha_pessoa alunos[], int qtd_disciplina, int qtd_alunos){
  int index_disc, index_aluno, op, op2, i, count;
  int maxop2=0;// Valor máximo que o op2 pode ter, será calculado diferente por não printar todos os alunos cadastrados no sistema na tela, vai printar apenas os que ainda não foram cadastrados na matricula escolhida

  // Escolhe uma disciplina cadastrada
  do{
    limparTela();
    listar_disciplinas(disciplinas, qtd_disciplina);
    printf("\nEscolha a disciplina\n");
    printf("(Digite 0 para retornar ao menu anterior)\n");
    scanf("%d", &op);
    getchar();

    if(op<0 || op>qtd_disciplina)
      printf("\n***ENTRADA INVALIDA***\n");
  }while(op<0 || op>qtd_disciplina);

  // Continua o código caso escolha uma disciplina que tenha aparecido no menu
  if(op==0)
    printf("\n***VOLTANDO***\n");
  else{
    // Encontrando o índice correto de disciplina para alterar os dados
    index_disc = trueIndexDisciplina(op, disciplinas);
    // Printando na tela apenas os alunos que não foram cadastrados na disciplina selecionada
    do{
      limparTela();
      for(i=0, count=0, maxop2=0;count<qtd_alunos;i++)
        if(alunos[i].cadastrado==true){
          if(checkMatriculado(disciplinas, alunos, index_disc, i)==false){
            printf("******#%d\n", maxop2+1);
            printf("\nNome: %s\n", alunos[i].nome);
            printf("\nCPF: %s\n", alunos[i].cpf);
            printf("\nMatricula: %d\n", alunos[i].matricula);
            printf("\nData de Nascimento: %s\n", alunos[i].dataNasc);
            printf("\nSexo: %c\n\n", alunos[i].sexo[0]);
            maxop2++;
          }
          count++;
        }
      
      if(maxop2==0){
        printf("***NAO HA ALUNOS DISPONIVEIS PARA INSERIR NESTA DISCIPLINA***\n");
        op2=0;
      }
      else{
        // Escolhendo o aluno que será inserido na disciplina
        printf("\nEscolha o aluno a ser inserido na disciplina\n");
        printf("(Digite 0 para retornar ao menu de disciplinas)\n");
        scanf("%d", &op2);
        getchar();
        
        if(op2<0 || op2>maxop2)
        printf("\n***ENTRADA INVALIDA***\n");
      }
    }while(op2<0 || op2>maxop2);

    
    if(op2==0)
      printf("\n***VOLTANDO***\n");
    else{
      // Encontrando o índice correto de aluno para alterar os dados
      count=0;
      i=0;
      while(count!=op2){
        if(alunos[i].cadastrado==true && checkMatriculado(disciplinas, alunos, index_disc, i)==false)
          count++;
        i++;
      }
      i--;
      index_aluno = i;
      // Inserindo o indice do aluno escolhido no vetor de alunos matriculados na disciplina escolhida
      for(i=0;count<disciplinas[index_disc].qtdMat;i++){
        if(disciplinas[index_disc].alunosMatriculados[i]==-1)
          break;
        else if(disciplinas[index_disc].alunosMatriculados[i]!=-1)
          count++;
      }
        
      disciplinas[index_disc].alunosMatriculados[i] = index_aluno;
      disciplinas[index_disc].qtdMat++;

      printf("\nALUNO INSERIDO NA DISCIPLINA\n");
    }
  }
}

//****************** Função que exclui um aluno de uma disciplina
void exclude_AlunoDisc(ficha_disciplina disciplinas[], ficha_pessoa alunos[], int qtd_disciplina, int qtd_alunos){
  int index_disc, index_aluno, op, op2, i, count;

  do{
    limparTela();
    listar_disciplinas(disciplinas, qtd_disciplina);
    printf("\nEscolha a disciplina\n");
    printf("(Digite 0 para retornar ao menu anterior)\n");
    scanf("%d", &op);
    getchar();

    if(op<0 || op>qtd_disciplina)
      printf("\n***ENTRADA INVALIDA***\n");
  }while(op<0 || op>qtd_disciplina);

  if(op==0)
    printf("\n***VOLTANDO***\n");
  else{
    // Encontrando o índice correto de disciplina para alterar os dados
    index_disc = trueIndexDisciplina(op, disciplinas);
    do{
      limparTela();
      for(i=0, count=0;count<disciplinas[index_disc].qtdMat;i++){
        if(disciplinas[index_disc].alunosMatriculados[i]!=-1){
          printf("******#%d\n", count+1);
          printf("\nNome: %s\n", alunos[i].nome);
          printf("\nCPF: %s\n", alunos[i].cpf);
          printf("\nMatricula: %d\n", alunos[i].matricula);
          printf("\nData de Nascimento: %s\n", alunos[i].dataNasc);
          printf("\nSexo: %c\n\n", alunos[i].sexo[0]);
          count++;
        }
      }
      if(count==0){
        printf("***NAO HA ALUNOS NESSA DISCIPLINA***\n");
        break;
      }
      else{
        printf("\nEscolha o aluno a ser excluido da disciplina\n");
        printf("(Digite 0 para retornar ao menu de disciplinas)\n");
        scanf("%d", &op2);
        getchar();
  
        if(op2<0 || op2>qtd_alunos)
          printf("\n***ENTRADA INVALIDA***\n");
      }
    }while(op2<0 || op2>qtd_alunos);

    
    if(op2==0)
      printf("\n***VOLTANDO***\n");
    else{
      // Encontrando o índice correto de aluno para alterar os dados
      index_aluno = trueIndexPessoa(op2, alunos);

      for(i=0, count=0;count<disciplinas[index_disc].qtdMat;i++)
        if(disciplinas[index_disc].alunosMatriculados[i]==index_aluno)
          break;
      disciplinas[index_disc].alunosMatriculados[i]=-1;
      disciplinas[index_disc].qtdMat--;

      printf("\n***ALUNO INSERIDO NA DISCIPLINA***\n");
    }
  }
}
//****************** Checa se há algum código de disciplina repetido em outra disciplina já cadastrada, retorna 2 caso encontre alguma igual
int codigoRepetido(ficha_disciplina disciplinas[], int index){
  int repetido = false;
  
  for(int i=0, count=0;count<index;i++)
    if(disciplinas[i].cadastrado==true){
      if(strcmp(disciplinas[index].codigo, disciplinas[i].codigo)==0){
        repetido=2;
        break;
      }
      count++;
    }

  return repetido;
}