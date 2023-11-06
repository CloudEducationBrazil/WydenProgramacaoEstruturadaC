#include <stdio.h>

float raiz_quadrada(float numero);

int main()
{  
    float numero;
    
    printf("Entre com um número positivo por favor : ");
    scanf("%f",&numero);
    
    printf("A raiz quadrada de %.3f é %.5f \n",numero,raiz_quadrada(numero));

    return(0);
}


float raiz_quadrada (float numero)
{
    int n;
    float recorre = numero;
    
    for (n = 0; n < 10; ++n)
          recorre = recorre/2 + numero/(2*recorre);
            
    return(recorre);    
}  