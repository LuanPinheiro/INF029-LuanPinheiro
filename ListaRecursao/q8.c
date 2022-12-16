// Função que encontra o MDC de dois números x e y
#include <stdio.h>

int main(){
    int x = 12, y = 18;
    printf("%d", mdc(x, y));
    return 0;
}

int mdc(int x, int y){
    if(y == 0){
        return x;
    }
    return mdc(y, x%y);
}