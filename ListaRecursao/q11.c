// Função que retorna a multiplicação de dois números através de sucessivas somas
#include <stdio.h>

int Multip_Rec(int n1, int n2);

int main(){
    int n1 = 2, n2 = 6;
    printf("%d", Multip_Rec(n1, n2));
    return 0;
}

int Multip_Rec(int n1, int n2){
    if(n2 == 0 || n1 == 0){
        return 0;
    }
    if(n2 == 1){
        return n1;
    }
    return n1 + Multip_Rec(n1, --n2);
}