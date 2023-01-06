// Função que gera todas as combinações possíveis da megasena
// INCOMPLETA
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define n 6
#define maxCombinacoes 50063860

int numeros[n];
int combinacoes(long int index);
void preencheNumeros();
void trocaNum(int index1, int index2);
void quickSort(int number[],int first,int last);

int main(){
    preencheNumeros(); // Preenche um vetor com todas as dezenas
    combinacoes(0);
    return 0;
}

int combinacoes(long int index){
    if(n > 26 || n < 1){
        printf("Entrada Invalida");
        return 0;
    }

    if(index == maxCombinacoes){
        printf("\nFim\n");
        return 0;
    }
    printf("Combinacao %ld: ", index);
    for(int i = 0; i < n; i++){
        printf("[%d]", numeros[i]);
    }
    printf("\n");
    int repetido;
    for (int i = 0; i < n; i++){
        do{
            numeros[i] = rand() % 60 + 1; // gera número entre 1 e 60
            repetido = false;
            for (int j=0; j<i; j++){ // verifica se o numero ja foi sorteado nesse jogo
                if (numeros[j] == numeros[i]){
                    repetido = true;
                }
            }
        }while(repetido == true);
    }
    quickSort(numeros, 0, 6);
    combinacoes(index+1);
}

void preencheNumeros(){
    for(int index = 0; index < n; index++){
        numeros[index] = index;
    }
}

void trocaNum(int index1, int index2){
    int aux = numeros[index1];
    numeros[index1] = numeros[index2];
    numeros[index2] = aux;
}

void quickSort(int number[],int first,int last){
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

		quickSort(number,first,j-1);
		quickSort(number,j+1,last);
	}
}