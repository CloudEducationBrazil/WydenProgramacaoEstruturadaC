#include <stdio.h>

int maximo(int numero, int vetor[]);

int main(void)
{   int vetor[5];
    for (int x = 0; x < 5; x++)
      scanf("%d", &vetor[x]);
      
    int max;
    max = maximo(5, vetor);
     printf("Maximo = %d", max);
}

int maximo(int numero, int vetor[]){
    if (numero == 1) return vetor[0];
    else {
        int x;
        x = maximo(numero -1, vetor);
        if ( x > vetor[numero-1] ) return x;
        else return vetor[numero-1];
    }
}