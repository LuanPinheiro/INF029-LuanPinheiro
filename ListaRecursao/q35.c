// Função que dado um número o converte em binário
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* inteiroBinario(int n, char string[]);

int main(){
    int n = 45;
    char string[] = "";
    inteiroBinario(n, string);
    printf("%s", string);
    return 0;
}

char* inteiroBinario(int n, char string[]){
    if(n > 0){
        if(n%2){
            strcat(string, "1");
        }
        else{
            strcat(string, "0");
        }
        return inteiroBinario(n/2, string);
    }
    return NULL;
}