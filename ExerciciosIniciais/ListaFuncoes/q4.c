#include <stdio.h>

void ler3numeros(int vetor[3]);

int main(){

  int v[3];

  ler3numeros(v);

  printf("%d\n", v[0]);
  printf("%d\n", v[1]);
  printf("%d\n", v[2]);
  
  return 0;
}

void ler3numeros(int vetor[3]){
  scanf("%d", &vetor[0]);
  scanf("%d", &vetor[1]);
  scanf("%d", &vetor[2]);
}