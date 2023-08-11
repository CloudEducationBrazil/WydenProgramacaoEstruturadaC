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
    // Tamanho da Natriz
	int Mat[3][3];
	// Tamanho do Vetor
	int Vct[9];
	
	int soma=0, i, j, x;
	
	// Entrada de Dados da Matriz - Leitura dos Elementos
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("Linha %d: ", i+1); scanf("%d", &Mat[i][j]);
		}
	}
	// Limpar a tela
	//system("cls");
	
	// Processamento
	x = 0;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
		   
		   // Atribuindo os Elementos da Matriz no Vetor
		   Vct[x] = Mat[i][j];
		   
		   // A soma dos Elementos do Vetor
		   soma = soma + Vct[x];

           // A variação do índice(coordenada) do vetor
		   x++;
		}
	}

    // Saída de Dados
	printf("Elementos do vetor:\n");
	for(x=0; x <= 8; x++){
		printf("Vetor[%d] = %d \n", x, Vct[x]);
	}
	
	printf("\n");
	
	printf("Soma dos elementos do Vetor: %d", soma);
	
	//system("pause");
	//system("cls");
	return 0;
}
