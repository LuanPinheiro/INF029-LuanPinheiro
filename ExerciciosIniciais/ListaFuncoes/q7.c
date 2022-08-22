#include <stdio.h>

void ler3palavras(char p1[16], char p2[16], char p3[16]);

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
  
  scanf("%s", p1);
  scanf("%s", p2);
  scanf("%s", p3);
}