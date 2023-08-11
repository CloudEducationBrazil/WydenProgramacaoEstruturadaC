/*
	Name: Contador de 1 até 10
	Copyright: AREA1 | Wyden
	Author: João Elias Ferraz Santana
	Date: 15/05/20 11:52
	Description: imprima os números de 1 até 10 sem utilizar
	estrutura de repetição utilizando função recursiva
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int mostarValores(int num);

int main(void){
    setlocale(LC_ALL, "Portuguese");
    printf("Mostrando números de 1 até 10\n\n");
    printf("%d ", mostarValores(1));
    printf("\n\nAcabei a contagem!");
    printf("\n\nPressione 'Enter' para sair...");
    getchar();
    return 0;
}

int mostarValores(int num){
    if(num<10){
        printf("%d\n", num);
        return mostarValores(num+1);
    }
}
