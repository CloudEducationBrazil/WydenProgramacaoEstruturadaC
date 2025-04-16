#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(){
  FILE* ArqLista;
  ArqLista = (FILE*) malloc(sizeof(FILE));
  //ArqLista = fopen("/home/unifacsmestrado/Documents/EstudoC/ArqListaEstatica.txt", "r");
  ArqLista = fopen("D:/EstudoC++/ArqListaEstatica.txt", "r");

  char  linha[200];
  char* result;

  if ( ArqLista == NULL ) { printf("Erro ao abrir o arquivo"); };

  while ( !feof(ArqLista) ) {
     result = fgets(linha, 100, ArqLista);

     if ( result )
       printf("Linha %s \n", linha);
  }

  fclose(ArqLista);

  return 0;
}
