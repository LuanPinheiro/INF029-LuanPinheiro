// Função que recebe dois inteiros k e n e calcula a potência de k elevado a n
#include <stdio.h>

int potencia(int k, int n);

int main(){
    int k, n;
    scanf("%d%d", &k, &n);
    printf("%d", potencia(k, n));
    return 0;
}

int potencia(int k, int n){
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return k;
    }
    if(n > 1){
        return k * potencia(k, --n);
    }
}