// Função que recebe um inteiro N e printa todos os números de 0 a N em ordem decrescente
#include <stdio.h>

int numerosN(int N);

int main(){
    int N = 10;
    numerosN(N);
    return 0;
}

int numerosN(int N){
    if(N >= 0){
        printf("%d ", N);
        numerosN(N-1);
    }
}