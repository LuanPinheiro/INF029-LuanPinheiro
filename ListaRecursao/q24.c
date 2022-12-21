// Função que retorna o N-ésimo número de Pell
#include <stdio.h>

int pell(int N);

int main(){
    int N = 2;
    printf("%d", pell(N));
    return 0;
}

int pell(int N){
    if(N < 0){
        printf("Entrada Invalida");
        return -1;
    }
    if(N < 2){
        return N;
    }
    if(N >= 2){
        return (2*pell(N-1) + pell(N-2));
    }
}