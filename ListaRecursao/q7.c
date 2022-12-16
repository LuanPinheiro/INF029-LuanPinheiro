// Função que recebe um vetor de 100 elementos float e inverte a ordem dos elementos
#include <stdio.h>
#include <stdbool.h>
#define N 6

int inverteVetor(float vetor[], int inicio, int fim);

int main(){
    float vetor[N] = {1.2, 3.1, 5.0, 4.3, 8.0, 2.5};
    int sucesso = inverteVetor(vetor, 0, N-1);
    if(sucesso){
        for(int i = 0; i < N; i++){
            printf("[%.1f] ", vetor[i]);
        }
    }
    return 0;
}

int inverteVetor(float vetor[], int inicio, int fim){
    float aux = vetor[inicio];
    if(fim > N-1 || inicio < 0){
        printf("Parametros Invalidos");
        return false;
    }
    if(inicio < fim){
        vetor[inicio] = vetor[fim];
        vetor[fim] = aux;
        return inverteVetor(vetor, ++inicio, --fim);
    }
    return true;
}