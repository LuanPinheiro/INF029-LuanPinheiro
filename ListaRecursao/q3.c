// Função que retorna um número invertido
#include <stdio.h>
#define N 15384

int inverteNum(int num, int num_invertido);

int main(){
    printf("%d ", inverteNum(N, 0));
    return 0;
}

int inverteNum(int num, int num_invertido){
    if(num > 0){
        return inverteNum(num/10, (num%10 + num_invertido*10));
    }
    else{
        return num_invertido;
    }
}