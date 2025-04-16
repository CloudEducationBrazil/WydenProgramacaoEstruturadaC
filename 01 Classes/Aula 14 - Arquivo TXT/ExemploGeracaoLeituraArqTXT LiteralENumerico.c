/*
 Programa Exemplo Leitura e Gravação de .txt
 Disciplina: Linguagem de Programação
 Wyden Área 1 | UniRuy
 Professor MSc Heleno Cardoso
 Data: 22/11/2019
*/

#include <stdio.h>

int main(void){
  int  v1[3];
  char v2[3][30];
  int  v3[3];

  // Entrada no Vetor - Atribuição
  printf("Leia Numero 1: "); scanf("%d", &v1[0]);
  printf("Leia Numero 2: "); scanf("%d", &v1[1]);
  printf("Leia Numero 3: "); scanf("%d", &v1[2]);

  //v2[0] = 21;
  //v2[1] = 22;
  //v2[2] = 23;
  setbuf(stdin, NULL);
  //fflush(stdin);

  printf("\n \n");
  printf("Leia 1o Nome: "); gets(v2[0]);
  printf("Leia 2o Nome: "); gets(v2[1]);
  printf("Leia 3o Nome: "); gets(v2[2]); // fgets(v2[2], 30, stdin)

  v3[0] = 31;
  v3[1] = 32;
  v3[2] = 33;

  printf("\n \n");

  // Imprimindo o Vetor Original
  for (int x=0; x < 3; x++){
    printf("Vetor [%d] = %d %s %d", x, v1[x], v2[x], v3[x]);
    printf("\n");
  }

  printf("\n");
  printf("\n");

  // Declaração da Variável Ponteiro para Arquivo
  FILE *arq;
  arq = fopen("dados.txt", "wt");

  // Testando se Conseguiu Abrir o Arquivo
  if ( arq == NULL ) { printf("Erro ao criar o arquivo"); return 0; };

  // Geração dos Registros no Arquivo .txt
  for (int x=0 ; x<3; x++){
    fprintf(arq, "%d\t%s\t%d\n", v1[x], v2[x], v3[x]);
  }

  // Fechando o Arquivo .txt
  fclose(arq);

  // Limpando o Vetor;
  v1[0] = "";
  v1[1] = "";
  v1[2] = "";

  strcpy(v2[0], "");
  strcpy(v2[1], "");
  strcpy(v2[2], "");

  v3[0] = "";
  v3[1] = "";
  v3[2] = "";

  // Imprimindo o Vetor - Confirmando que está VAZIO
  printf("Vet1 %d\t%d\t%d\n", v1[0], v1[1], v1[2]);
  printf("Vet2 %s\t%s\t%s\n", v2[0], v2[1], v2[2]);
  printf("Vet3 %d\t%d\t%d\n", v3[0], v3[1], v3[2]);

  // Pausa
  getchar();

  // Abrindo o arquivo no modo leitura
  arq = fopen("dados.txt", "rt");

  // Testando se Conseguiu Abrir o Arquivo
  if ( arq == NULL ) { printf("Erro ao abrir o arquivo"); return 0; };

  int x = 0;
  while ( !feof(arq) )  {
    fscanf(arq, "%d\t%[^\n]s\t%d", &v1[x], &v2[x], &v3[x]);
    x++;
  }

  // Fechando o Arquivo .txt
  fclose(arq);

  // Imprimindo o Vetor
  for (int x=0; x < 3; x++){
    printf("Vetor [%d] = %d %s %d \n", x, v1[x], v2[x], v3[x]);
    //printf("\n");
  }
}
