#include <stdio.h>
#include <stdlib.h>

int main(void){
  FILE *ArqListaEstatica;

  ArqListaEstatica = fopen("ArqListaEstatica2.txt", "wt");

  fprintf(ArqListaEstatica, "%s\t%d\t%f\t%s\n", "Teste", 2, 76.78, "Teste");
  //fprintf(ArqListaEstatica, "%d\n", 2);
  //fprintf(ArqListaEstatica, "%f\n", 76.78);
  //fprintf(ArqListaEstatica, "%s\n", "Teste");

  fclose(ArqListaEstatica);
}
