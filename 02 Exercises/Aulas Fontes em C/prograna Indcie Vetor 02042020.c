#include <stdio.h>
#include <stdlib.h>

int main(){
  int v[5], x, maior =0, indice;

  for (x = 0; x < 5; x++){
   printf("Informe o elemento do vetor[%d]? ", x); scanf("%d", &v[x]);
  }

  for (x = 0; x < 5; x++)
   if ( v[x] > maior ){
     maior = v[x];
     indice = x;
   }

   printf("Indice = %d, e Maior = %d", indice, maior);
}