// Função que calcula a soma dos primeiros n números ao cubo
#include <stdio.h>

int somaCubo(int n);

int main(){
	int n = 4;
	printf("%d", somaCubo(n));
	return 0;
}

int somaCubo(int n){
	if(n == 0){
		return n;
	}
	if(n > 0){
		return (n*n*n) + somaCubo(n-1);
	}
}