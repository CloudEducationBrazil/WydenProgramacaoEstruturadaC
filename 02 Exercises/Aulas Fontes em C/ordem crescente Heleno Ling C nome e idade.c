#include <stdio.h>
#include <stdlib.h>
#define tamVetor 6

// Definição da Estrutura de Dados
typedef struct {
  char nome[50];
  int idade
} dados[tamVetor];

int main(void){
  dados pessoa;
  int x, y, auxIdade;
  char auxNome[50];

  // Entrada de Dados
  for (x = 0; x < tamVetor; x++){
    printf("\n Informe Nome: "); fgets(pessoa[x].nome, 50, stdin);
    printf("Informe Idade: "); scanf("%d", &pessoa[x].idade);
    fflush(stdin);
  }

  // 21; 12; 15
  for (x = 0; x < tamVetor; x++){
    for (y = x + 1; y < tamVetor; y++)
        // Ordem Crescente
        if ( pessoa[x].idade > pessoa[y].idade )
        {  auxIdade = pessoa[y].idade;
           pessoa[y].idade = pessoa[x].idade;
           pessoa[x].idade = auxIdade;

           strcpy(auxNome, pessoa[y].nome);
           strcpy(pessoa[y].nome, pessoa[x].nome);
           strcpy(pessoa[x].nome, auxNome);
        }
  }

  // Saída de Dados - Impressão da Estrutura de Dados
  printf("\n Listagem Ordenada ");
  for (x = 0; x < tamVetor; x++)
    printf("Nome Idade: %s %d \n", pessoa[x].nome, pessoa[x].idade);
}
