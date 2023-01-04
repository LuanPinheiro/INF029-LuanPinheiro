// Função que retorna o resultado da função dada a regra: S = 2 + 5/2 + 10/3 + 1+n²/n
#include <stdio.h>

int funcao(int n);

int main(){
    int n = 4;
    printf("%d", funcao(n));
    return 0;
}

int funcao(int n){
    if(n < 0){
        printf("Entrada Invalida");
        return -1;
    }
    if(n == 0){
        return 2;
    }
    if(n == 1 || n == 2){
        return funcao(n-1) + ((5*n)/(n+1));
    }
    if(n > 2){
        return funcao(n-1) + ((1+(n*n))/n);
    }
}