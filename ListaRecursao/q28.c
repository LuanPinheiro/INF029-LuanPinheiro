/*Função que retorna o resultado de uma multiplicação à russa
a) Ter 2 números A e B, que ficaram no topo da tabela
b) Dividir A por 2 sucessivas vezes ignorando o resto até chegar em 1, imprimindo esses resultados na coluna A
c) Multiplicar B por 2 na mesma quantidade de vezes que A foi dividido por 2, imprimindo os resultados na coluna B
d) Somar todos os números das colunas B que estejam juntos a números impares da coluna A*/
#include <stdio.h>

int multiplicacaoRussa(int A, int B);

int main(){
    int A = 27, B = 82;
    printf("A B Parcelas\n");
    printf("Resultado: %d", multiplicacaoRussa(A, B));
    return 0;
}

int multiplicacaoRussa(int A, int B){
    if(A >= 1){
        if(A%2){
            printf("%d %d %d\n", A, B, B);
            return B + multiplicacaoRussa(A/2, B*2);
        }
        printf("%d %d --\n", A, B);
        return multiplicacaoRussa(A/2, B*2);
    }
    return 0;
}