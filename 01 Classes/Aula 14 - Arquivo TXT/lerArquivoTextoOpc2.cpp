#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(){
  char linha[200];
  float num;
  char* result;
 
  //FILE *ArqLista = fopen("ArqListaEstatica.txt", "r");
  FILE *ArqLista = (FILE*) malloc(sizeof(FILE));
  ArqLista = fopen("ArqListaEstatica.txt", "r");
  
  if ( ArqLista == NULL ) { printf("Erro ao abrir o arquivo"); return 0; };
 
  while ((fscanf(ArqLista, "%s", linha) != EOF) )  {
     fscanf(ArqLista, "%200[^\n]", linha);
     
     printf("%s \n", linha);
 }
 fclose(ArqLista);

  return 0;
}
