#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define n 10

typedef struct{
    int alocados[n]; // Controlará quais vetores ja foram alocados
    int tam[n]; // Controlará o tamanho dos vetores já alocados
    int qtdPreenchidos[n] // Controlará quantos numeros ja foram preenchidos em cada vetor
}aloc;

void menu();
aloc insertElemento(int *vetorPrincipal[], aloc controlador);

int main(){
    // Estrutura principal sendo declarada, os vetores de inteiros, que serão dinamicamente alocados dentro do vetorPrincipal
    int *vet1 = malloc(sizeof(int)),
    *vet2 = malloc(sizeof(int)),
    *vet3 = malloc(sizeof(int)),
    *vet4 = malloc(sizeof(int)),
    *vet5 = malloc(sizeof(int)),
    *vet6 = malloc(sizeof(int)),
    *vet7 = malloc(sizeof(int)),
    *vet8 = malloc(sizeof(int)),
    *vet9 = malloc(sizeof(int)),
    *vet10 = malloc(sizeof(int));
	int *vetorPrincipal[n] = {vet1, vet2, vet3, vet4, vet5, vet6, vet7, vet8, vet9, vet10};
    aloc controlador;
    int op;

    for(int i = 0; i < n; i++){
        controlador.alocados[i] = false;
        controlador.qtdPreenchidos[i] = 0;
    }

    do{
        printf("Escolha uma opcao\n\n");
        menu();
        printf("Valores: ");
        for(int i = 0; i < 5; i++){
            printf("[%d] ", vet1[i]);
        }
        printf("\nEnderecos: ");
        for(int i = 0; i < 5; i++){
            printf("[%x] ", vet1[i]);
        }
        scanf("%d", &op);
        getchar();

        switch(op){
            case 1: controlador = insertElemento(vetorPrincipal, controlador); break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 6: break;
            case 7: printf("ENCERRANDO"); break;
            default: printf("OPCAO INVALIDA\n\n"); getchar(); break;
        }
    }while (op != 7);
	
    free(vet1);
    free(vet2);
    free(vet3);
    free(vet4);
    free(vet5);
    free(vet6);
    free(vet7);
    free(vet8);
    free(vet9);
    free(vet10);
    free(vetorPrincipal);
	return 0;
}

void menu(){
    printf("1. Inserir elemento\n");
    printf("2. Listar todos os numeros\n");
    printf("3. Listar os numeros de cada estrutura ordenados separadamente\n");
    printf("4. Listar todos os numeros ordenados\n");
    printf("5. Excluir elemento\n");
    printf("6. Aumentar tamanho da estrutura\n");
    printf("7. Fechar o programa\n\n");
}

aloc insertElemento(int *vetorPrincipal[], aloc controlador){
    int valid, op;
    int *vet;
    do{
        valid = true;
        printf("Escolha uma posicao na estrutura principal\n");
        scanf("%d", &op);
        getchar();
        if(op > 10 || op < 1){
            printf("POSICAO INVALIDA\n\n");
            valid = false;
        }
    }while(valid == false);
    op--; // Diminuindo o valor em 1 para ter o index correto do vetorPrincipal
    vet = *vetorPrincipal[op];

    if(controlador.alocados[op] == false){ // Caso o vetor da posicao indicada nao estiver alocado, primeiro ira alocar
        do{
            printf("Vetor ainda nao alocado, digite o tamanho da estrutura\n");
            scanf("%d", &controlador.tam[op]);
            getchar();
        }while(controlador.tam[op] < 1);

        vet = realloc(*vet, sizeof(int)*controlador.tam[op]);
        controlador.alocados[op] = true;
    }

    if(controlador.qtdPreenchidos[op] == controlador.tam[op]){
        printf("Limite do vetor atingido\n");
    }
    else{
        vet = *vetorPrincipal[op];
        printf("ENDERECO: %x\nvet[0]: %x\n", vet, &vet[controlador.qtdPreenchidos[op]]);
        printf("Digite o valor a ser inserido\n");
        scanf("%d", &vet[controlador.qtdPreenchidos[op]]);
        getchar();
        controlador.qtdPreenchidos[op]++;
    }

    return controlador;
}