// Função que retorna o N-ésimo termo da sequência de tribonacci
#include <stdio.h>

int tribonacci(int N);

int main(){
    int N = 7;
    printf("%d", tribonacci(N));
    return 0;
}

int tribonacci(int N){
    if(N <= 0){
        printf("Entrada Invalida");
        return -1;
    }
    if(N == 0 || N == 1){
        return 0;
    }
    if(N == 2){
        return 1;
    }
    if(N > 2){
        return tribonacci(N-1) + tribonacci(N-2) + tribonacci(N-3);
    }
}