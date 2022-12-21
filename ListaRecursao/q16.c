// Função que retorna o fatorial duplo de um número impar N
#include <stdio.h>

int fatorialDuplo(int N);

int main(){
    int N = 5;
    if(N%2){
        printf("%d", fatorialDuplo(N));
    }
    else{
        printf("Entrada Par");
    }
    return 0;
}

int fatorialDuplo(int N){
    if(N < 0){
        printf("Entrada Invalida ");
        return -1;
    }
    if(N == 0 || N == 1){
        return 1;
    }
    if(N > 1){
        if(N%2){
            return N * fatorialDuplo(N-1);
        }
        else{
            return fatorialDuplo(N-1);
        }
    }
}