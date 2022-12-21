// Função que dado dois valores m,n não negativos, retornam o resultado da equação de acherman
#include <stdio.h>

int acherman(int m, int n);

int main(){
    int m = 3, n = 3;
    printf("%d", acherman(m,n));
    return 0;
}

int acherman(int m, int n){
    if(m < 0 || n < 0){
        printf("Entrada Invalida");
        return -1;
    }
    if(m == 0){
        return n+1;
    }
    if(m > 0 && n == 0){
        return acherman(m-1,1);
    }
    if(m > 0 && n > 0){
        return acherman(m-1, acherman(m,n-1));
    }
    return 0;
}