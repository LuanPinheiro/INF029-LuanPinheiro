// Função que dado uma matriz 10x10, que é um labirinto aleatório de 0's e 1's retorna se há saída
// Incompleto, não está encontrando um caminho corretamente sempre
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define tam 10
#define seed 456 // Seed do labirinto

void preencheLabirinto(int labirinto[tam][tam]);
void printaLabirinto(int labirinto[tam][tam]);
int caminho(int labirinto[tam][tam], int linha, int coluna, int qtdJogadas);
char* proxJogada(int labirinto[tam][tam], int linha, int coluna);

int main(){
    int labirinto[tam][tam];
    preencheLabirinto(labirinto);
    printaLabirinto(labirinto);
    if(!caminho(labirinto, 0, 0, 0)){
        printf("Nao tem caminho");
    }
}

void preencheLabirinto(int labirinto[tam][tam]){
    srand(seed);
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            labirinto[i][j] = rand() % 2;
        }
    }
    labirinto[0][0] = 0;
    labirinto[9][9] = 0;
    for(int i = 0; i < tam; i++){
        labirinto[i][6] = 0; // para debug, abrindo espaço no labirinto para não depender de seed
        labirinto[i][5] = 0;
        labirinto[i][4] = 0;
    }
}

void printaLabirinto(int labirinto[tam][tam]){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            printf("[%d]", labirinto[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int caminho(int labirinto[tam][tam], int linha, int coluna, int qtdJogadas){
    if(qtdJogadas > 3000){
        return false;
    }
    int baixo = linha+1;
    int direita = coluna+1;
    int cima = linha-1;
    int esquerda = coluna-1;
    char ultimaJogada[2] = {linha, coluna};
    char *proximaJogada;
    system("PAUSE");
    if(linha == 9 && coluna == 9){
        printf("Tem Caminho");
        return true;
    }
    if(labirinto[linha][direita] == 0 && direita < tam){
        proximaJogada = proxJogada(labirinto, linha, direita);
        printf("%c%c / %c%c\n", ultimaJogada[0]+48, ultimaJogada[1]+48, proximaJogada[0]+48, proximaJogada[1]+48);
        if (proximaJogada[0] != ultimaJogada[0] || proximaJogada[1] != ultimaJogada[1]){
            return caminho(labirinto, linha, direita, qtdJogadas+1);
        }
    }
    if(labirinto[baixo][coluna] == 0 && baixo < tam){
        proximaJogada = proxJogada(labirinto, baixo, coluna);
        printf("%c%c / %c%c\n", ultimaJogada[0]+48, ultimaJogada[1]+48, proximaJogada[0]+48, proximaJogada[1]+48);
        if (proximaJogada[0] != ultimaJogada[0] || proximaJogada[1] != ultimaJogada[1]){
            return caminho(labirinto, baixo, coluna, qtdJogadas+1);
        }
    }
    if(labirinto[cima][coluna] == 0 && cima >= 0){
        proximaJogada = proxJogada(labirinto, cima, coluna);
        printf("%c%c / %c%c\n", ultimaJogada[0]+48, ultimaJogada[1]+48, proximaJogada[0]+48, proximaJogada[1]+48);
        if (proximaJogada[0] != ultimaJogada[0] || proximaJogada[1] != ultimaJogada[1]){
            return caminho(labirinto, cima, coluna, qtdJogadas+1);
        }
    }
    if(labirinto[linha][esquerda] == 0 && esquerda >= 0){
        proximaJogada = proxJogada(labirinto, linha, esquerda);
        printf("%c%c / %c%c\n", ultimaJogada[0]+48, ultimaJogada[1]+48, proximaJogada[0]+48, proximaJogada[1]+48);
        if (proximaJogada[0] != ultimaJogada[0] || proximaJogada[1] != ultimaJogada[1]){
            return caminho(labirinto, linha, esquerda, qtdJogadas+1);
        }
    }
    return false;
}

char* proxJogada(int labirinto[tam][tam], int linha, int coluna){
    int baixo = linha+1;
    int direita = coluna+1;
    int cima = linha-1;
    int esquerda = coluna-1;
    char* jogada = malloc(sizeof(char)*2);
    jogada[0] = linha;
    jogada[1] = coluna;
    printf("DENTRO DA FUNCAO: %c%c\n", jogada[0]+48, jogada[1]+48);
    if(labirinto[linha][direita] == 0 && direita < tam){
        jogada[1] = direita;
    }
    else if(labirinto[baixo][coluna] == 0 && baixo < tam){
        jogada[0] = baixo;
    }
    else if(labirinto[cima][coluna] == 0 && cima >= 0){
        jogada[0] = cima;
    }
    else if(labirinto[linha][esquerda] == 0 && esquerda >= 0){
        jogada[1] = esquerda;
    }
    return jogada;
}