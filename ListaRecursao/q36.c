// Função que retorna se uma palavra é palíndromo
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int palindromo(char *string, int comeco, int fim);
void removeSpaces(char* s);

int main(){
    char string[] = "a bola, da loba.";
    removeSpaces(string);
    int tamanho = strlen(string) - 1;

    printf("%d", palindromo(string, 0, tamanho));
    return 0;
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

void removeSpaces(char* string){
    char* d = string;
    do{
        while((*d < 65 || *d > 90) && (*d < 97 || *d > 122) && *d != 0){
            ++d;
        }
    }while(*string++ = *d++);
}