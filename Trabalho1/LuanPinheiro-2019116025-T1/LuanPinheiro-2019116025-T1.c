// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Luan Pinheiro da Silva
//  email: luanp.soledade@gmail.com
//  Matrícula: 2019116025
//  Semestre: 2022.2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "LuanPinheiro-2019116025-T1.h"
#include "extra.h" // Todas as funções extras que serão criadas

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  // Conversão de Dias, Mêses em inteiros
  int dia = diaInt(data);
  int mes = mesInt(data);
  int ano = anoInt(data);
  return validarData(dia, mes, ano);
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{
  //calcule os dados e armazene nas três variáveis a seguir
  DiasMesesAnos dma;

  if (q1(datainicial) == 0){
    dma.retorno = 2;
    return dma;
  }
  else if (q1(datafinal) == 0){
    dma.retorno = 3;
    return dma;
  }
  else{
    //verifique se a data final não é menor que a data inicial
    int diaInicial = diaInt(datainicial);
    int mesInicial = mesInt(datainicial);
    int anoInicial = anoInt(datainicial);
    int diaFinal = diaInt(datafinal);
    int mesFinal = mesInt(datafinal);
    int anoFinal = anoInt(datafinal);

    if(anoInicial > anoFinal){
      dma.retorno = 4;
      return dma;
    }
    else if(anoInicial == anoFinal){
      if(mesInicial > mesFinal){
        dma.retorno = 4;
        return dma;
      }
      else if(mesInicial == mesFinal){
        if(diaInicial > diaFinal){
          dma.retorno = 4;
          return dma;
        }
      }
    }
    
    //calcule a distancia entre as datas
    dma.qtdDias = 0;
    dma.qtdMeses = 0;
    dma.qtdAnos = 0;

    // O diaInicial, mesInicial e anoInicial irá avançar até serem iguais, nesse caminho será calculado em paralelo a quantidade de dias meses e anos percorridos, com seus meses de diferentes dias
    for(int diaDma = diaInicial, mesDma = mesInicial, anoDma = anoInicial, mesMudou = false, mesMudouDma = false; diaInicial != diaFinal || mesInicial != mesFinal || anoInicial != anoFinal;){
      diaInicial++;
      if(mesInicial == 2){
        if(anoInicial % 4 == 0 && (anoInicial % 100 != 0 || anoInicial % 400 == 0)){
          if(diaInicial > 29){
            mesMudou = true;
          }
        }
        else{
          if(diaInicial > 28){
            mesMudou = true;
          }
        }
      }
      else{
        if(mesInicial == 4 || mesInicial == 6 || mesInicial == 9 || mesInicial == 11){
          if(diaInicial > 30)
          {
            mesMudou = true;
          }
        }
        else{
          if(diaInicial > 31){
            mesMudou = true;
          }
        }
      }
      if(mesMudou == true){
        diaInicial = 0;
        mesInicial++;
        if(mesInicial > 12){
          mesInicial = 1;
          anoInicial++;
        }
        mesMudou = false;
      }

      // Quantidade de dias meses e anos em paralelo, sua principal diferença é iniciar com a contagem de dias em 1, diferente do código acima, que inicia não necessariamente no dia 1 do mês
      dma.qtdDias++;
      if(mesDma == 2){
        if(anoDma % 4 == 0 && (anoDma % 100 != 0 || anoDma % 400 == 0)){
          if(dma.qtdDias > 29){
            mesMudouDma = true;
          }
        }
        else{
          if(dma.qtdDias > 28){
            mesMudouDma = true;
          }
        }
      }
      else{
        if(mesDma == 4 || mesDma == 6 || mesDma == 9 || mesDma == 11){
          if(dma.qtdDias > 30)
          {
            mesMudouDma = true;
          }
        }
        else{
          if(dma.qtdDias > 31){
            mesMudouDma = true;
          }
        }
      }
      if(mesMudouDma == true){
        dma.qtdDias = 0;
        dma.qtdMeses++;
        if(dma.qtdMeses == 12){
          dma.qtdMeses = 0;
          dma.qtdAnos++;
        }
        mesDma++;
        if(mesDma > 12){
          mesDma = 1;
          anoDma++;
        }
        mesMudouDma = false;
      }
    }
    //se tudo der certo
    dma.retorno = 1;
    return dma;
  }
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;

    if(isCaseSensitive == 1){ // Se é Case Sensitive, só vai haver ocorrência se for exatamente o mesmo caractere
      for(int i = 0; texto[i] != '\0'; i++){
        if(texto[i] == c){
          qtdOcorrencias++;
        }
      }
    }
    else{
      char upperCaseString[250]; // Criando uma cópia(para não alterar a string original), para deixar tudo em caixa alta
      strcpy(upperCaseString, texto); 
      transformMaiusculo(upperCaseString);
      if(c >= 97 && c <= 122){ // Caractere em caixa alta, igual a string que será comparada
        c -= 32;
      }

      for(int i = 0; upperCaseString[i] != '\0'; i++){
        if(upperCaseString[i] == c){
          qtdOcorrencias++;
        }
      }
    }
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0;
    int tamanhoBusca = strlen(strBusca), tamanhoTexto = strlen(strTexto);
    int indexTexto, indexBusca, indexTextoAux, countPosicoes;
	int strTextoInt[tamanhoTexto], strBuscaInt[tamanhoBusca]; // Terá os valores de strTexto e strBusca em int, é o que será usada na comparação

	tamanhoTexto = transformaCaractereEspecial(strTexto, tamanhoTexto, strTextoInt); // transforma as strings em inteiro
	tamanhoBusca = transformaCaractereEspecial(strBusca, tamanhoBusca, strBuscaInt);

    // For irá percorrer a strTexto
    for(indexTexto = 0, countPosicoes = 0; indexTexto < tamanhoTexto; indexTexto++){
        if(strTextoInt[indexTexto] == strBuscaInt[0]){ // Caso a posição atual seja igual ao começo da string de busca, é uma potencial ocorrencia
            for(indexTextoAux = indexTexto, indexBusca = 0; indexBusca < tamanhoBusca; indexBusca++, indexTextoAux++){ // Com uso de uma variavel auxiliar(que ficará com o indice da strTexto), irá continuar a percorrer a strTexto
                if(strTextoInt[indexTextoAux] != strBuscaInt[indexBusca]){
                    break; // Caso esse recorte da strTexto não seja igual a strBusca o código para aqui
                }
            }
            if(indexBusca == tamanhoBusca){ // Caso não ocorra o break acima essa condição é verdadeira e uma nova ocorrencia é registrada
                posicoes[countPosicoes] = indexTexto + 1; // Posição em que começou a ocorrencia(+1 por que a contagem inicia em 1)
                posicoes[countPosicoes+1] = indexTextoAux;
                countPosicoes += 2;
                indexTexto = indexTextoAux - 1; // Como a strBusca foi encontrada não é necessário percorrer as letras anteriores  na ocorrencia em strTexto, e como o indexTextoAux é de valor 1 acima do indice real é necessário subtrair 1
                qtdOcorrencias++;
            }
        }
    }
    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
	int num_invertido = 0, resto;

  // Começando da direita para esquerda, isola cada numero em 1 unidade, e vai inserindo esse número em uma nova variavel
	while(num>0){
		resto = num % 10; 
		num_invertido = (num_invertido * 10) + resto;
		num /= 10;
	}
  return num_invertido;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
	int i, numero_isolado, num_aux, num_aux2, qtdOcorrencias = 0;

	while(numerobase > 0){
		numero_isolado = numerobase % 10; // Numero, dentro do numerobase, que será comparado com o numerobusca
		num_aux = numerobusca / 10; // Auxiliar que ajuda a definir, junto com o for abaixo, quantas casas decimais tem o numerobusca
		num_aux2 = numerobase / 10; // Auxiliar que será usada no for abaixo, para definir um numero isolado, com a mesma quantidade de casas decimais que o numerobusca

		for(i = 10; num_aux > 0; i *= 10, num_aux /= 10){ // For que irá funcionar apenas se houver mais de uma casa decimal, colocando mais casas com numeros posteriores dentro do numero_isolado
			numero_isolado += (num_aux2 % 10)*i;
		}
		
		if(numero_isolado == numerobusca){ // Checando se o numero que foi isolado é igual ao que esta sendo buscado
			qtdOcorrencias++;
		}
		
		numerobase /= 10;
	}
	return qtdOcorrencias;
}