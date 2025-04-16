/*
 Programa Exemplo Leitura e Gravação de .txt
 Disciplina: Linguagem de Programação
 Wyden Área 1 | UniRuy
 Professor MSc Heleno Cardoso
*/

#include <stdio.h>

int main(void){
  int v1[3];
  int v2[3];
  int v3[3];

  // Entrada no Vetor - Atribuição
  v1[0] = 11;
  v1[1] = 12;
  v1[2] = 13;

  v2[0] = 21;
  v2[1] = 22;
  v2[2] = 23;

  v3[0] = 31;
  v3[1] = 32;
  v3[2] = 33;

  // Imprimindo o Vetor Original
  for (int x=0; x < 3; x++){
    printf("Vetor [%d] = %d %d %d", x, v1[x], v2[x], v3[x]);
    printf("\n");
  }

  printf("\n");
  printf("\n");

  // Declaração da Variável Ponteiro para Arquivo
  FILE *arq;
  arq = fopen("/home/unifacsmestrado/Downloads/dados.txt", "wt");

  // Testando se Conseguiu Abrir o Arquivo
  if ( arq == NULL ) { printf("Erro ao criar o arquivo"); return 0; };

  // Geração dos Registros no Arquivo .txt
  for (int x=0 ; x<3; x++){
    fprintf(arq, "%d\t %d\t %d \n", v1[x], v2[x], v3[x]);
  }

  // Fechando o Arquivo .txt
  fclose(arq);

  // Limpando o Vetor;
  v1[0] = "";
  v1[1] = "";
  v1[2] = "";

  v2[0] = "";
  v2[1] = "";
  v2[2] = "";

  v3[0] = "";
  v3[1] = "";
  v3[2] = "";

  // Imprimindo o Vetor - Confirmando que está VAZIO
  printf("Vet1 %d %d %d", v1[0], v1[1], v1[2]);
  printf("\n");

  printf("Vet2 %d %d %d", v2[0], v2[1], v2[2]);
  printf("\n");

  printf("Vet3 %d %d %d", v3[0], v3[1], v3[2]);
  printf("\n");

  // Pausa
  getchar();

  // Abrindo o arquivo no modo leitura
  arq = fopen("/home/unifacsmestrado/Downloads/dados.txt", "rt");

  // Testando se Conseguiu Abrir o Arquivo
  if ( arq == NULL ) { printf("Erro ao abrir o arquivo"); return 0; };

  // Carregando o Arquivo no Vetor
  if ( arq == NULL ) { printf("Erro ao abrir o arquivo"); return 0; };

  int x = 0;
  while ( !feof(arq) )  {
    fscanf(arq, "%d\t %d\t %d \n", &v1[x], &v2[x], &v3[x]);
    x++;
  }

  // Fechando o Arquivo .txt
  fclose(arq);

  // Imprimindo o Vetor
  for (int x=0; x < 3; x++){
    printf("Vetor [%d] = %d %d %d", x, v1[x], v2[x], v3[x]);
    printf("\n");
  }
}
