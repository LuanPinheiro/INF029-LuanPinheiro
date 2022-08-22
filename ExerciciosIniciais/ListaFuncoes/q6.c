#include <stdio.h>

void ler3letras(char l[3]);

int main() {

  char letras[3];

  ler3letras(letras);

  printf("%c", letras[0]);
  printf("%c", letras[1]);
  printf("%c", letras[2]);
  
  return 0;
}

void ler3letras(char l[3]){
  
  scanf("%s", &l[0]);
  scanf("%s", &l[1]);
  scanf("%s", &l[2]);
}