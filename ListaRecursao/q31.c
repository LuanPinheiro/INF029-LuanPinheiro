// Função que recebe 3 valores inteiros i,j,k, e printa todos os números no intervalo [i,j] com incremento k
#include <stdio.h>

int valoresIntervalo(int i, int j, int k);

int main(){
    int i = 2, j = 20, k = 3;
    valoresIntervalo(i,j,k);
    return 0;
}

int valoresIntervalo(int i, int j, int k){
    if (i > j){
        return 0;
    }
    if(i <= j){
        printf("[%d] ", i);
        i += k;
        return valoresIntervalo(i, j, k);
    }
}