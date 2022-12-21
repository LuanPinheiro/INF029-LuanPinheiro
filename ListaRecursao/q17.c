// Função que retorna o fatorial quádruplo de um número inteiro positivo N
#include <stdio.h>

int main(){
    int N = 3;
    printf("%d", fatorial(2*N)/fatorial(N));
    return 0;
}

int fatorialQuadruplo(int N){
    int retorno, retorno2;
    if(N < 0){
        printf("Entrada Invalida");
        return -1;
    }
    if(N == 0 || N == 1){
        return 1;
    }
    if(N > 1){
        retorno = N * fatorialQuadruplo(N-1);
        retorno2 = 2*N * fatorial(2*N-1);
        return retorno2 / retorno;
    }
}

int fatorial(int numero){
    if(numero < 0){
        printf("Numero Invalido");
        return -1;
    }
    if(numero == 0 || numero == 1){
        return 1;
    }
    if(numero > 1){
        return numero * fatorial(numero - 1);
    }
}