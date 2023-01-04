// Função que calcula a soma de dois números naturais, através de somas recursivas
#include <stdio.h>

int soma(int n1, int n2);

int main(){
    int n1 = 5, n2 = 10;
    printf("%d", soma(n1, n2));
    return 0;
}

int soma(int n1, int n2){
    if(n1 < 0 || n2 < 0){
        printf("Entrada Invalida");
        return -1;
    }
    if(n2 == 0){
        return n1;
    }
    return soma(n1+1, n2-1);
}