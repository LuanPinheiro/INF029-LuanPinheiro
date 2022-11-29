#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define n 10

typedef struct{
    int tam[n]; // Controlará o tamanho dos vetores já alocados
    int qtdPreenchidos[n] // Controlará quantos numeros ja foram preenchidos em cada vetor
}aloc;

void menu();
void limpaTela();
aloc insertElemento(int *vetorPrincipal[], aloc controlador);

int main(){
    // Estrutura principal sendo declarada, os vetores de inteiros, que serão dinamicamente alocados dentro do vetorPrincipal
    int *vetorPrincipal[n] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    aloc controlador;
    int op;

    for(int i = 0; i < n; i++){
        controlador.qtdPreenchidos[i] = 0;
    }

    do{
		limpaTela();
        printf("Escolha uma opcao\n\n");
        menu();
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
	
    free(vetorPrincipal[0]);
	free(vetorPrincipal[1]);
	free(vetorPrincipal[2]);
	free(vetorPrincipal[3]);
	free(vetorPrincipal[4]);
	free(vetorPrincipal[5]);
	free(vetorPrincipal[6]);
	free(vetorPrincipal[7]);
	free(vetorPrincipal[8]);
	free(vetorPrincipal[9]);
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

	if(vetorPrincipal[op] == NULL){
		do{
            printf("Vetor ainda nao alocado, digite o tamanho da estrutura\n");
            scanf("%d", &controlador.tam[op]);
            getchar();
        }while(controlador.tam[op] < 1);
		vetorPrincipal[0] = malloc(sizeof(int)*controlador.tam[op]);
	}

    if(controlador.qtdPreenchidos[op] == controlador.tam[op]){
        printf("Limite do vetor atingido");
		limpaTela();
    }
    else{
        printf("Digite o valor a ser inserido\n");
        scanf("%d", &vetorPrincipal[op][controlador.qtdPreenchidos[op]]);
        getchar();
        controlador.qtdPreenchidos[op]++;
    }
	
    return controlador;
}

void listarTodos(int *vetorPrincipal[], aloc controlador){
	limpaTela();
	for(int indexPrincipal = 0; indexPrincipal < n; indexPrincipal++){
		
	}
}

void limpaTela(){
	printf("\n\n(APERTE ENTER PARA CONTINUAR)\n");
	getchar();
	system("clear");
}