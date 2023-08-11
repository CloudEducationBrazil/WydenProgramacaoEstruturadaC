#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
  int tamVetor, somaVetA = 0, somaVetB = 0, somaVetC = 0;
  float normaVetA, normaVetB, normaVetC;
  int vetA[tamVetor], vetB[tamVetor], vetC[tamVetor];
  printf("Digite Tamanho do Vetor? "); scanf("%d", &tamVetor);

  for (int x = 0; x < tamVetor; x++){
    printf("Digite Elemento A [%d] do Vetor? ", x); scanf("%d", &vetA[x]);
    printf("Digite Elemento B [%d] do Vetor? ", x); scanf("%d", &vetB[x]);
    printf("Digite Elemento C [%d] do Vetor? ", x); scanf("%d", &vetC[x]);
  }

  for (int x = 0; x < tamVetor; x++){
    somaVetA += vetA[x];
    somaVetB += vetB[x];
    somaVetC += vetC[x];
  }

    normaVetA = sqrt(somaVetA);
    normaVetB = sqrt(somaVetB);
    normaVetC = sqrt(somaVetC);

    printf("\nNorma do Tamanho A = %f", normaVetA);
    printf("\nNorma do Tamanho B = %f", normaVetB);
    printf("\nNorma do Tamanho C = %f", normaVetC);

    printf("\nSoma do Tamanho A = %d", somaVetA);
    printf("\nSoma do Tamanho B = %d", somaVetB);
    printf("\nSoma do Tamanho C = %d", somaVetC);

    if ( normaVetA > normaVetB && normaVetA > normaVetC)
      printf("\nMaior Norma A = %d", normaVetA);
    else
    if ( normaVetB > normaVetA && normaVetB > normaVetC)
      printf("\nMaior Norma B = %d", normaVetB);
    else
    if ( normaVetC > normaVetA && normaVetC > normaVetB)
      printf("\nMaior Norma C = %d", normaVetC);
    else
      printf("\nNormas Iguais A B C = %d", normaVetC);
}
