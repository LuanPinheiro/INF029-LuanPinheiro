// Função que retorna o N-ésimo número da sequencia de Fibonacci
#include <stdio.h>
#define N 8

int fibonacci(int num);

int main(){
    printf("%d", fibonacci(N));
    return 0;
}

int fibonacci(int num){
    if(num < 0){
        printf("Numero Invalido");
        return -1;
    }
    if(num == 0 || num == 1){
        return 1;
    }
    if(num > 1){
        return (fibonacci(num - 1) + fibonacci(num - 2)); 
    }
}