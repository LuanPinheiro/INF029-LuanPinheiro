// Função que calcula a multiplicação de dois números naturais, através de incrementos recursivos
#include <stdio.h>

int multiplica(int n1, int n2);

int main(){
    int n1 = 5, n2 = 10;
    printf("%d", multiplica(n1, n2));
    return 0;
}

int multiplica(int n1, int n2){
    if(n1 < 0 || n2 < 0){
        printf("Entrada Invalida");
        return -1;
    }
    if(n2 == 0){
        return 0;
    }
    if(n2 == 1){
        return n1;
    }
    return n1 + multiplica(n1, n2-1);
}