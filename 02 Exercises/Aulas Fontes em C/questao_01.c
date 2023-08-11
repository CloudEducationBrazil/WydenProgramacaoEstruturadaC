/*
	Name: Transforma Matriz em vetor
	Copyright: AREA1 | Wyden
	Author: João Elias Ferraz Santana
	Date: 16/04/20 19:38
	Description: dada uma matriz 3 x 3, transforme em um vetor. Imprima o vetor e o somatório dos elementos.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int Mat[3][3], Vct[9], soma=0, i, j;
	for(i=0;i<3; i++){
		for(j=0; j<3; j++){
			printf("Linha %d: ", i+1);
			scanf("%d", &Mat[i][j]);
			soma=soma+Mat[i][j];
		}
	}
	system("cls");
	for(i=0; i<3; i++){
		Vct[i]=Mat[0][i];
	}
	for(i=3; i<6; i++){
		Vct[i]=Mat[0][i];
	}
	for(i=6; i<9; i++){
		Vct[i]=Mat[0][i];
	}
	printf("Elementos do vetor:\n");
	for(i=0;i<9; i++){
		printf("%d ", Vct[i]);
	}
	printf("\n");
	printf("Soma dos elementos: %d\n\n", soma);
	system("pause");
	system("cls");
	return 0;
}
