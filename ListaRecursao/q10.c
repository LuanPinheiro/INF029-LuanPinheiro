// Função que retorna quantas vezes um dígito K aparece em um número N
#include <stdio.h>

int digitoEmNumero(int k, int n, int ocorrencias);

int main(){
    int k = 5, n = 1532525;
    printf("%d", digitoEmNumero(k, n, 0));
    return 0;
}

int digitoEmNumero(int k, int n, int ocorrencias){
    int digitoAtual;
    if(k > 9 || k < 0 || n < 0){
        printf("Entrada Invalida");
        return -1;
    }
    if(n > 0){
        digitoAtual = n%10;
        if(digitoAtual == k){
            ocorrencias++;
        }
        return digitoEmNumero(k, n/10, ocorrencias);
    }
    return ocorrencias;
}