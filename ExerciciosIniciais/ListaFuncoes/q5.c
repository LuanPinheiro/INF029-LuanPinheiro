#include <stdio.h>

typedef struct{
  int num1;
  int num2;
  int num3;
  int num4;
}numeros;

numeros ler4numeros();

int main() {

  numeros nums;
  
  nums = ler4numeros();

  printf("\n%d\n", nums.num1);
  printf("%d\n", nums.num2);
  printf("%d\n", nums.num3);
  printf("%d\n", nums.num4);
  
  return 0;
}

numeros ler4numeros(){

  numeros func;
  
  scanf("%d", &func.num1);
  scanf("%d", &func.num2);
  scanf("%d", &func.num3);
  scanf("%d", &func.num4);

  return func;
}