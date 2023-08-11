/*
Name: João Marcelo Tavares
Copyright:
Author:
Date: 17/04/20 20:11
Description:
*/
//
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

int function (void);
int main (void){
setlocale(LC_ALL, "PORTUGUESE");
//Declarações
int idade, sexo, grupoderisco, infectado,qtdm,qtdf, strut;
//
printf("\n          Prefeitura de Salvador");
printf("\n      Primeira capital do brasil\n");
printf("\n     Secretaria Municipal de Saúde");
printf("\n   Numeros totais do Corona Virus em Salvador");

strut = function();

return 0;
}

int function(void){
int x,z;
int tamanho;
printf("\n\n\n\n   Registro de dados *(INDIVIDUAIS) \n  ");
printf("\n\n\n\n   Quantas pessoas infectadas temos na cidade? \n  "); scanf("%d", &z);
fflush(stdin);

struct Covid
{
int idade,citz[z];
char nome[50],sexo[50],grupo[10],infectado[10];
};
//create
for (x=0;x<z;x++){
struct Covid citz[x];
printf("Instruções gerais: Para o programa funcionar, deve-se escrever o nome completo, sexo com 'M' ou 'F', grupo de risco e se está infectado com 'S' ou 'N'' \n");
printf("Nome completo = \n");
fgets(citz[x].nome, 50, stdin);
printf("Sexo = \n");
fgets(citz[x].sexo, 50, stdin);
printf("Encontra-se no grupo de risco = \n");
fgets(citz[x].grupo, 10, stdin);
printf("Está infectado pelo (COVID-19)? = \n");
fgets(citz[x].infectado, 10, stdin);
printf("Qual sua idade? = \n");
scanf("%d", &citz[x].idade);
fflush(stdin);

tamanho = strcmp(citz[x].sexo, "F") == 0;
printf("Sexo = ", tamanho);



}// final do looping da struct citz[x]

//system("cls");
//Área de parametros de controle
printf("[Estatisticas]\n\n\n\n");
printf("Um total de pessoas infectadas [%d]", z);






return 0;
}
