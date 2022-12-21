// Função que retorna o N-ésimo número de Catalan
#include <stdio.h>

float catalan(int N);

int main(){
    int N = 5;
    printf("%.0f", catalan(N));
    return 0;
}

float catalan(int N){
    if(N < 0){
        printf("Entrada Invalida");
        return -1;
    }
    if(N == 0){
        return 1;
    }
    if(N > 0){
        return (((2.0*(2.0*N-1.0))/(N+1.0)) * catalan(N-1.0));
    }
}