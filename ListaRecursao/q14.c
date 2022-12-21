// Função que dado um número N par, imprime todos os numeros pares de 0 a N em ordem crescente
#include <stdio.h>

int numerosN(int N);

int main(){
    int N = 6;
    if(!(N%2)){
        numerosN(N);
    }
    else{
        printf("Entrada Impar");
    }
    
    return 0;
}

int numerosN(int N){
    if(N > 0){
        numerosN(N-1);
        if(!(N%2)){
            printf("%d ", N);
        }
    }
}