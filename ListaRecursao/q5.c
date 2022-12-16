// Função que calcula os numeros inteiros positivos de 1 a N somados
#include <stdio.h>
#define N 5

int main(){
    printf("%d", somaPositivos(N));
    return 0;
}

int somaPositivos(int num){
    if(num > 0){
        return num + somaPositivos(num-1);
    }
}