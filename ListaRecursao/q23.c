// Função que retorna o N-ésimo termo da sequência de Padovan
#include <stdio.h>

int padovan(int N);

int main(){
    int N = 8;
    printf("%d", padovan(N));
    return 0;
}

int padovan(int N){
    if(N < 0){
        printf("Entrada Invalida");
        return -1;
    }
    if(N == 0 || N == 1 || N == 2){
        return 1;
    }
    if(N > 2){
        return padovan(N-2) + padovan(N-3);
    }
}