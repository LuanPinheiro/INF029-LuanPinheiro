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
  int qtdMat;
  int cadastrado;
}ficha_disciplina;

//****************** Função de leitura de nome, recebe o vetor de struct e a posição que deve ler do usuário o nome, se não encontrar erro faz a string ficar com caracteres em caixa alta
void lerNome(ficha_pessoa pessoa[], int index){
  int tam, erro;
  
  do{
    erro = false;
    
    printf("Digite o nome: ");
    fgets(pessoa[index].nome, 52, stdin);
    limparString(pessoa[index].nome);
    tam = tamString(pessoa[index].nome);
    if(tam>50){
      erro = true;
      limparBuffer();
    } else if(tam<3)
      erro = true;
  
    if(erro==false){
      transformMaiusculo(pessoa[index].nome);
      erro = validarNome(pessoa[index].nome);
    }

    if(erro==true)
      printf("***ENTRADA INVALIDA***\n");
  }while(erro!=false);
}

//****************** Função de leitura de CPF, recebe o vetor de struct e a posição que deve ler do usuário o CPF
void lerCPF(ficha_pessoa pessoa[], int index){
  int tam, erro;
  
  do{
    erro = false;

    printf("Digite o CPF: ");
    fgets(pessoa[index].cpf, 13, stdin);
    limparString(pessoa[index].cpf);
    tam = tamString(pessoa[index].cpf);
    if(tam!=11){
      erro = true;
      if(tam>11)
      limparBuffer();
    }
    /*else if(qtd>0 || qtd_repete>0){
      pessoa[index].erroCPF = pessoaRepetida(pessoa, pessoa_repete, 0, qtd, qtd_repete, index);
    }*/
    
    if(erro == false)
      erro = validarCPF(pessoa[index].cpf);

    if(erro==true)
      printf("***ENTRADA INVALIDA***\n");
  }while(erro!=false);
}

//****************** Função de leitura de Matricula, recebe o vetor de struct e a posição que deve ler do usuário a Matricula, além dos paramêtros para comparação da struct diferente, e checa se há Matricula repetida entre professores e alunos (ex: se ler dado de aluno, recebe também de professor para buscar se está repetido)
void lerMatricula(ficha_pessoa pessoa[], int index){
  int tam, erro;
  
  do{
    erro = false;

    printf("Digite a Matricula: ");
    fgets(pessoa[index].matricula, 12, stdin);
    limparString(pessoa[index].matricula);
    tam = tamString(pessoa[index].matricula);
    if(tam!=10){
      erro = true;
      if(tam>10)
        limparBuffer();
    }
    /*else if(qtd>0 || qtd_repete>0)
      pessoa[index].erroMat = pessoaRepetida(pessoa, pessoa_repete, 1, qtd, qtd_repete, index);*/
  
    if(erro == false)
      erro = validarMatricula(pessoa[index].matricula);

    if(erro==true)
      printf("***ENTRADA INVALIDA***\n");
  }while(erro==true);
}

//****************** Função de leitura de Data de Nascimento, recebe o vetor de struct e a posição que deve ler do usuário a Data
void lerDataNasc(ficha_pessoa pessoa[], int index){
  int tam, erro;
  
  do{
    erro = false;

    printf("Digite a Data de Nascimento: ");
    fgets(pessoa[index].dataNasc, 12, stdin);
    limparString(pessoa[index].dataNasc);
    tam = tamString(pessoa[index].dataNasc);
    if(tam>10 || tam<5){
      erro = true;
      if(tam>10)
        limparBuffer();
    }
    else
      erro = validarNascimento(pessoa[index].dataNasc);

    if(erro==true)
      printf("***ENTRADA INVALIDA***\n");
  }while(erro==true);
}

//****************** Função de leitura de sexo, recebe o vetor de struct e a posição que deve ler do usuário o sexo
void lerSexo(ficha_pessoa pessoa[], int index){
  int tam, erro;
  
  do{
    erro = false;

    printf("Digite o sexo: ");
    fgets(pessoa[index].sexo, 3, stdin);
    limparString(pessoa[index].sexo);
    tam = tamString(pessoa[index].sexo);
    if(tam!=1){
      erro = true;
      if(tam>1)
        limparBuffer();
    }
    else{
      transformMaiusculo(pessoa[index].sexo);
      erro = validarSexo(pessoa[index].sexo[0]);
    }

    if(erro==true)
      printf("***ENTRADA INVALIDA***\n");
  }while(erro==true);
}

//****************** Função de leitura de nome, recebe o vetor de struct e a posição que deve ler do usuário o nome, se não encontrar erro faz a string ficar com caracteres em caixa alta
void lerNomeDisc(ficha_disciplina disciplinas[], int index){
  int tam, erro;
  
  do{
    erro = false;
    
    printf("Digite o nome: ");
    fgets(disciplinas[index].nome, 52, stdin);
    limparString(disciplinas[index].nome);
    tam = tamString(disciplinas[index].nome);
    if(tam>50){
      erro = true;
      limparBuffer();
    } else if(tam<3)
      erro = true;
  
    if(erro==false){
      transformMaiusculo(disciplinas[index].nome);
      erro = validarNome(disciplinas[index].nome);
    }

    if(erro==true)
      printf("***ENTRADA INVALIDA***\n");
  }while(erro!=false);
}

//****************** Função de leitura de codigo, recebe o vetor de struct e a posição que deve ler do usuário o codigo, se não encontrar erro transforma as letras minusculas em maiusculas
void lerCodigoDisc(ficha_disciplina disciplinas[], int index){
  int tam, erro;
  
  do{
    erro = false;
    
    printf("Digite o codigo da disciplina: ");
    fgets(disciplinas[index].codigo, 8, stdin);
    limparString(disciplinas[index].codigo);
    tam = tamString(disciplinas[index].codigo);
    if(tam>6)
      limparBuffer();
    if(tam!=6)
      erro = true;

    if(erro == false){
      transformMaiusculo(disciplinas[index].codigo);
      erro = validarCodigo(disciplinas[index].codigo);
    }
    

    if(erro==true)
      printf("***ENTRADA INVALIDA***\n");
  }while(erro!=false);
}

//****************** Função de leitura de semestre, recebe o vetor de struct e a posição que deve ler do usuário o semestre
void lerSemestreDisc(ficha_disciplina disciplinas[], int index){
  int tam, erro;
  
  do{
    erro = false;
    
    printf("Digite o semestre da disciplina: ");
  fgets(disciplinas[index].semestre, 8, stdin);
  limparString(disciplinas[index].semestre);
  tam = tamString(disciplinas[index].semestre);
  if(tam>6)
    limparBuffer();
  if(tam!=6)
    erro = true;

    if(erro == false)
      erro = validarSemestre(disciplinas[index].semestre);
    

    if(erro==true)
      printf("***ENTRADA INVALIDA***\n");
  }while(erro!=false);
}