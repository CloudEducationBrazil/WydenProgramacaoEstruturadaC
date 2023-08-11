/*
	Name: Transforma Vetor em Matriz
	Copyright: AREA1 | Wyden
	Author: João Elias Ferraz Santana
	Date: 16/04/20 20:22
	Description: dado um vetor de 9 posições, ele será transformado em uma matriz 3x3;
	o programa faz o somatório dos elementos positivos
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int Vct[9], Mat[3][3], i, j, soma=0;
	for(i=0; i<9; i++){
		printf("Entre com o valor %d: ", i+1);
		scanf("%d", &Vct[i]);
	}
	j=0;
	for(i=0; i<3; i++){
		Mat[0][j]=Vct[i];
		j=j+1;
	}
	j=0;
	for(i=3; i<6; i++){
		Mat[1][j]=Vct[i];
		j=j+1;
	}
	j=0;
	for(i=6; i<9; i++){
		Mat[2][j]=Vct[i];
		j=j+1;
	}
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(Mat[i][j]>0){
				soma=soma+Mat[i][j];
			}
		}
	}
	system("cls");
	printf("Matriz 3x3 com os valores do vetor:\n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%d ", Mat[i][j]);
		}
		printf("\n");
	}
	printf("\nSoma dos positivos: %d\n\n", soma);
	system("pause");
	system("cls");
	return 0;
}
