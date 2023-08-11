#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(){
  FILE *ArqLista;
  ArqLista = fopen("ArqListaEstatica2.txt", "w");
  
  if ( ArqLista == NULL ) { printf("Erro ao abrir o arquivo"); return 0; };
 
  fputs("teste 1 \n", ArqLista);
  fputs("teste 2 \n", ArqLista);
  fputs("teste 3 \n", ArqLista);
 
  fclose(ArqLista);

  printf("Arquivo gerado com sucesso...");
  return 0;
}
