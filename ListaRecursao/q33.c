// Função que retorna o menor elemento de um vetor
#include <stdio.h>
#define n 5

int menorElemento(int vetor[], int tamanho);

int main(){
    int vetor[n] = {1, 5, -3, -10, -5};
    printf("%d", menorElemento(vetor, n-1));
    return 0;
}

int menorElemento(int vetor[], int tamanho){
    if(tamanho > 0){
        int menor = menorElemento(vetor, tamanho-1);
        if(vetor[tamanho] < menor){
            return vetor[tamanho];
        }
        return menor;
    }
    return vetor[tamanho];
}