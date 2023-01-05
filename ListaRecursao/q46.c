// Função que calcula a média de um vetor de tamanho n
#include <stdio.h>

float media(int vetor[], int n);

int main(){
	int n = 5;
	int vetor[n];
	for(int i = 0; i < n; i++){
		vetor[i] = i+1;
	}
	printf("%.0f\n", media(vetor, n-1)/n);
	return 0;
}

float media(int vetor[], int tam){
	float mediaNum;
	if(tam == 0){
		return vetor[tam];
	}
	if(tam > 1){
		mediaNum = vetor[tam] + media(vetor, tam-1);
	}
	return mediaNum;
}