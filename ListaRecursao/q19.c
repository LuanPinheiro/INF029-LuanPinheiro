// Função que retorna o hiperfatorial de um número inteiro positivo N
#include <stdio.h>

int hiperFatorial(int N);
int potencia(int k, int n);

int main(){
    int N = 4;
    printf("%d", hiperFatorial(N));
    return 0;
}

int hiperFatorial(int N){
    if(N < 0){
        printf("Entrada Invalida");
        return -1;
    }
    if(N == 0 || N == 1){
        return 1;
    }
    if(N > 1){
        return potencia(N, N) * hiperFatorial(N-1);
    }
}

int potencia(int k, int n){
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return k;
    }
    if(n > 1){
        return k * potencia(k, --n);
    }
}