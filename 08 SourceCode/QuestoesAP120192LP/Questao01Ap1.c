#include <stdio.h>
#include <stdlib.h>

void fNomEleitor(int indice, char candidatoEleicao[][50]);

int main(void){
  int maxCand;
  char candidatoEleicao[maxCand][50];
  int votoEleitor = -1;
  int totCand1=0, totCand2=0, totCand3=0 ,totCand4=0 ,totNulo=0;
  float totBranco=0, totVotosEleicao=0;

  while (votoEleitor != 0){
    printf("\nDigite o Voto? "); scanf("%d", &votoEleitor);

    switch ( votoEleitor ) {
      case 1: totCand1++;  fNomEleitor(totVotosEleicao, candidatoEleicao); totVotosEleicao++; break;
      case 2: totCand2++;  fNomEleitor(totVotosEleicao, candidatoEleicao); totVotosEleicao++; break;
      case 3: totCand3++;  fNomEleitor(totVotosEleicao, candidatoEleicao); totVotosEleicao++; break;
      case 4: totCand4++;  fNomEleitor(totVotosEleicao, candidatoEleicao); totVotosEleicao++; break;
      case 5: totNulo++;   fNomEleitor(totVotosEleicao, candidatoEleicao); totVotosEleicao++; break; // Nulo
      case 6: totBranco++; fNomEleitor(totVotosEleicao, candidatoEleicao); totVotosEleicao++; break; // Branco
      default: { printf("\nVoto Inválido"); }
      }
   }
   printf("\nTotal Votos 1 = %d ", totCand1);
   printf("\nTotal Votos 2 = %d ", totCand2);
   printf("\nTotal Votos 3 = %d ", totCand3);
   printf("\nTotal Votos 4 = %d ", totCand4);
   printf("\nTotal Nulo = %d ", totNulo);
   printf("\nTotal Branco = %.2f ", totBranco);
   printf("\nTotal Votos = %.2f ", totVotosEleicao);
   printf("\nPercentual = %.2f", totBranco/totVotosEleicao);

   if ( totCand2 > 0 )
    for (int x= 0; x < totCand2; x++)
      printf("\nCanidato = [%d] = %s", x, candidatoEleicao[x]);
}

void fNomEleitor(int indice, char candidatoEleicao[][50]){
   printf("\nNome do Eleitor [%d]? ", indice); scanf("%s", &candidatoEleicao[indice]);
}
