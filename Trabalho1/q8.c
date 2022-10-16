#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define naviosDeGuerra 5
#define indiceBarcos barcosPlayer[0].count

typedef struct{
    int direcao; // Direcao para calcular
    int posicaoLinha[4]; // Todas as posições, em linhas, que o barco ocupa
    int posicaoColuna[4]; // Todas as posições, em colunas, que o barco ocupa
    int tamanho; // quantidade de espacos que ele ocupa, para futuros prints
    int count; // Countador de qual barco está
}barcos;

void listarTabuleiro(char tabuleiro[10][10]);
void inserirBarcos(char tabuleiro[10][10], int qtdBarcos, int player, barcos barcosPlayer[]);
int atacarAdversario(char tabuleiroAdversarioVisivel[10][10], char tabuleiroAdversarioReal[10][10], int player, int qtdBarcos, barcos barcosPlayer[]);
int ataque(char tabuleiroAdversarioReal[10][10], char tabuleiroAdversarioVisivel[10][10], int posicaoCelulaLinha, int posicaoCelulaColuna, int qtdBarcos, barcos barcosPlayer[]);
int exibirOpcoesTamanhos(int tamanho1, int tamanho3, int tamanho4);
void colocarBarco(char tabuleiro[10][10], int player, int tamanhoBarco, barcos barcosPlayer[]);
void colocarPosicaoFinal(char tabuleiro[10][10], int posicaoInicialLinha, int posicaoInicialColuna, int tamanhoBarco, barcos barcosPlayer[]);
int linhaValida(char tabuleiro[10][10], int posicaoInicialLinha, int posicaoInicialColuna, int posicaoFinalColuna, int direcao);
int colunaValida(char tabuleiro[10][10], int posicaoInicialLinha, int posicaoInicialColuna, int posicaoFinalLinha, int direcao);
int trocarPlayer(int player);
void limparString(char string[]);

int main(){
    char tabuleiroP1[10][10], tabuleiroP1Adversario[10][10], tabuleiroP2[10][10], tabuleiroP2Adversario[10][10];
    int player = 1, valid, op;
    int qtdBarcosP1 = naviosDeGuerra, qtdBarcosP2 = naviosDeGuerra; // Controla a quantidade de barcos restantes de cada jogador 
    barcos barcosP1[naviosDeGuerra], barcosP2[naviosDeGuerra]; // Guarda a posição de cada barco
    int win = false;

    for(int i = 0; i < 10; i++){ // Preenchendo os tabuleiros com espaços vazios
        for(int j = 0; j < 10; j++){
            tabuleiroP1[i][j] = ' ';
            tabuleiroP1Adversario[i][j] = ' ';
            tabuleiroP2[i][j] = ' ';
            tabuleiroP2Adversario[i][j] = ' ';
        }
    }
    // Iniciando o indice, ele vai ficar no primeiro barco, para preencher o vetor de barcos a partir dele como referencia ex: barcoP1[count].tamanho
    barcosP1[0].count = 0;
    barcosP2[0].count = 0;

    // Primeira jogada, colocando os navios
    inserirBarcos(tabuleiroP1, qtdBarcosP1, 1, barcosP1);
    /*for(int i = 0; i < naviosDeGuerra; i++){
        printf("Navio %d:\n", i+1);
        for(int j = 0; j < barcosP1[i].tamanho; j++){
            printf("Posicao %d: [%d][%d]\n", j+1, barcosP1[i].posicaoLinha[j], barcosP1[i].posicaoColuna[j]);
        }
        printf("\n");
    }*/
    inserirBarcos(tabuleiroP2, qtdBarcosP2, 2, barcosP2);
    do{
        do{
            valid = true;
            system("clear");
            printf("JOGADOR: %d\n", player);
            printf("Menu de Acoes:\n");
            printf("1. Ver seu tabuleiro\n2. Atacar Adversario\n");
            scanf("%d", &op);
            getchar();

            switch(op){
                case 1: switch(player){
                    case 1: listarTabuleiro(tabuleiroP1); getchar(); break;
                    case 2: listarTabuleiro(tabuleiroP2); getchar(); break;
                } break;

                case 2: switch(player){
                    case 1: qtdBarcosP2 = atacarAdversario(tabuleiroP1Adversario, tabuleiroP2, player, qtdBarcosP2, barcosP2); player = trocarPlayer(player); break;
                    case 2: qtdBarcosP1 = atacarAdversario(tabuleiroP2Adversario, tabuleiroP1, player, qtdBarcosP1, barcosP1); player = trocarPlayer(player); break;
                } break;

                default: valid = false;
                    printf("\n(ENTRADA INVALIDA)\n");
                    getchar();
            }
            // Condições de fim de jogo
            if(qtdBarcosP1 == 0){
                printf("\nJogador 2 Venceu!");
                return 0;
            }
            else if(qtdBarcosP2 == 0){
                printf("\nJogador 1 Venceu!");
                return 0;
            }
        }while(valid == false);
    }while(qtdBarcosP1!=0 || qtdBarcosP2!=0);
}

