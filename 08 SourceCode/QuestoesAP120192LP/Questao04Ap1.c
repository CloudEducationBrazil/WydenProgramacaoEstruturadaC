#include <stdlib.h>
#include <stdio.h>

#define tamGabarito 20

int main(void) {
  char vetResposta[tamGabarito];
  char vetNomAlunos[2][30];
  char vetRespostaAlunos[2][tamGabarito];
  char vetResultadoAlunos[2][1];
  float somaNotas, media;

  // Gabarito
  for (int x= 0; x<tamGabarito; x++){
    printf("Digite o Gabarito [%d]? ", x); scanf(" %c", &vetResposta[x]);
  }

  printf("\n");
  // Alunos e suas repostas
  for (int i= 0; i<2; i++){
    printf("Digite o Aluno? "); scanf("%s", &vetNomAlunos[i]);
    for (int j= 0; j<tamGabarito; j++){
        printf("Digite seu Gabarito [%d]? ", j); scanf(" %c", &vetRespostaAlunos[i][j]);
    }
  }

  printf("\n");
  // resultado dos Alunos e suas repostas
  for (int i= 0; i<2; i++ ){
    somaNotas = 0;
    for (int j= 0; j<tamGabarito; j++)
      if ( vetResposta[j] == vetRespostaAlunos[i][j] )
        somaNotas++;
    media = (somaNotas / tamGabarito) * 10;

    printf("\nSoma, %.0f", somaNotas);
    printf("\nMedia, %.2f", media);

    if ( media >= 6 )
      vetResultadoAlunos[i][0] = 'A';
    else
      vetRespostaAlunos[i][0] = 'R';
  }

  printf("\n");
  for (int i= 0; i<2; i++ ){
    printf("\nAluno %s", vetNomAlunos[i]);
    printf("\nResultado %c", vetRespostaAlunos[i][0]);
  }
}
