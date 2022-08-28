#include <stdio.h>

void ler3palavras(char p1[16], char p2[16], char p3[16]);
void LimparString(char string[]);

int main() {

  char palavra1[16];
  char palavra2[16];
  char palavra3[16];

  ler3palavras(palavra1, palavra2, palavra3);

  printf("\n%s\n", palavra1);
  printf("%s\n", palavra2);
  printf("%s\n", palavra3);
  
  return 0;
}

void ler3palavras(char p1[16], char p2[16], char p3[16]){

  printf("Palavra 1: ");
  fgets(p1, 16, stdin);
  LimparString(p1);

  printf("Palavra 2: ");
  fgets(p2, 16, stdin);
  LimparString(p2);
  
  printf("Palavra 3: ");
  fgets(p3, 16, stdin);
  LimparString(p3);
}

void LimparString(char string[]){
  for(int i=0;string[i] != '\0';i++)
      if(string[i] == '\n')
        string[i] = '\0';
} 