#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int naviosDeGuerra = 8;
void listarTabuleiroPlayer(char tabuleiro[10][10], int player);
void listarTabuleiroAdversario(char tabuleiro[10][10]);
void inserirBarcos(char tabuleiro[10][10], int qtdBarcos, int player);
void atacarAdversario(char tabuleiroAdversario[10][10], int player, int qtdBarcos);
int exibirOpcoesTamanhos(int tamanho1, int tamanho3, int tamanho4);
void colocarBarco(char tabuleiro[10][10], int player, int tamanhoBarco);
void colocarPosicaoFinal(char tabuleiro[10][10], int posicaoInicialLinha, int posicaoInicialColuna, int tamanhoBarco);
int trocarPlayer(int player);
void limparString(char string[]);

int main(){
    char tabuleiroP1[10][10], tabuleiroP1Adversario[10][10], tabuleiroP2[10][10], tabuleiroP2Adversario[10][10];
    int player = 1, valid, op;
    int qtdBarcosP1 = naviosDeGuerra, qtdBarcosP2 = naviosDeGuerra;
    int win = false;

    for(int i = 0; i < 10; i++){ // Preenchendo os tabuleiros com espaços vazios
        for(int j = 0; j < 10; j++){
            tabuleiroP1[i][j] = ' ';
            tabuleiroP1Adversario[i][j] = ' ';
            tabuleiroP2[i][j] = ' ';
            tabuleiroP2Adversario[i][j] = ' ';
        }
    }
    // Primeira jogada, colocando os navios
    inserirBarcos(tabuleiroP1, qtdBarcosP1, 1);
    inserirBarcos(tabuleiroP2, qtdBarcosP2, 2);

    do{
        do{
            valid = true;
            system("clear");
            printf("JOGADOR: %d", player);
            printf("Menu de Ações:\n");
            printf("1. Ver seu tabuleiro\n2. Atacar Adversario\n");
            scanf("%d", &op);
            getchar();

            switch(op){
                case 1: switch(player){
                    case 1: listarTabuleiroPlayer(tabuleiroP1, player); break;
                    case 2: listarTabuleiroPlayer(tabuleiroP2, player); break;
                } break;

                case 2: switch(player){
                    case 1: atacarAdversario(tabuleiroP1Adversario, player, qtdBarcosP2); break;
                    case 2: atacarAdversario(tabuleiroP2Adversario, player, qtdBarcosP1); break;
                } break;

                default: valid = false;
                    printf("\n(ENTRADA INVALIDA)\n");
                    getchar();
            }
            player = trocarPlayer(player); // Após a jogada troca o player
        }while(valid == false);
    }while(win == false);
    

    return 0;
}

