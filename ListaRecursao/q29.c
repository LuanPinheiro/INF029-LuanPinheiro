// Função que segue a regra n = 1 -> m+1, m = 1 -> n+1, m>1 n>1 -> F(m,n-1)+F(m-1,n)
#include <stdio.h>

int funcaoCustom(int m, int n);

int main(){
    int m = 5, n = 3;
    printf("%d", funcaoCustom(m, n));
    return 0;
}

int funcaoCustom(int m, int n){
    if(n == 1){
        return m+1;
    }
    if(m == 1){
        return n+1;
    }
    if(m > 1 && n > 1){
        return funcaoCustom(m,n-1) + funcaoCustom(m-1,n);
    }
    printf("Entrada Invalida");
    return -1;
}