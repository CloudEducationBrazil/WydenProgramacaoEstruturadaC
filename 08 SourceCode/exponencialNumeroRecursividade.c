#include <stdio.h>
int exponencial(int num, int exp_);

int main()
{   int num, exp_, resultado;
    printf("Digite o número?"); scanf("%d", &num);
    printf("Digite o exponencial?"); scanf("%d", &exp_);
    
    resultado = exponencial(num, exp_);
    printf("Resultado: %d = %d", num, resultado);

    return 0;
}

int exponencial(int num, int exp_){
    if ( exp_ == 0) return 1;
    if ( exp_ == 1) return num;
    
    return num * exponencial(num, exp_ -1);
}
