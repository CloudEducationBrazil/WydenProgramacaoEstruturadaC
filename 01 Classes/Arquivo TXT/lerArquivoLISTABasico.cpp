#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(void){
  // Declarar uma variável do tipo FILE (arquivo) para carregar o arquivo LISTA.TXT
  FILE* Arquivo;
 
  // Criar um endereço de memória para carregar o arquivo LISTA.TXT
  Arquivo = (FILE*) malloc(sizeof(FILE));
 
  // Carregar o arquivo LISTA.TXT somente para leitura 
  Arquivo = fopen("LISTA.txt", "r");

  char  linha[200]; // Recebe cada linha do arquivo LISTA.TXT
  char* result;

  // Testa se o arquivo LISTA.TXT foi carregado na memória com sucesso
  if ( Arquivo == NULL ) { printf("Erro ao abrir o arquivo"); };

  // Enquanto existir linhas no arquivo LISTA.TXT
  while ( !feof(Arquivo) ) {
     result = fgets(linha, 100, Arquivo);

     // Se existir linha no arquivo, for verdade, imprime na tela
     if ( result )
       printf("Linha %s \n", linha);
  }

  // Fecha o Arquivo na memória
  fclose(Arquivo);
}
