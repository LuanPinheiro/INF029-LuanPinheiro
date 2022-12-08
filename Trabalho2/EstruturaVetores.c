#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "EstruturaVetores.h"

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho){
    // a posicao é válida dentro do vetor principal?
    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        return POSICAO_INVALIDA;
    }

    // o tamanho nao pode ser menor que 1
    if(tamanho < 1){
        return TAMANHO_INVALIDO;
    }

	posicao--; // posicao será ajustado para ser o indíce real no vetorPrincipal

    // a posicao pode já existir estrutura auxiliar
    if(vetorPrincipal[posicao].estruturaAuxiliar){
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }
    
    // deu tudo certo, crie
    vetorPrincipal[posicao].estruturaAuxiliar = malloc(sizeof(int)*tamanho);

	// o tamanho ser muito grande
	if(!vetorPrincipal[posicao].estruturaAuxiliar){
		return SEM_ESPACO_DE_MEMORIA;
	}

	// caso tudo der certo adicionar tamanho e quantidade zerada
	vetorPrincipal[posicao].tamanho = tamanho;
	vetorPrincipal[posicao].preenchidos = 0;
    return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor){
	
    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        return POSICAO_INVALIDA;
    }

	posicao--; // posicao será ajustado para ser o indíce real no vetorPrincipal 

    if(!vetorPrincipal[posicao].estruturaAuxiliar){
        return SEM_ESTRUTURA_AUXILIAR;
    }

    // testa se ainda há espaço na estrutura auxiliar
	if(vetorPrincipal[posicao].preenchidos == vetorPrincipal[posicao].tamanho){
		return SEM_ESPACO;
	}

	// insere
	vetorPrincipal[posicao].estruturaAuxiliar[vetorPrincipal[posicao].preenchidos] = valor;
	vetorPrincipal[posicao].preenchidos++;
    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
	if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
		return POSICAO_INVALIDA;
	}

	posicao--; // posicao será ajustado para ser o indíce real no vetorPrincipal 
	
	if(!vetorPrincipal[posicao].estruturaAuxiliar){
		return SEM_ESTRUTURA_AUXILIAR;
	}

	if(vetorPrincipal[posicao].preenchidos == 0){
		return ESTRUTURA_AUXILIAR_VAZIA;
	}
	
	vetorPrincipal[posicao].preenchidos--;
    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
	if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
		return POSICAO_INVALIDA;
	}

	posicao--; // posicao será ajustado para ser o indíce real no vetorPrincipal 
	
	if(!vetorPrincipal[posicao].estruturaAuxiliar){
		return SEM_ESTRUTURA_AUXILIAR;
	}

	if(vetorPrincipal[posicao].preenchidos == 0){
		return ESTRUTURA_AUXILIAR_VAZIA;
	}
	
	for(int i = 0; i < vetorPrincipal[posicao].preenchidos; i++){
		if(vetorPrincipal[posicao].estruturaAuxiliar[i] == valor){
			shiftEstruturaAuxiliar(posicao, i);
			vetorPrincipal[posicao].preenchidos--;
			return SUCESSO;
		}
	}
	return NUMERO_INEXISTENTE;
}

