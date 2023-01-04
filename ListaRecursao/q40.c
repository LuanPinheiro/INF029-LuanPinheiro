// Função que retorna o valor na sequencia: F(1) = 1, F(2) = 2, F(n) = 2 * F(n-1) + 3 * F(n-2)
#include <stdio.h>

int funcao(int n);

int main(){
    int n = 5;
    printf("%d", funcao(n));
    return 0;
}

int funcao(int n){
    if(n == 1 || n == 2){
        return n;
    }
    return (2 * funcao(n-1)) + 3 * (funcao(n-2));
}