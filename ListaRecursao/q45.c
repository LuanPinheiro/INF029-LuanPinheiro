// Função que calcula a soma dos dígitos de um número
#include <stdio.h>

int somaDigitos(int n);

int main(){
	int n = 1531;
	printf("%d", somaDigitos(n));
	return 0;
}

int somaDigitos(int n){
	if(n > 0){
		return n%10 + somaDigitos(n/10);
	}
	return 0;
}