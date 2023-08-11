#include <stdio.h>
#include <stdlib.h>

#define tamVetorAux 3

int  somarVetor (int a[], int tamVetor);
void lerVetor   (int a[], int tamVetor);

int main(void) {
  int a[tamVetorAux];
  int resultado;

  lerVetor(a, tamVetorAux);
  resultado = somarVetor(a, tamVetorAux);

  printf("Resultado = %d", resultado);
}

void lerVetor(int a[], int tamVetor){
  int x;
  for ( x = 0; x < tamVetor; x++){
    printf("Elemento [%d]", x);
    scanf("%d", &a[x]);
  }
}

int somarVetor(int a[], int tamVetor){
  int x, soma = 0;
  for ( x = 0; x < tamVetor; x++)
    soma += a[x];

  return soma;
}
