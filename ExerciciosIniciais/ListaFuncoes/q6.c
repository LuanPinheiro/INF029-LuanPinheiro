#include <stdio.h>

typedef struct{
  char l1;
  char l2;
  char l3;
}struct_letras;

struct_letras ler3letras(struct_letras l);

int main() {

  struct_letras letras;

  letras = ler3letras(letras);

  printf("%c ", letras.l1);
  printf("%c ", letras.l2);
  printf("%c ", letras.l3);
  
  return 0;
}

struct_letras ler3letras(struct_letras l){

  printf("Letra 1: ");
  l.l1 = getchar();
  getchar();
  
  printf("Letra 2: ");
  l.l2 = getchar();
  getchar();
  
  printf("Letra 3: ");
  l.l3 = getchar();
  getchar();

  return l;
}