#include <stdio.h>
#include <stdbool.h>

void limparString(char string[]);
void printHud(char tabuleiro[3][3]);
int trocarPlayer(int player);
int checkVitoriaVertical(char velha[3][3], int jogadaColuna);
int checkVitoriaHorizontal(char velha[3][3], int jogadaLinha);
int checkVitoriaDiagonal(char velha[3][3], char jogadaPlayer);

int main(){
    char velha[3][3];
    char celula[4];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            velha[i][j] = ' ';
        }
    }

    int win = 0; // Condição de vitória
    int player = 1; // Qual player está jogando
    int jogadas = 9; // Quantas jogadas faltam
    int valid; // Validador de jogada, se é uma célula existente e vazia
    int jogadaLinha, jogadaColuna; // Coordenadas da jogada
    char jogadaPlayer; // Caractere que ficará na célula

    do{
        do{
            system("clear");
            printHud(velha);
            printf("\nJogador %d:\n", player);

            valid = true;
            fgets(celula, 4, stdin);
            limparString(celula);
            if(celula[0] != 'A' && celula[0] != 'B' && celula[0] != 'C'){
                valid = false;
            }
            else if(celula[1] != '1' && celula[1] != '2' && celula[1] != '3'){
                valid = false;
            }

            jogadaLinha = celula[0] - 48 - 17; // Calculando posição real da jogada em ASCII
            jogadaColuna = celula[1] - 48 - 1;

            if(velha[jogadaLinha][jogadaColuna] != ' '){
                valid = false;
            }
            if(valid == false){
                printf("\nCELULA INVALIDA\n");
                getchar();
            }
        }while(valid == false);

        switch(player){
            case 1: jogadaPlayer = 'X'; break;
            case 2: jogadaPlayer = 'O'; break;
        }

        velha[jogadaLinha][jogadaColuna] = jogadaPlayer; // Jogada realizada

        if(checkVitoriaVertical(velha, jogadaColuna) == true || checkVitoriaHorizontal(velha, jogadaLinha) == true || checkVitoriaDiagonal(velha, jogadaPlayer) == true){
            win = player; // checando se o jogador venceu, se sim as jogadas serão interrompidas, e o jogo finalizado;
            break;
        }
        player = trocarPlayer(player);
        jogadas--; // Tendo 9 jogadas, quando chega a 0 acabam as jogadas possiveis
    }while(jogadas > 0);

    system("clear");
    printHud(velha); // Um último print com o resultado de todas as jogadas
    switch(win){
        case 1: printf("Jogador 1 venceu!\n"); break;
        case 2: printf("Jogador 2 venceu!\n"); break;
        default: printf("Deu velha!\n");
    }
    
    return 0;
}

//****************** Usada para retirar o '\n' após inserir uma string[] via fgets()
void limparString(char string[]){
  for(int i=0;string[i]!='\0';i++)
      if(string[i]=='\n')
        string[i] = '\0';
}

void printHud(char velha[3][3]){
    printf("  1   2   3\n");
    printf("A %c | %c | %c \n", velha[0][0], velha[0][1], velha[0][2]);
    printf(" -----------\n");
    printf("B %c | %c | %c \n", velha[1][0], velha[1][1], velha[1][2]);
    printf(" ----------- \n");
    printf("C %c | %c | %c \n", velha[2][0], velha[2][1], velha[2][2]);
}

int checkVitoriaVertical(char velha[3][3], int jogadaColuna){
    for(int i=0; i<2; i++){
        if(velha[i][jogadaColuna] != velha[i+1][jogadaColuna]){
            return false;
        }
    }
    return true; 
}

int checkVitoriaHorizontal(char velha[3][3], int jogadaLinha){
    for(int i=0; i<2; i++){
        if(velha[jogadaLinha][i] != velha[jogadaLinha][i+1]){
            return false;
        }
    }
    return true;
}

int checkVitoriaDiagonal(char velha[3][3], char jogadaPlayer){
    if(velha[1][1] == jogadaPlayer){
        if(velha[0][0] == jogadaPlayer && velha[2][2] == jogadaPlayer){
        return true;
        }
        else{
            if(velha[2][0] == jogadaPlayer && velha[0][2] == jogadaPlayer){
                return true;
            }
            else{
                return false;
            }
        }
    }
    else{
        return false;
    }
}

int trocarPlayer(int player){
    if(player == 1){
        player = 2;
    }
    else{
        player = 1;
    }
    return player;
}