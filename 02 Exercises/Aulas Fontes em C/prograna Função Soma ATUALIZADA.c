#include <stdio.h>
#include <stdlib.h>

// Assinatura da função (DECLARAÇÃO)
int fSoma(int num1, int num2);

int main(void) {
   // variáveis locais
   int valor1, valor2, resultado;

   printf("Informe o número 1? "); scanf("%d", &valor1);
   printf("Informe o número 2? "); scanf("%d", &valor2);
   // Invocando a Função (CHAMADA)
   resultado = fSoma(valor1, valor2);

   printf("Total da Soma = %d", resultado);
}

int fSoma(int num1, int num2){
  // variáveis locais
  int soma;
  soma = num1 + num2;

  return soma;
}
