/*
	Name: Transforma Vetor em Matriz
	Copyright: AREA1 | Wyden
	Author: João Elias Ferraz Santana
	Date: 16/04/20 21:38
	Description: dada um vetor tamanho 9, transforme em uma matriz 3 x 3. Imprima a matriz e o somatório dos elementos.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
	// Tamanho do Vetor
	int Vct[9];

    // Tamanho da Natriz
	int Mat[3][3];
	
	int soma, i, j, x;
	
	// Entrada de Dados do Vetor - Leitura dos Elementos
	for(int x =0; x < 9; x++){
		printf("Elemento [%d] ", x); scanf("%d", &Vct[x]);
	}

	// Processamento
	x = 0; soma = 0;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
		   
		   // Atribuindo os Elementos do Vetor na Matriz
		   Mat[i][j] = Vct[x];
		   
		   // A soma dos Elementos da Matriz
		   if ( Mat[i][j] > 0 )
		     soma = soma + Mat[i][j];

           // A variação do índice(coordenada) do vetor
		   x++;
		}
	}

    // Saída de Dados
	printf("Elementos da matrix:\n");
	for(i=0; i<3; i++){
		
		for(j=0; j<3; j++)
		  printf(" %d ", Mat[i][j]);
		  
		printf("\n");
	}
	
	printf("\n");
	printf("Soma dos elementos da Matrz: %d", soma);
	
	return 0;
}