void listarTabuleiro(char tabuleiro[10][10]){
    printf("   0   1   2   3   4   5   6   7   8   9\n");
    for(int i = 0; i < 10; i++){
        printf("%c ", 65+i);
        for(int j = 0; j < 10; j++){
            printf("[%c] ",tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Irá pedir ao usuário uma célula para inserir um barco, irá repetir a ação até que todos os barcos sejam colocados em posições válidas
void inserirBarcos(char tabuleiro[10][10], int qtdBarcos, int player, barcos barcosPlayer[]){
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

        colocarBarco(tabuleiro, player, tamanhoBarco, barcosPlayer);
        qtdBarcos--;
    }while(qtdBarcos > 0);
}

int atacarAdversario(char tabuleiroAdversarioVisivel[10][10], char tabuleiroAdversarioReal[10][10], int player, int qtdBarcos, barcos barcosPlayer[]){
    char celula[4];
    int valid;
    int posicaoCelulaLinha;
    int posicaoCelulaColuna;

    do{
        valid = true;
        listarTabuleiro(tabuleiroAdversarioVisivel);
        printf("Ataque uma celula adversaria: ");
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
                posicaoCelulaLinha = celula[0] - 48 - 17; // Convertendo a entrada em ASCII para uma posição real nas matrizes 
                posicaoCelulaColuna = celula[1] - 48;

                if(tabuleiroAdversarioVisivel[posicaoCelulaLinha][posicaoCelulaColuna] == ' '){
                    return ataque(tabuleiroAdversarioReal, tabuleiroAdversarioVisivel, posicaoCelulaLinha, posicaoCelulaColuna, qtdBarcos, barcosPlayer); // função que recebe qtdBarcos, e a coordenada, se destruir um barco por completo diminui qtdBarcos
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

int ataque(char tabuleiroAdversarioReal[10][10], char tabuleiroAdversarioVisivel[10][10], int posicaoCelulaLinha, int posicaoCelulaColuna, int qtdBarcos, barcos barcosPlayer[]){
    //printf("Antes de mudar: %c [%d][%d]\n", tabuleiroAdversarioReal[posicaoCelulaLinha][posicaoCelulaLinha], posicaoCelulaLinha, posicaoCelulaColuna);
    if(tabuleiroAdversarioReal[posicaoCelulaLinha][posicaoCelulaColuna] == 'N'){
        tabuleiroAdversarioReal[posicaoCelulaLinha][posicaoCelulaColuna] = 'O';
        tabuleiroAdversarioVisivel[posicaoCelulaLinha][posicaoCelulaColuna] = 'O';

        for(int i = 0; i < naviosDeGuerra; i++){
            for(int j = 0; j < barcosPlayer[i].tamanho; j++){
                if(barcosPlayer[i].posicaoLinha[j] == posicaoCelulaLinha && barcosPlayer[i].posicaoColuna[j] == posicaoCelulaColuna){
                    if(barcosPlayer[i].tamanho == 1){
                        return --qtdBarcos;
                    }
                    else{
                        for(int k = 0; k < barcosPlayer[i].tamanho-1; k++){
                            if(tabuleiroAdversarioReal[barcosPlayer[i].posicaoLinha[k]][barcosPlayer[i].posicaoColuna[k]] != tabuleiroAdversarioReal[barcosPlayer[i].posicaoLinha[k+1]][barcosPlayer[i].posicaoColuna[k+1]]){
                                return qtdBarcos;
                            }
                        }
                    }
                    return --qtdBarcos;
                }
            }
        }
    }
    else if (tabuleiroAdversarioReal[posicaoCelulaLinha][posicaoCelulaColuna] == ' '){
        tabuleiroAdversarioReal[posicaoCelulaLinha][posicaoCelulaColuna] = 'X';
        tabuleiroAdversarioVisivel[posicaoCelulaLinha][posicaoCelulaColuna] = 'X';
    }
    return qtdBarcos;
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
void colocarBarco(char tabuleiro[10][10], int player, int tamanhoBarco, barcos barcosPlayer[]){
    int valid;
    char celula[4]; // Celula que o usuário irá digitar
    int posicaoInicialLinha, posicaoInicialColuna; // posição inicial que controla o espaço em que o barco estará, a posição final está na função colocarPosicaoFinal

    do{
        system("clear");
        valid = true;
        listarTabuleiro(tabuleiro);
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
                    if(tamanhoBarco == 1){ // Caso o tamanho do barco seja 1, não é necessario escolher direção
                        tabuleiro[posicaoInicialLinha][posicaoInicialColuna] = 'N';
                        barcosPlayer[indiceBarcos].posicaoLinha[0] = posicaoInicialLinha;
                        barcosPlayer[indiceBarcos].posicaoColuna[0] = posicaoInicialColuna;
                        barcosPlayer[indiceBarcos].tamanho = 1;
                        indiceBarcos++;
                    }
                    else{
                        colocarPosicaoFinal(tabuleiro, posicaoInicialLinha, posicaoInicialColuna, tamanhoBarco, barcosPlayer); // Indicando a posição final do barco
                    }
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

// Coloca os barcos nas posicoes validas, indicadas pelo usuario
void colocarPosicaoFinal(char tabuleiro[10][10], int posicaoInicialLinha, int posicaoInicialColuna, int tamanhoBarco, barcos barcosPlayer[]){
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
                if(posicaoFinalLinha < 0 || colunaValida(tabuleiro, posicaoInicialLinha, posicaoInicialColuna, posicaoFinalLinha, 1) == false){
                    valid = false;
                }
                else{
                    for(int count = 0; posicaoInicialLinha >= posicaoFinalLinha; posicaoInicialLinha--, count++){ // contador iniciado para preencher o vetor de barcos
                        tabuleiro[posicaoInicialLinha][posicaoInicialColuna] = 'N';
                        barcosPlayer[indiceBarcos].posicaoLinha[count] = posicaoInicialLinha;
                        barcosPlayer[indiceBarcos].posicaoColuna[count] = posicaoInicialColuna;
                    }
                } break;
                
            case 2: posicaoFinalLinha = posicaoInicialLinha+tamanhoBarco;
                if(posicaoFinalLinha > 9 || colunaValida(tabuleiro, posicaoInicialLinha, posicaoInicialColuna, posicaoFinalLinha, 2) == false){
                    valid = false;
                }
                else{
                    for(int count = 0; posicaoInicialLinha <= posicaoFinalLinha; posicaoInicialLinha++, count++){
                        tabuleiro[posicaoInicialLinha][posicaoInicialColuna] = 'N';
                        barcosPlayer[indiceBarcos].posicaoLinha[count] = posicaoInicialLinha;
                        barcosPlayer[indiceBarcos].posicaoColuna[count] = posicaoInicialColuna;
                    }
                } break;

            case 3: posicaoFinalColuna = posicaoInicialColuna-tamanhoBarco;
                if(posicaoFinalColuna < 0 || linhaValida(tabuleiro, posicaoInicialLinha, posicaoInicialColuna, posicaoFinalColuna, 2) == false){
                    valid = false;
                }
                else{
                    for(int count = 0; posicaoInicialColuna >= posicaoFinalColuna; posicaoInicialColuna--, count++){
                        tabuleiro[posicaoInicialLinha][posicaoInicialColuna] = 'N';
                        barcosPlayer[indiceBarcos].posicaoLinha[count] = posicaoInicialLinha;
                        barcosPlayer[indiceBarcos].posicaoColuna[count] = posicaoInicialColuna;
                    }
                } break;

            case 4: posicaoFinalColuna = posicaoInicialColuna+tamanhoBarco;
                if(posicaoFinalColuna > 9 || linhaValida(tabuleiro, posicaoInicialLinha, posicaoInicialColuna, posicaoFinalColuna, 1) == false){
                    valid = false;
                }
                else{
                    for(int count = 0; posicaoInicialColuna <= posicaoFinalColuna; posicaoInicialColuna++, count++){
                        tabuleiro[posicaoInicialLinha][posicaoInicialColuna] = 'N';
                        barcosPlayer[indiceBarcos].posicaoLinha[count] = posicaoInicialLinha;
                        barcosPlayer[indiceBarcos].posicaoColuna[count] = posicaoInicialColuna;
                    }
                } break;
            default: valid = false; break;
        }

        if(valid == false){
            printf("\n(OPCAO INVALIDA)"); 
            getchar();
        }
    }while(valid == false);

    barcosPlayer[indiceBarcos].tamanho = tamanhoBarco + 1;
    indiceBarcos++;
}

// Indica se há espaço livre o suficiente para colocar um barco
int linhaValida(char tabuleiro[10][10], int posicaoInicialLinha, int posicaoInicialColuna, int posicaoFinalColuna, int direcao){

    // direcao = 1 (DIREITA), direcao = 2 (ESQUERDA)
    if(direcao == 1){
        for(; posicaoInicialColuna <= posicaoFinalColuna; posicaoInicialColuna++){
            if(tabuleiro[posicaoInicialLinha][posicaoInicialColuna] != ' '){
                return false;
            }
        }
    }
    else{
        for(; posicaoInicialColuna >= posicaoFinalColuna; posicaoInicialColuna--){
            if(tabuleiro[posicaoInicialLinha][posicaoInicialColuna] != ' '){
                return false;
            }
        }
    }
    return true;
}

// Indica se há espaço livre o suficiente para colocar um barco
int colunaValida(char tabuleiro[10][10], int posicaoInicialLinha, int posicaoInicialColuna, int posicaoFinalLinha, int direcao){

    // direcao = 1 (CIMA), direcao = 2 (BAIXO)
    if(direcao == 1){
        for(; posicaoInicialLinha >= posicaoFinalLinha; posicaoInicialLinha--){
            if(tabuleiro[posicaoInicialLinha][posicaoInicialColuna] != ' '){
                return false;
            }
        }
    }
    else{
        for(; posicaoInicialLinha <= posicaoFinalLinha; posicaoInicialLinha++){
            if(tabuleiro[posicaoInicialLinha][posicaoInicialColuna] != ' '){
                return false;
            }
        }
    }
    return true;
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