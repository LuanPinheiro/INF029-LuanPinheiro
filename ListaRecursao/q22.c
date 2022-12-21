// Função que retorna o N-ésimo termo da sequência de tetranacci
#include <stdio.h>

int tetranacci(int N);

int main(){
    int N = 7;
    printf("%d", tetranacci(N));
    return 0;
}

int tetranacci(int N){
    if(N < 0){
        printf("Entrada Invalida");
        return -1;
    }
    if(N == 0 || N == 1 || N == 2){
        return 0;
    }
    if(N == 3){
        return 1;
    }
    if(N > 3){
        return tetranacci(N-1) + tetranacci(N-2) + tetranacci(N-3) + tetranacci(N-4);
    }
}