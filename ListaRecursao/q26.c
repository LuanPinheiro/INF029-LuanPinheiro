// Função que retorna a N-ésima palavra de fibonacci
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* palavraFibonacci(int num);

int main(){
    int N = 6;
    printf("Final: %s", palavraFibonacci(N));
    return 0;
}

char* palavraFibonacci(int num){
    if(num < 0){
        return "Numero Invalido";
    }
    if(num == 0){
        return "b";
    }
    if(num == 1){
        return "a";
    }
    if(num > 1){
        char *string = malloc(sizeof(char));
        strcpy(string, palavraFibonacci(num-1));
        strcat(string, palavraFibonacci(num-2));
        return string;
    }
}