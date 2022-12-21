// Função que recebe um inteiro N e printa todos os números de 0 a N em ordem crescente
#include <stdio.h>

int numerosN(int N);

int main(){
    int N = 3;
    numerosN(N);
    return 0;
}

int numerosN(int N){
    if(N >= 0){
        numerosN(N-1);
        printf("%d ", N);
    }
}