// Se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    if (posicao < 1 || posicao > 10)
    {
        return POSICAO_INVALIDA;
    }
    else{
		return SUCESSO;
	} 
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
		return POSICAO_INVALIDA;
	}

	posicao--; // posicao será ajustado para ser o indíce real no vetorPrincipal 
	
	if(!vetorPrincipal[posicao].estruturaAuxiliar){
		return SEM_ESTRUTURA_AUXILIAR;
	}

    // Passando os valores da estrutura para um vetor auxiliar
    for(int i = 0; i < vetorPrincipal[posicao].preenchidos; i++){
        vetorAux[i] = vetorPrincipal[posicao].estruturaAuxiliar[i];
    }
    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
		return POSICAO_INVALIDA;
	}

	posicao--; // posicao será ajustado para ser o indíce real no vetorPrincipal 
	
	if(!vetorPrincipal[posicao].estruturaAuxiliar){
		return SEM_ESTRUTURA_AUXILIAR;
	}

    // Passando os valores da estrutura para um vetor auxiliar
    for(int i = 0; i < vetorPrincipal[posicao].preenchidos; i++){
        vetorAux[i] = vetorPrincipal[posicao].estruturaAuxiliar[i];
    }
    quicksort(vetorAux, 0, vetorPrincipal[posicao].preenchidos-1);
    return SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int estruturasVazias = 0;
    for(int i = 0; i < TAM; i++){
        if(vetorPrincipal[i].preenchidos == 0){
            estruturasVazias++;
        }
    }
    if(estruturasVazias == TAM){
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    
    tamLista = 0;
    for(int i = 0, indexAux = 0; i < TAM; i++){
        if(vetorPrincipal[i].preenchidos != 0){
            for(int j = 0; j < vetorPrincipal[i].preenchidos; j++, indexAux++){
                vetorAux[indexAux] = vetorPrincipal[i].estruturaAuxiliar[j];
                tamLista++;
            }
        }
    }
    
    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int estruturasVazias = 0;
    for(int i = 0; i < TAM; i++){
        if(vetorPrincipal[i].preenchidos == 0){
            estruturasVazias++;
        }
    }
    if(estruturasVazias == TAM){
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }

    int indexAux = 0;
    for(int i = 0; i < TAM; i++){
        if(vetorPrincipal[i].preenchidos != 0){
            for(int j = 0; j < vetorPrincipal[i].preenchidos; j++, indexAux++){
                vetorAux[indexAux] = vetorPrincipal[i].estruturaAuxiliar[j];
            }
        }
    }

    quicksort(vetorAux, 0, indexAux-1);
    return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        return POSICAO_INVALIDA;
    }

    posicao--; // posicao será ajustado para ser o indíce real no vetorPrincipal

    if(vetorPrincipal[posicao].tamanho + novoTamanho < 1){
        return NOVO_TAMANHO_INVALIDO;
    }

    if(!vetorPrincipal[posicao].estruturaAuxiliar){
        return SEM_ESTRUTURA_AUXILIAR;
    }

    vetorPrincipal[posicao].estruturaAuxiliar = realloc(vetorPrincipal[posicao].estruturaAuxiliar,sizeof(node)*(vetorPrincipal[posicao].tamanho + novoTamanho));

    if(vetorPrincipal[posicao].estruturaAuxiliar){
        vetorPrincipal[posicao].tamanho += novoTamanho;
        if(vetorPrincipal[posicao].preenchidos > vetorPrincipal[posicao].tamanho){
            vetorPrincipal[posicao].preenchidos = vetorPrincipal[posicao].tamanho;
        }
        return SUCESSO;
    }
    return SEM_ESPACO_DE_MEMORIA;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    return vetorPrincipal[posicao-1].preenchidos;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
    int vetorAux[20];
    if(getDadosDeTodasEstruturasAuxiliares(vetorAux) == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS){
        return NULL;
    }

    No *inicio = malloc(sizeof(No));
    No *nodoAnterior = inicio;
    nodoAnterior->conteudo = vetorAux[0];
    for(int i = 1; i < tamLista; i++){
        nodoAnterior = adicionarNodo(nodoAnterior, vetorAux[i]);
    }
    return inicio;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    int index = 0;
    while(inicio){
        vetorAux[index] = inicio->conteudo;
        inicio = inicio->prox;
        index++;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
    for(int i = 0; i < TAM; i++){
        vetorPrincipal[i].estruturaAuxiliar = NULL;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
    for(int i = 0; i < TAM; i++){
        free(vetorPrincipal[i].estruturaAuxiliar);
    }
}

// Faz o shift de todos os elementos em uma estrutura auxiliar a partir de determinada posição, seguindo a direita
void shiftEstruturaAuxiliar(int posicao, int posicaoAtual){
    for(int i = posicaoAtual; i < vetorPrincipal[posicao].preenchidos-1; i++){
        vetorPrincipal[posicao].estruturaAuxiliar[i] = vetorPrincipal[posicao].estruturaAuxiliar[i+1];
    }
}

// Algoritmo de ordenação
void quicksort(int number[],int first,int last){
	int i, j, pivot, temp;

	if(first<last){
		pivot=first;
		i=first;
		j=last;

		while(i<j){
			while(number[i]<=number[pivot]&&i<last){
				i++;
			}
			while(number[j]>number[pivot]){
				j--;
			}

			if(i<j){
				temp=number[i];
				number[i]=number[j];
				number[j]=temp;
			}
		}
		
		temp=number[pivot];
		number[pivot]=number[j];
		number[j]=temp;

		quicksort(number,first,j-1);
		quicksort(number,j+1,last);
	}
}

void printaLista(No *inicioLista){
    No *node = inicioLista;
    printf("Lista completa: ");
    while(node){
        printf("[%d] ", node->conteudo);
        if(node->prox == NULL){
            break;
        }
        node = node->prox;
    }
}

No* adicionarNodo(No *nodoAnterior, int valor){
    No *nodoNovo = malloc(sizeof(No));
    nodoNovo->conteudo = valor;
    nodoNovo->prox = NULL;
    nodoAnterior->prox = nodoNovo;
    return nodoNovo;
}