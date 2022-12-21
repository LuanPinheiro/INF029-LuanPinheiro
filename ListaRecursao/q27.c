/*Funções que:
a) imprimem o número em binário
b) multiplicação de dois números naturais apenas com soma
c) inversão de uma string
d) gerador de uma sequência F(1) = 1, F(2) = 2, F(N) = 2*F(N-1) + 3*F(N-2)
e) verificar se uma palavra é palíndromo
f) busca sequencial em um vetor ordenado, que retorna a primeira ocorrência
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define tam 7

int numBinario(int num, int multiplicador);
int Multip_Rec(int n1, int n2);
char* inverteString(char *string, int comeco, int fim);
int sequencia(int N);
int palindromo(char *string, int comeco, int fim);
int buscaSequencial(int valor, int vetor[], int index, int tamVetor);

int main(){
    int N = 5, X = 2, vetor[] = {1,2,3,4,5};
    char *string = malloc(sizeof(char)*tam), aux[tam];
    strcpy(string, "palavra");
    strcpy(aux, string);

    printf("Numero %d em Binario: %d\n", N, numBinario(N, 1));
    printf("Multiplicacao %dx%d: %d\n", N, X, Multip_Rec(N, X));
    printf("Inversao da String '%s': %s\n", aux, inverteString(string, 0, tam-1));
    printf("Resultado funcao: %d\n", sequencia(N));
    printf("Palavra %s eh palindomo?: %d\n", string, palindromo(string, 0, tam-1));
    printf("Busca sequencial de %d: %d\n", X, buscaSequencial(X, vetor, 0, 5));

    return 0;
}

int numBinario(int num, int multiplicador){
    int resto, retorno;
    if(num > 0){
        resto = num % 2;
        retorno = resto * multiplicador;
        multiplicador *= 10;
        num /= 2;
        return retorno + numBinario(num, multiplicador);
    }
    return num;
}

int Multip_Rec(int n1, int n2){
    if(n2 == 0 || n1 == 0){
        return 0;
    }
    if(n2 == 1){
        return n1;
    }
    return n1 + Multip_Rec(n1, --n2);
}

char* inverteString(char *string, int comeco, int fim){
    if(comeco > fim){
        printf("ENTRADA INVALIDA");
    }
    if(comeco < fim){
        char aux = string[comeco];
        string[comeco] = string[fim];
        string[fim] = aux;
        return inverteString(string, comeco+1, fim-1);
    }
    return string;
}

int sequencia(int N){
    if(N < 0){
        printf("ENTRADA INVALIDA");
        return -1;
    }
    if(N == 1 || N == 2){
        return N;
    }
    if(N > 0){
        return (2*sequencia(N-1)) + (3*sequencia(N-2));
    }
}

int palindromo(char *string, int comeco, int fim){
    if(comeco < fim){
        if(string[comeco] == string[fim]){
            return palindromo(string, comeco+1, fim-1);
        }
        else{
            return false;
        }
    }
    return true;
}

int buscaSequencial(int valor, int vetor[], int index, int tamVetor){
    if(index < 0 || tamVetor < 0){
        printf("ENTRADA INVALIDA");
        return -1;
    }
    if(index < tamVetor){
        if(vetor[index] == valor){
            return index;
        }
        return buscaSequencial(valor, vetor, ++index, tamVetor);
    }
    printf("NAO ENCONTRADO");
    return -1;
}