void listarTabuleiroPlayer(char tabuleiro[10][10], int player){
    printf("TABULEIRO DO PLAYER %d\n", player);
    printf("   0   1   2   3   4   5   6   7   8   9\n");
    for(int i = 0; i < 10; i++){
        printf("%c ", 65+i);
        for(int j = 0; j < 10; j++){
            printf("[%c] ",tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void listarTabuleiroAdversario(char tabuleiro[10][10]){
    printf("TABULEIRO DO ADVERSARIO\n");
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            printf("[%c] ",tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Irá pedir ao usuário uma célula para inserir um barco, irá repetir a ação até que todos os barcos sejam colocados em posições válidas
void inserirBarcos(char tabuleiro[10][10], int qtdBarcos, int player){
    char celula[4];
    int valid;
    int tamanho4 = 1, tamanho3 = 1, tamanho1 = 3, tamanhoBarco; // Definindo a quantidade de barcos obrigatorios de cada tipo, e o tamanho do barco que será colocado
    int op, opcoes; // Variavel que indica a opcao selecionada, e variavel que indica o tipo de opcoes que apareceram


    // Há 2 Do's dentro de cada case, um para definir qual barco será inserido, e outro para definir as células em que ele estará
    do{
        do{
            system("clear");
            valid = true;
            printf("JOGADOR %d\n", player);
            opcoes = exibirOpcoesTamanhos(tamanho1, tamanho3, tamanho4);
            printf("\nDigite a opcao: ");
            scanf("%d", &op);
            getchar();
            if(opcoes == 1){
                switch(op){ // Controla a quantidade de barcos obrigatórios que faltam
                    case 1: if(tamanho4 > 0){
                        tamanho4--;
                        tamanhoBarco = 4;
                        }
                        else{
                            valid = false;
                        } break;
                    case 2: if(tamanho3 > 0){
                        tamanho3--;
                        tamanhoBarco = 3;
                        }
                        else{
                            valid = false;
                        } break;
                    case 3: if(tamanho1 > 0){
                        tamanho1--; 
                        tamanhoBarco = 1;
                        }
                        else{
                            valid = false;
                        } break;
                    default: valid = false;
                }
            }
            else{
                if(op != 1){
                    valid = false;
                }
                else{
                    tamanhoBarco = 2;
                }
            }

            if(valid == false){
                printf("\n(OPCAO INVALIDA)");
                getchar();
            }
        }while(valid == false);

        colocarBarco(tabuleiro, player, tamanhoBarco);
        qtdBarcos--;
    }while(qtdBarcos > 0);
}

void atacarAdversario(char tabuleiroAdversario[10][10], int player, int qtdBarcos){
    // ataca uma célula no tabuleiro adversario
}

int exibirOpcoesTamanhos(int tamanho1, int tamanho3, int tamanho4){
    if(tamanho4 > 0 || tamanho3 > 0 || tamanho1 > 0){
        printf("1. Inserir barco tamanho 4");
        if(tamanho4 == 0){
            printf("(ESGOTADO)");
        }

        printf("\n2. Inserir barco tamanho 3");
        if(tamanho3 == 0){
            printf("(ESGOTADO)");
        }

        printf("\n3. Inserir barco tamanho 1");
        if(tamanho1 == 0){
            printf("(ESGOTADO)");
        }
        return 1;
    }
    else{
        printf("1. Inserir Barco tamanho 2\n");
        return 2;
    }
}

// Função que coloca um barco em uma posição válida
void colocarBarco(char tabuleiro[10][10], int player, int tamanhoBarco){
    int valid;
    char celula[4]; // Celula que o usuário irá digitar
    int posicaoInicialLinha, posicaoInicialColuna; // posição inicial que controla o espaço em que o barco estará, a posição final está na função colocarPosicaoFinal

    do{
        system("clear");
        valid = true;
        listarTabuleiroPlayer(tabuleiro, player);
        printf("Digite a celula para inserir um barco\n");
        fgets(celula, 4, stdin);
        limparString(celula);
        if(strlen(celula) != 2){
            valid = false;
        }
        else{
            if(celula[0] < 65 || celula[0] > 74 || celula[1] < 48 || celula[1] > 57){
                valid = false;
            }
            else{
                posicaoInicialLinha = celula[0] - 48 - 17; // Convertendo a entrada em ASCII para uma posição real nas matrizes 
                posicaoInicialColuna = celula[1] - 48;
                if(tabuleiro[posicaoInicialLinha][posicaoInicialColuna] == ' '){
                    colocarPosicaoFinal(tabuleiro, posicaoInicialLinha, posicaoInicialColuna, tamanhoBarco); // Indicando a posição final do barco
                }
                else{
                    valid = false;
                }
            }
        }

        if(valid == false){
            printf("\n(CELULA INVALIDA)");
            getchar();
        }
    }while(valid == false);
}

void colocarPosicaoFinal(char tabuleiro[10][10], int posicaoInicialLinha, int posicaoInicialColuna, int tamanhoBarco){
    int valid, op; // op = opcao escolhida pelo usuario
    char inicialLinha = posicaoInicialLinha + 48 + 17; // Transformando a posição inicial de volta a como era na entrada
    char inicialColuna = posicaoInicialColuna + 48;
    int posicaoFinalLinha, posicaoFinalColuna; // Posição que indica a direção do barco

    tamanhoBarco--; // Ajustado para manipulação de coordenadas

    do{
        valid = true;
        printf("O barco vai ficar de %c%c para qual direcao?\n", inicialLinha, inicialColuna);
        printf("1. Para cima\n2. Para baixo\n3. Para esquerda\n4. Para direita\n");
        scanf("%d", &op);
        getchar();

        switch(op){
            case 1: posicaoFinalLinha = posicaoInicialLinha-tamanhoBarco;
                if(posicaoFinalLinha < 0 || tabuleiro[posicaoFinalLinha][posicaoInicialColuna] != ' '){
                    valid = false;
                }
                else{
                    for(; posicaoInicialLinha >= posicaoFinalLinha; posicaoInicialLinha--){
                        tabuleiro[posicaoInicialLinha][posicaoInicialColuna] = 'N';
                    }
                } break;
                
            case 2: posicaoFinalLinha = posicaoInicialLinha+tamanhoBarco;
                if(posicaoFinalLinha > 9 || tabuleiro[posicaoFinalLinha][posicaoInicialColuna] != ' '){
                    valid = false;
                }
                else{
                    for(; posicaoInicialLinha <= posicaoFinalLinha; posicaoInicialLinha++){
                        tabuleiro[posicaoInicialLinha][posicaoInicialColuna] = 'N';
                    }
                } break;

            case 3: posicaoFinalColuna = posicaoInicialColuna-tamanhoBarco;
                if(posicaoFinalColuna < 0 || tabuleiro[posicaoInicialLinha][posicaoFinalColuna] != ' '){
                    valid = false;
                }
                else{
                    for(; posicaoInicialColuna >= posicaoFinalColuna; posicaoInicialColuna--){
                        tabuleiro[posicaoInicialLinha][posicaoInicialColuna] = 'N';
                    }
                } break;

            case 4: posicaoFinalColuna = posicaoInicialColuna+tamanhoBarco;
                if(posicaoFinalColuna > 9 || tabuleiro[posicaoInicialLinha][posicaoFinalColuna] != ' '){
                    valid = false;
                }
                else{
                    for(; posicaoInicialColuna <= posicaoFinalColuna; posicaoInicialColuna++){
                        tabuleiro[posicaoInicialLinha][posicaoInicialColuna] = 'N';
                    }
                } break;
            default: valid = false; break;
        }

        if(valid == false){
            printf("\n(OPCAO INVALIDA)"); 
            getchar();
        }
    }while(valid == false);
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

//****************** Usada para retirar o '\n' após inserir uma string[] via fgets()
void limparString(char string[]){
  for(int i=0;string[i]!='\0';i++)
      if(string[i]=='\n')
        string[i] = '\0';
}