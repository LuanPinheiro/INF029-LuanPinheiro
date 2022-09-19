#include <stdio.h>

typedef struct{
  char palavra1[16];
  char palavra2[16];
  char palavra3[16];
}words;

words ler3palavras(words palavras);
void LimparString(char string[]);

int main() {

  words palavras;

  palavras = ler3palavras(palavras);

  printf("\n%s\n", palavras.palavra1);
  printf("%s\n", palavras.palavra2);
  printf("%s\n", palavras.palavra3);
  
  return 0;
}

words ler3palavras(words palavras){

  printf("Palavra 1: ");
  fgets(palavras.palavra1, 16, stdin);
  LimparString(palavras.palavra1);

  printf("Palavra 2: ");
  fgets(palavras.palavra2, 16, stdin);
  LimparString(palavras.palavra2);
  
  printf("Palavra 3: ");
  fgets(palavras.palavra3, 16, stdin);
  LimparString(palavras.palavra1);

  return palavras;
}

void LimparString(char string[]){
  for(int i=0;string[i] != '\0';i++)
      if(string[i] == '\n')
        string[i] = '\0';
} 