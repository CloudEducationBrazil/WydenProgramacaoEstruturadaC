/*
	Name: Ordenador de Pessoas
	Copyright: AREA1 | Wyden.
	Author: João Elias Ferraz Santana
	Date: 28/05/20 20:35
	Description: Elabore um programa em linguagem C que receba 100 nomes
	(de no máximo 100 caracteres cada) e as idades das respectivas pessoas
	em um vetor de estruturas (struct). Após o recebimento, listar os 100
	nomes armazenados neste vetor por ordem crescente de idades.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAXPESS 100
#define MAX_SIZE 100

typedef struct{
	char nome[MAX_SIZE];
	int idade;
}Pessoa;

int main(void){
	setlocale(LC_ALL, "Portuguese");
	Pessoa lista[MAX_SIZE];
	int i, j, k, aux, aux1;
	char nomeAUX[MAX_SIZE];
	for(i=0;i<MAXPESS; i++){
		fflush(stdin);
		printf("Seu nome: ");
		gets(lista[i].nome);
		fflush(stdin);
		printf("Sua idade: ");
		scanf("%d", &lista[i].idade);
		system("cls");
	}

	aux1=1;
	while(aux1 == 1){
		aux1=0;
		for(i=0; i < MAXPESS; i++){
			if(lista[i].idade > lista[i+1].idade){
				aux=lista[i+1].idade;

				strcpy(nomeAUX, lista[i].nome);

				lista[i+1].idade = lista[i].idade;
				strcpy(lista[i+1].nome, lista[i].nome);

				lista[i].idade = aux;
				strcpy(lista[i].nome, nomeAUX);

				aux1=1;
			}
		}
	}
	printf("ORDEM CRESCENTE:\n\n");
	for(i=0; i<MAXPESS; i++){
		printf("Nome: ");
		for(j=0; j<strlen(lista[i].nome); j++){
			printf("%c", lista[i].nome[j]);
		}
		printf("\nIdade: %d\n", lista[i].idade);
	}
	system("pause");
	return 0;
}
