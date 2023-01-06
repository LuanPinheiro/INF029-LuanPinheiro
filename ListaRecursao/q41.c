// Função que dado um número n, mostra todas as combinações possiveis das n primeiras letras do alfabeto
#include <stdio.h>
#include <stdlib.h>
#define n 6

char letras[n];
int combinacoes(int index);
void preencheLetras();
void trocaChar(int index1, int index2);

int main(){
    preencheLetras(); // Preenche em ordem alfabética
    combinacoes(0);
    return 0;
}

int combinacoes(int index){
    if(n > 26 || n < 1){
        printf("Entrada Invalida");
        return 0;
    }

    if(index == n){ // Fim do loop
        printf("%s\n", letras);
        return 0;
    }
    for (int i = index; i < n; i++) {
        trocaChar(letras, index, i);
        combinacoes(index+1);
        trocaChar(letras, i, index);
    }
}

void preencheLetras(){
    for(int index = 0; index < n; index++){
        letras[index] = 65 + index;
    }
}

void trocaChar(int index1, int index2){
    char aux = letras[index1];
    letras[index1] = letras[index2];
    letras[index2] = aux;
}