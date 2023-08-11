#include <stdio.h>
#include <bibliotecaPessoal.c>

int main(void) {
  int num1, num2, soma;
  printf("Informe o valor do 1. numero:? "); scanf("%d", &num1);
  printf("Informe o valor do 2. numero:? "); scanf("%d", &num2);

  // Função Soma
  soma = fSoma(num1, num2);

  printf("\n");
  printf("Resultado: %d", soma);
  printf("\n");

}
