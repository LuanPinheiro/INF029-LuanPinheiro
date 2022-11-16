#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void mudar(int *vetorPrincipal[]);

int main(){
    int *vet1 = malloc(sizeof(int)*3);
    int *vet2 = malloc(sizeof(int)*3);
    int *vet3 = malloc(sizeof(int)*3);
    int *vetorPrincipal[3] = {vet1, vet2, vet3};
    vet1[0] = 5;
    vet1[1] = 6;
    vet1[2] = 7;

    printf("Valores ANTES: %d %d %d\n", vet1[0], vet1[1], vet1[2]);
    printf("Enderecos ANTES: %x %x %x %x\n", &vet1[0], &vet1[1], &vet1[2], &vet1[3]);
    mudar(vetorPrincipal);
    printf("Valores DEPOIS: %d %d %d\n", vet1[0], vet1[1], vet1[2]);
    printf("Enderecos DEPOIS: %x %x %x %x\n", &vet1[0], &vet1[1], &vet1[2], &vet1[3]);

    free(vetorPrincipal);
    free(vet1);
    free(vet2);
    free(vet3);

    return 0;
}

void mudar(int *vetorPrincipal[]){
    int *pointer, count = 0;
    pointer = *vetorPrincipal;
    printf("\nEnderecos FUNCAO: %x %x %x\n", &pointer[0], &pointer[1], &pointer[2]);
    printf("\nValores FUNCAO: %d %d %d\n\n", pointer[0], pointer[1], pointer[2]);
    pointer = realloc(*pointer, sizeof(int)*5);
}