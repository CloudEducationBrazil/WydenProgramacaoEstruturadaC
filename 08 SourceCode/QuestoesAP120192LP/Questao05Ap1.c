#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int mat[5][5], somaMatColuna3 = 0, somaMatDiagonalS = 0, somaMatAbaixoDiagonalP = 0;

    for (int l = 0; l < 5; l++)
      for (int c = 0; c < 5; c++) {
        printf("Elemento [%d][%d] = ", l, c); scanf("%d", &mat[l][c]);
      }

    for (int l = 0; l < 5; l++)
      for (int c = 0; c < 5; c++){
        // Elementos da Coluna 3
        if ( c == 2 )
          somaMatColuna3 += mat[l][c];

        // Diagonal Secundária
        if ( (l + c) == 4 )
          somaMatDiagonalS += mat[l][c];

        // ELementos Abaixo da Diagonal Principal
        if ( (l + c ) < 2 * l )
          somaMatAbaixoDiagonalP += mat[l][c];
      }

    printf("\nsomaMatColuna3 = %d ", somaMatColuna3);
    printf("\nsomaMatDiagonalS = %d ", somaMatDiagonalS);
    printf("\nsomaMatAbaixoDiagonalP = %d ", somaMatAbaixoDiagonalP);

    printf("\n");
    printf("\n");

    for (int l = 0; l < 5; l++)
      for (int c = 0; c < 5; c++)
        printf("\nElemento [%d][%d] = %d ", l, c, mat[l][c]);
}
