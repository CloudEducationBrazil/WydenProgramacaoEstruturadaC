#include <stdio.h>
#include <stdlib.h>

// Assinatura da fun��o (DECLARA��O)
int fSoma(int num1, int num2);

int main(void) {
   // vari�veis locais
   int valor1, valor2, resultado;

   printf("Informe o n�mero 1? "); scanf("%d", &valor1);
   printf("Informe o n�mero 2? "); scanf("%d", &valor2);
   // Invocando a Fun��o (CHAMADA)
   resultado = fSoma(valor1, valor2);

   printf("Total da Soma = %d", resultado);
}

int fSoma(int num1, int num2){
  // vari�veis locais
  int soma;
  soma = num1 + num2;

  return soma;
}
