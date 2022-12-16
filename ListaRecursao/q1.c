// Função que calcula o fatorial de N
#include <stdio.h>
#define N 5

int fatorial(int numero);

int main(){
    printf("%d", fatorial(N));
    return 0;
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