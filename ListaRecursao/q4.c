// Função que soma os valores de um vetor de inteiros
#include <stdio.h>

int somaVetor(int vetor[], int index, int tam);

int main(){
    int vetor[] = {1, 4, 6, 10, 5};
    int tam = 5;
    printf("%d", somaVetor(vetor, 0, tam));
    return 0;
}

int somaVetor(int vetor[], int index, int tam){
    if(index < 0){
        printf("Parametro Invalido");
        return -1;
    }
    if(index == tam){
        return 0;
    }
    if(index >= 0){
        return (vetor[index] + somaVetor(vetor, ++index, tam));
    }
}