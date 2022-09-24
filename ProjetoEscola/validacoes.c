#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define vet_size 1000

//****************** Checa se há caracteres além de letras e espaços na string
int validarNome(char validNome[]){
  // checando se o primeiro caracter é um espaço
  if(validNome[0]==32)
    return true;
  else for(int i=0;validNome[i]!='\0';i++)
    if(validNome[i]!=32 && (validNome[i]>90 || validNome[i]<65))
      return true;

  return false;
}

//****************** Valida se o código está na estrutura correta de Letras e Numeros
int validarCodigo(char validCod[]){
  int i;
  
  for(i=0;validCod[i]!='\0';i++){
    if(i<3){
      if(validCod[i]<65 || validCod[i]>90)
        return true;
    } else if(i>=3)
      if(validCod[i]<48 || validCod[i]>57)
        return true;
  }

  return false;
}

//****************** Valida se há apenas numeros no semestre, com exceção do '.' na posição 4 da string
int validarSemestre(char validSemestre[]){
  for(int i=0;validSemestre[i]!='\0';i++)
  {
    if(i<4){
      if(validSemestre[i]<48 || validSemestre[i]>57)
        return true;
    } else if(i==4){
      if(validSemestre[i]!=46)
        return true;
    } else if(i==5){
      if((validSemestre[i]-48)<1 || (validSemestre[i]-48)>2)
        return true;
    }
  }

  return false;
}

//****************** Valida CPF de acordo com as regras do Ministério da Fazenda
int validarCPF(char validCPF[]) {
  int i, soma1 = 0, soma2 = 0;
  int aux = 0;

  //Checando se o CPF tem caracteres diferentes de numeros
  for (i=0; validCPF[i]!='\0'; i++)
    if ((validCPF[i] - 48) < 0 || (validCPF[i] - 48) > 9)
      return true;
  
  //Checando se o CPF tem todos os numeros iguais, aux servindo de check, se achar numero diferente sai do for
  for(i=1;i!='\0';i++)
    if (validCPF[i] != validCPF[0]){
      aux = 1;
      break;
    }
  if (aux == 0)
    return true;

  //Checando a validação do primeiro digito verificador, multiplicando os 9 primeiros numeros, decrescentemente por 10
  for(i=0, aux=10; i<9; i++, aux--)
    soma1 += (validCPF[i]-48) * aux;
  
  soma1 = (soma1 * 10) % 11;
  
  if(soma1 != (validCPF[9] - 48))
    return true;

  //Checando a validação do segundo digito verificador, multiplicando os 10 numeros, decrescentemente por 11
  for(i=0, aux=11; i<10; i++, aux--)
    soma2 += (validCPF[i]-48) * aux;
  
  soma2 = (soma2 * 10) % 11;
  
  if(soma2 != (validCPF[10] - 48))
    return true;

  // Checando se todos os valores são iguais
  //for(i=0;validCPF[i]!='\0' && validCPF[i+1]!='\0';i++){
    //if(validCPF[i]!=validCPF[i+1])
      //return false;
  //}
  
  return false;
}

//****************** Checa se o caracter é uma das entradas de sexo válidas
int validarSexo(char validSexo) {
  char valid[] = {'F', 'M', 'O'};
  int i;
  
  for (i=0;valid[i]!='\0';i++)
    if (validSexo == valid[i])
      return false;

  return true;
}

//****************** Checa se é uma data válida, inclui validação de ano bissexto
int validarNascimento(char validNasc[]) {
  int dia, mes, ano;
  int aux, ano_atual = 2022, ano_min = 1900;
  
  // Conversão de Dias, Mêses em inteiros
  dia = diaInt(validNasc);
  mes = mesInt(validNasc);
  ano = anoInt(validNasc);

  //Validação de Ano
  if(ano <= 0 || ano >= ano_atual || ano < ano_min)
    return true;

  //Validação de dias e meses
  if (dia > 31 || dia <= 0 || mes <= 0 || mes > 12 || ano <= 0)
    return true;
  else {
    if (mes != 2) {
      if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
        if (dia > 30)
          return true;
    } 
    else {
      if (ano % 4 == 0 && ano % 100 != 0) {
        if (dia > 29)
          return true;
      } 
      else if (dia > 28)
        return true;
    }
  }

  return false;
}