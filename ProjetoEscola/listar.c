#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define vet_size 1000

typedef struct{
  int matricula;;
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

//****************** Função que lista pessoas na ordem que foram cadastradas
void listar_pessoas(ficha_pessoa pessoas[], int qtd){
  for(int i=0, count=0;count<qtd;i++)
    if(pessoas[i].cadastrado==true){
      printf("******#%d\n", count+1);
      printf("\nNome: %s\n", pessoas[i].nome);
      printf("\nCPF: %s\n", pessoas[i].cpf);
      printf("\nMatricula: %d\n", pessoas[i].matricula);
      printf("\nData de Nascimento: %s\n", pessoas[i].dataNasc);
      printf("\nSexo: %c\n\n", pessoas[i].sexo[0]);
  
      count++;
    }
}

//****************** Lista as disciplinas na ordem que foram cadastradas
void listar_disciplinas(ficha_disciplina disciplinas[], int qtd){
  for(int i=0, count=0;count<qtd;i++)
    if(disciplinas[i].cadastrado==true){
      printf("\n\n******#%d\n", count+1);
      printf("\nNome da disciplina: %s\n", disciplinas[i].nome);
      printf("\nCodigo da disciplina: %s\n", disciplinas[i].codigo);
      printf("\nSemestre: %s\n", disciplinas[i].semestre);
      printf("\nNome do Professor: %s\n\n", disciplinas[i].nome_p);

      count++;
    }
}

//****************** Lista pessoas(alunos ou professores) de acordo com a entrada do usuário(F, M, O)
void listar_pessoas_sexo(ficha_pessoa pessoas[], int qtd){
  int count=0, count2=0;
  ficha_pessoa entrada[2];

  limparTela();
  printf("***Informe o sexo que será filtrado***\n\n");
  lerSexo(entrada, 0);
  limparTela();
  
  for(int i=0;count<qtd;i++)
    if(pessoas[i].cadastrado==true){
      if(pessoas[i].sexo[0]==entrada[0].sexo[0]){
        printf("******#%d\n", count2+1);
        printf("\nNome: %s\n", pessoas[i].nome);
        printf("\nCPF: %s\n", pessoas[i].cpf);
        printf("\nMatricula: %d\n", pessoas[i].matricula);
        printf("\nData de Nascimento: %s\n", pessoas[i].dataNasc);
        printf("\nSexo: %c\n\n", pessoas[i].sexo[0]);
        count2++;
      }
      count++;
    }
}

//****************** Lista uma disciplina com todos os seus dados, e seus alunos cadastrados
void listar1disc(ficha_disciplina disciplinas[], ficha_pessoa alunos[], int qtd_disciplina, int qtd_alunos){
  ficha_disciplina entrada[2];
  int count;

  limparTela();
  printf("***Digite o codigo da disciplina que quer listar\n\n");
  lerCodigoDisc(entrada, 0);

  for(int i=0;i<52;i++){
    if(strcmp(entrada[0].codigo, disciplinas[i].codigo)==0){
      printf("\n\nNome da disciplina: %s\n", disciplinas[i].nome);
      printf("\nCodigo da disciplina: %s\n", disciplinas[i].codigo);
      printf("\nSemestre: %s\n", disciplinas[i].semestre);
      printf("\nNome do Professor: %s\n", disciplinas[i].nome_p);
      printf("\nALUNOS MATRICULADOS NA DISCIPLINA:\n\n");
      for(int j=0, count=0;count<disciplinas[i].qtdMat;j++){
        if(disciplinas[i].alunosMatriculados[j]!=-1){
          printf("******#%d\n", count+1);
          printf("\nNome: %s\n", alunos[disciplinas[i].alunosMatriculados[j]].nome);
          printf("\nCPF: %s\n", alunos[disciplinas[i].alunosMatriculados[j]].cpf);
          printf("\nMatricula: %d\n", alunos[disciplinas[i].alunosMatriculados[j]].matricula);
          printf("\nData de Nascimento: %s\n", alunos[disciplinas[i].alunosMatriculados[j]].dataNasc);
          printf("\nSexo: %c\n\n", alunos[disciplinas[i].alunosMatriculados[j]].sexo[0]);
        }
        count++;
      }
      break;
    }
  }
  if(count==0)
    printf("***NAO HA ALUNOS CADASTRADOS NESSA DISCIPLINA***\n\n");
}

//****************** Lista alunos que estão matriculados em menos de 3 disciplinas
void listarcad3(ficha_pessoa alunos[], ficha_disciplina disciplinas[], int qtd_alunos, int qtd_disciplina){
  int count=0, count4=0, qtd;
  limparTela();
  
  for(int i=0;count<qtd_alunos;i++){
    if(alunos[i].cadastrado==true){
      qtd=0;
      for(int j=0, count2=0;count2<qtd_disciplina;j++){
        if(disciplinas[j].cadastrado==true){
          for(int k=0, count3=0;count3<disciplinas[j].qtdMat;k++){
            if(disciplinas[j].alunosMatriculados[k]!=-1){
              if(disciplinas[j].alunosMatriculados[k]==i){
                qtd++;
                break;
              }
              count3++;
            }
          }
          count2++;
        }
      }
      if(qtd<3){
        printf("******#%d\n", count4+1);
        printf("\nCadastrado em %d disciplinas\n", qtd);
        printf("\nNome: %s\n", alunos[i].nome);
        printf("\nCPF: %s\n", alunos[i].cpf);
        printf("\nMatricula: %d\n", alunos[i].matricula);
        printf("\nData de Nascimento: %s\n", alunos[i].dataNasc);
        printf("\nSexo: %c\n\n", alunos[i].sexo[0]);
        count4++;
      }
      count++;
    }
  }
  if(count4==0)
    printf("***NAO FORAM ENCONTRADOS ALUNOS MATRICULADOS EM MENOS DE 3 DISCIPLINAS***\n");
}

//****************** Lista as disciplinas na ordem que foram cadastradas
void listarDisc40(ficha_disciplina disciplinas[], int qtd){
  int count2;

  limparTela();
  for(int i=0, count=0, count2=0;count<qtd;i++)
    if(disciplinas[i].cadastrado==true){
      if(disciplinas[i].qtdMat>40){
        printf("\n\n******#%d\n", count2+1);
        printf("\nNome da disciplina: %s\n", disciplinas[i].nome);
        printf("\nCodigo da disciplina: %s\n", disciplinas[i].codigo);
        printf("\nSemestre: %s\n", disciplinas[i].semestre);
        printf("\nNome do Professor: %s\n\n", disciplinas[i].nome_p);
        count2++;
      }
      count++;
    }
  if(count2==0)
    printf("***NAO FORAM ENCONTRADAS DISCIPLINAS COM MAIS DE 40 ALUNOS***\n");
}

//****************** Lista as pessoas(aluno ou professor), em ordem alfabética
void listarNome(ficha_pessoa pessoas[], int qtd){
  int i, j, menor, aux;
  int ordenado[qtd];
  char str_aux[52];
  ficha_pessoa nomes[qtd];

  limparTela();
  for(i=0, aux=0;aux<qtd;i++)
    if(pessoas[i].cadastrado==true){
      ordenado[aux]=i;
      strcpy(nomes[aux].nome, pessoas[i].nome);
      aux++;
    }

  // Ordenando os nomes por selection sort
  for(i=0;i<qtd-1;i++){
    menor=i;
    for(j=i+1;j<qtd;j++){
      printf("ciclo %d:\n\n", i);
      aux=0;
      do{
        if(nomes[j].nome[aux]!=32 && nomes[menor].nome[aux]!=32){
          printf("***%s***%c*** ****%s***%c***\n", nomes[j].nome, nomes[j].nome[aux], nomes[menor].nome,nomes[menor].nome[aux]);
          if(nomes[j].nome[aux]<nomes[menor].nome[aux]){
            menor=j;
            break;
          }
          else if(nomes[menor].nome[aux]<nomes[j].nome[aux]){
            break;
          }
        }
        aux++;
      }while(nomes[j].nome[aux]!='\0');
    }

    if(menor!=i){
      aux=ordenado[i];
      ordenado[i] = ordenado[menor];
      ordenado[menor] = aux;

      strcpy(str_aux, nomes[i].nome);
      strcpy(nomes[i].nome, nomes[menor].nome);
      strcpy(nomes[menor].nome, str_aux);
    }
  }

  // Printando o vetor ordenado
  for(i=0;i<qtd;i++){
    printf("******#%d\n", i+1);
    printf("\nNome: %s\n", pessoas[ordenado[i]].nome);
    printf("\nCPF: %s\n", pessoas[ordenado[i]].cpf);
    printf("\nMatricula: %d\n", pessoas[ordenado[i]].matricula);
    printf("\nData de Nascimento: %s\n", pessoas[ordenado[i]].dataNasc);
    printf("\nSexo: %c\n\n", pessoas[ordenado[i]].sexo[0]);
  }
}

void listarData(ficha_pessoa pessoas[], int qtd){
  limparTela();
  int dia[qtd], mes[qtd], ano[qtd], aux[qtd];
  int count, menor, i, check;

  // Transformando todos os dias meses e anos em inteiros para ordenar posteriormente
  for(i=0;count<qtd;i++)
    if(pessoas[i].cadastrado==true){
      dia[count] = diaInt(pessoas[i].dataNasc);
      mes[count] = mesInt(pessoas[i].dataNasc);
      ano[count] = anoInt(pessoas[i].dataNasc);
      aux[count] = i;
      count++;
    }

  // Ordenando o vetor auxiliar via selection sort
  for(i=0;i<qtd-1;i++){
    menor = i;
    for(int j=i+1;j<qtd;j++)
      if(ano[j]<ano[menor])
        menor=j;
      else if(ano[j]==ano[menor])
        if(mes[j]<mes[menor])
          menor=j;
        else if(mes[j]==mes[menor])
          if(dia[j]<dia[menor])
            menor=j;
    
    if(menor!=i){
      count = aux[i]; //count funcionando como variável auxiliar
      aux[i] = aux[menor];
      aux[menor] = count;
      
      count = ano[i];
      ano[i] = ano[menor];
      ano[menor] = count;
      
      count = mes[i];
      mes[i] = mes[menor];
      mes[menor] = count;
      
      count = dia[i];
      dia[i] = dia[menor];
      dia[menor] = count;
    }
  }

  // Printando o vetor ordenado
  for(i=0;i<qtd;i++){
    printf("******#%d\n", i+1);
    printf("\nNome: %s\n", pessoas[aux[i]].nome);
    printf("\nCPF: %s\n", pessoas[aux[i]].cpf);
    printf("\nMatricula: %d\n", pessoas[aux[i]].matricula);
    printf("\nData de Nascimento: %s\n", pessoas[aux[i]].dataNasc);
    printf("\nSexo: %c\n\n", pessoas[aux[i]].sexo[0]);
  }
}

//****************** Recebe uma string de no mínimo 3 caracteres, e printa todas as pessoas que tenham essas letras em seu nome
void busca(ficha_pessoa alunos[], ficha_pessoa professores[], int qtd_alunos, int qtd_prof){
  ficha_pessoa entrada[2];
  int i, j, k, count, count2, countPrint;

  limparTela();
  imprimir_linhas();
  printf("Digite no minimo 3 letras para buscar alguém cadastrado\n\n");
  lerNome(entrada, 0);
  
  printf("\n******ALUNOS:\n");
  for(i=0, count=0, count2=0;count<qtd_alunos;i++){
    if(alunos[i].cadastrado==true){
      for(j=0, countPrint=0;entrada[0].nome[j]!='\0';j++){
        for(k=0;alunos[i].nome[k]!='\0';k++){
          if(alunos[i].nome[k]==entrada[0].nome[j]){
            countPrint++;
            break;
          }
          if(countPrint==3)
            break;
        }
      }

      if(countPrint==3){
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
    printf("\n***NAO FORAM ENCONTRADOS ALUNOS***\n");
  
  printf("\n******Professores:\n");
  for(i=0, count=0, count2=0;count<qtd_prof;i++){
    if(professores[i].cadastrado==true){
      for(j=0, countPrint=0;entrada[0].nome[j]!='\0';j++){
        for(k=0;professores[i].nome[k]!='\0';k++){
          if(professores[i].nome[k]==entrada[0].nome[j]){
            countPrint++;
            break;
          }
          if(countPrint==3)
            break;
        }
      }

      if(countPrint==3){
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
    printf("\n***NAO FORAM ENCONTRADOS PROFESSORES***\n");
}