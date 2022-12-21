// Função que retorna o superfatorial de um número inteiro positivo N
#include <stdio.h>

int fatorial(int numero);
int superFatorial(int N);

int main(){
    int N = 4;
    printf("%d", superFatorial(N));
    return 0;
}

int superFatorial(int N){
    int retorno;
    if(N < 0){
        printf("Entrada Invalida");
        return -1;
    }
    if(N == 1 || N == 0){
        return 1;
    }
    if(N > 1){
        retorno = N * fatorial(N-1);
        if(N-1){
            retorno *= superFatorial(N-1);
        }
        return retorno;
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